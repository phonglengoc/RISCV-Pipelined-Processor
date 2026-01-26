`timescale 1ns / 1ns

`define REG_SIZE 31
`define INST_SIZE 31
`define OPCODE_SIZE 6

`ifndef DIVIDER_STAGES
`define DIVIDER_STAGES 8
`endif

`include "cla.v"
`include "DividerUnsignedPipelined.v"

module RegFile (
  input      [        4:0] rd,
  input      [`REG_SIZE:0] rd_data,
  input      [        4:0] rs1,
  output reg [`REG_SIZE:0] rs1_data,
  input      [        4:0] rs2,
  output reg [`REG_SIZE:0] rs2_data,
  input                    clk,
  input                    we,
  input                    rst
);
  localparam NumRegs = 32;
  reg [`REG_SIZE:0] regs[0:NumRegs-1];
  integer i;

  always @(posedge clk) begin
    if (rst) begin
      for (i = 0; i < NumRegs; i = i + 1) begin
        regs[i] <= 32'd0;
      end
    end else if (we && rd != 5'd0) begin
      regs[rd] <= rd_data;
    end
  end

  always @(*) begin
    rs1_data = (rs1 == 5'd0) ? 32'd0 : regs[rs1];
    rs2_data = (rs2 == 5'd0) ? 32'd0 : regs[rs2];
  end
endmodule

module DatapathPipelined (
  input                     clk,
  input                     rst,
  input      [(8*32)-1:0]   test_case,
  output     [ `REG_SIZE:0] pc_to_imem,
  input      [`INST_SIZE:0] inst_from_imem,
  
  // Đã sửa: Xóa 'reg' vì các tín hiệu này được lái bằng assign
  output     [ `REG_SIZE:0] addr_to_dmem,
  input      [ `REG_SIZE:0] load_data_from_dmem,
  output     [ `REG_SIZE:0] store_data_to_dmem,
  output     [         3:0] store_we_to_dmem,
  
  output reg                halt, // Giữ reg nếu dùng trong always
  output     [ `REG_SIZE:0] trace_writeback_pc,
  output     [`INST_SIZE:0] trace_writeback_inst
);
  // --- Opcodes ---
  localparam [`OPCODE_SIZE:0] OpcodeLoad    = 7'b00_000_11;
  localparam [`OPCODE_SIZE:0] OpcodeStore   = 7'b01_000_11;
  localparam [`OPCODE_SIZE:0] OpcodeBranch  = 7'b11_000_11;
  localparam [`OPCODE_SIZE:0] OpcodeJalr    = 7'b11_001_11;
  // localparam [`OPCODE_SIZE:0] OpcodeMiscMem = 7'b00_011_11;
  localparam [`OPCODE_SIZE:0] OpcodeJal     = 7'b11_011_11;
  localparam [`OPCODE_SIZE:0] OpcodeRegImm  = 7'b00_100_11;
  localparam [`OPCODE_SIZE:0] OpcodeRegReg  = 7'b01_100_11;
  localparam [`OPCODE_SIZE:0] OpcodeEnviron = 7'b11_100_11;
  localparam [`OPCODE_SIZE:0] OpcodeAuipc   = 7'b00_101_11;
  localparam [`OPCODE_SIZE:0] OpcodeLui     = 7'b01_101_11;

  // --- Divider Pipeline Declarations (Moved to Top) ---
  localparam DIV_STAGES = `DIVIDER_STAGES;
  reg [DIV_STAGES-1:0] div_valid;
  reg [4:0]  div_rd_pipe   [0:DIV_STAGES-1];
  reg        div_is_rem    [0:DIV_STAGES-1];
  reg        div_is_signed [0:DIV_STAGES-1];
  reg [31:0] div_pc_pipe   [0:DIV_STAGES-1];
  reg [31:0] div_inst_pipe [0:DIV_STAGES-1];
  reg        div_sign_a    [0:DIV_STAGES-1];
  reg        div_sign_b    [0:DIV_STAGES-1];
  reg [31:0] div_src_a     [0:DIV_STAGES-1];
  reg [31:0] div_src_b     [0:DIV_STAGES-1];
  reg        div_div_zero  [0:DIV_STAGES-1];
  
  // Execution operands declared here to avoid scope errors
  reg [31:0] x_op_a;
  reg [31:0] x_op_b;
  
  // Cycle counter
  reg [`REG_SIZE:0] cycles_current;
  always @(posedge clk) begin
    if (rst) cycles_current <= 0;
    else cycles_current <= cycles_current + 1;
  end

  /***************/
  /* FETCH STAGE */
  /***************/
  reg  [`REG_SIZE:0] f_pc_current;
  wire [`REG_SIZE:0] f_inst;
  reg  [`REG_SIZE:0] f_pc_next;

  always @(posedge clk) begin
    if (rst) f_pc_current <= 32'd0;
    else f_pc_current <= f_pc_next;
  end
  assign pc_to_imem = f_pc_current;
  assign f_inst = inst_from_imem;

  /****************/
  /* DECODE STAGE */
  /****************/
  reg        d_valid;
  reg [31:0] d_pc;
  reg [31:0] d_inst;
  reg [4:0]  d_rs1, d_rs2, d_rd;
  reg [2:0]  d_funct3;
  reg [6:0]  d_funct7;
  reg [6:0]  d_opcode;

  reg        x_valid;
  reg [31:0] x_pc;
  reg [31:0] x_inst;
  reg [4:0]  x_rd;
  reg [2:0]  x_funct3;
  reg [6:0]  x_funct7;
  reg [6:0]  x_opcode;
  reg [31:0] x_rs1_val, x_rs2_val;
  reg [31:0] x_imm_i, x_imm_s, x_imm_b, x_imm_j;
  reg [31:0] x_store_val; 
  reg        x_is_load, x_is_store, x_is_branch, x_is_jal, x_is_jalr;
  reg        x_is_lui, x_is_auipc, x_is_alu_imm, x_is_alu_reg;
  reg        x_is_mul, x_is_div;
  reg        x_is_ecall;
  
  reg        m_valid;
  reg [31:0] m_pc;
  reg [31:0] m_inst;
  reg [4:0]  m_rd;
  reg [2:0]  m_funct3;
  reg        m_is_load, m_is_store;
  reg        m_reg_we;
  reg [31:0] m_alu_res;
  reg [31:0] m_store_val;
  reg        m_is_ecall;

  reg        w_valid;
  reg [31:0] w_pc;
  reg [31:0] w_inst;
  reg [4:0]  w_rd;
  reg        w_reg_we;
  reg [31:0] w_wb_data;
  reg        w_is_ecall;
  
  wire        rf_we;
  wire [4:0]  rf_rd;
  wire [31:0] rf_wdata;
  wire [31:0] rs1_data_raw, rs2_data_raw;
  
  RegFile rf (
    .rd      (rf_rd),
    .rd_data (rf_wdata),
    .rs1     (d_inst[19:15]),
    .rs1_data(rs1_data_raw),
    .rs2     (d_inst[24:20]),
    .rs2_data(rs2_data_raw),
    .clk     (clk),
    .we      (rf_we),
    .rst     (rst)
  );

  wire [31:0] d_imm_i = {{20{d_inst[31]}}, d_inst[31:20]};
  wire [31:0] d_imm_s = {{20{d_inst[31]}}, d_inst[31:25], d_inst[11:7]};
  wire [31:0] d_imm_b = {{19{d_inst[31]}}, d_inst[31], d_inst[7], d_inst[30:25], d_inst[11:8], 1'b0};
  wire [31:0] d_imm_j = {{11{d_inst[31]}}, d_inst[31], d_inst[19:12], d_inst[20], d_inst[30:21], 1'b0};
  
  reg stall_pipe;
  reg flush_pipe;
  wire stall_all = stall_pipe;

  wire [31:0] fwd_div_data;
  wire        fwd_div_valid;
  wire [4:0]  fwd_div_rd;

  // WD bypass (Writeback to Decode read)
  wire [31:0] d_rs1_val = (rf_we && (rf_rd == d_inst[19:15]) && (d_inst[19:15] != 0)) ? rf_wdata : rs1_data_raw;
  wire [31:0] d_rs2_val = (rf_we && (rf_rd == d_inst[24:20]) && (d_inst[24:20] != 0)) ? rf_wdata : rs2_data_raw;
  
  always @(posedge clk) begin
    if (rst) begin
      d_valid <= 1'b0;
      d_pc <= 0; d_inst <= 0; d_rs1 <= 0; d_rs2 <= 0; d_rd <= 0; d_funct3 <= 0;
      d_funct7 <= 0; d_opcode <= 0;
      
      x_valid <= 1'b0; x_pc <= 0; x_inst <= 0; x_rd <= 0;
      x_funct3 <= 0; x_funct7 <= 0; x_opcode <= 0; x_rs1_val <= 0; x_rs2_val <= 0; x_imm_i <= 0;
      x_imm_s <= 0; x_imm_b <= 0; x_imm_j <= 0;
      x_is_load <= 0; x_is_store <= 0; x_is_branch <= 0;
      x_is_jal <= 0; x_is_jalr <= 0; x_is_lui <= 0; x_is_auipc <= 0; x_is_alu_imm <= 0; x_is_alu_reg <= 0;
      x_is_mul <= 0; x_is_div <= 0; x_is_ecall <= 0;
      
      m_valid <= 1'b0; m_pc <= 0; m_inst <= 0;
      m_rd <= 0; m_funct3 <= 0; m_is_load <= 0; m_is_store <= 0; m_reg_we <= 0; m_alu_res <= 0;
      m_store_val <= 0; m_is_ecall <= 0;

      w_valid <= 1'b0; w_pc <= 0; w_inst <= 0; w_rd <= 0;
      w_reg_we <= 0; w_wb_data <= 0; w_is_ecall <= 0;

    end else begin
      if (!stall_all) begin
        d_valid <= 1'b1;
        d_pc    <= f_pc_current;
        d_inst  <= flush_pipe ? 32'd0 : f_inst;
        d_rs1   <= flush_pipe ? 5'd0 : f_inst[19:15];
        d_rs2   <= flush_pipe ? 5'd0 : f_inst[24:20];
        d_rd    <= flush_pipe ? 5'd0 : f_inst[11:7];
        d_funct3<= flush_pipe ? 3'd0 : f_inst[14:12];
        d_funct7<= flush_pipe ? 7'd0 : f_inst[31:25];
        d_opcode<= flush_pipe ? 7'd0 : f_inst[6:0];
      end else begin
        d_valid <= d_valid;
        d_pc    <= d_pc;
        d_inst  <= d_inst;
        d_rs1   <= d_rs1;
        d_rs2   <= d_rs2;
        d_rd    <= d_rd;
        d_funct3<= d_funct3;
        d_funct7<= d_funct7;
        d_opcode<= d_opcode;
      end

      if (stall_all) begin
        x_valid   <= 1'b0;
      end else begin
        x_valid   <= d_valid && !flush_pipe;
        x_pc      <= d_pc;
        x_inst    <= d_inst;
        x_rd      <= d_rd;
        x_funct3  <= d_funct3;
        x_funct7  <= d_funct7;
        x_opcode  <= d_opcode;
        x_rs1_val <= d_rs1_val;
        x_rs2_val <= d_rs2_val;
        x_imm_i   <= d_imm_i;
        x_imm_s   <= d_imm_s;
        x_imm_b   <= d_imm_b;
        x_imm_j   <= d_imm_j;
        
        x_is_load    <= (d_opcode == OpcodeLoad);
        x_is_store   <= (d_opcode == OpcodeStore);
        x_is_branch  <= (d_opcode == OpcodeBranch);
        x_is_jal     <= (d_opcode == OpcodeJal);
        x_is_jalr    <= (d_opcode == OpcodeJalr);
        x_is_lui     <= (d_opcode == OpcodeLui);
        x_is_auipc   <= (d_opcode == OpcodeAuipc);
        x_is_alu_imm <= (d_opcode == OpcodeRegImm);
        x_is_alu_reg <= (d_opcode == OpcodeRegReg);
        x_is_mul     <= (d_opcode == OpcodeRegReg) && (d_funct7 == 7'd1) && (d_funct3[2:0] <= 3'b011);
        x_is_div     <= (d_opcode == OpcodeRegReg) && (d_funct7 == 7'd1) && (d_funct3[2:0] >= 3'b100);
        x_is_ecall   <= (d_opcode == OpcodeEnviron) && (d_inst[31:7] == 25'd0);
      end

      m_valid    <= x_valid;
      m_pc       <= x_pc;
      m_inst     <= x_inst;
      m_rd       <= x_rd;
      m_funct3   <= x_funct3;
      m_is_load  <= x_is_load;
      m_is_store <= x_is_store;
      m_reg_we   <= m_reg_we_next;
      m_alu_res  <= x_alu_res;
      m_store_val<= x_store_val;
      m_is_ecall <= x_is_ecall;

      w_valid   <= m_valid;
      w_pc      <= m_pc;
      w_inst    <= m_inst;
      w_rd      <= m_rd;
      w_reg_we  <= w_reg_we_next;
      w_wb_data <= w_wb_data_next;
      w_is_ecall <= m_is_ecall;
    end
  end

  /****************************/
  /* EXECUTE / MEMORY LOGIC   */
  /****************************/
  wire [31:0] w_main_data = w_wb_data;
  wire        w_main_we   = w_reg_we;
  wire [4:0]  x_rs1_idx   = x_inst[19:15];
  wire [4:0]  x_rs2_idx   = x_inst[24:20];

  always @(*) begin
    // Default values
    x_op_a = x_rs1_val;
    x_op_b = x_rs2_val;
    // Forwarding for rs1
    if (fwd_div_valid && (fwd_div_rd == x_rs1_idx) && (fwd_div_rd != 0)) begin
      x_op_a = fwd_div_data;
    end 
    else if (m_valid && m_reg_we && !m_is_load && (m_rd == x_rs1_idx) && (m_rd != 0)) begin
      x_op_a = m_alu_res;
    end 
    else if (w_main_we && (w_rd == x_rs1_idx) && (w_rd != 0)) begin
      x_op_a = w_main_data;
    end

    // Forwarding for rs2
    if (fwd_div_valid && (fwd_div_rd == x_rs2_idx) && (fwd_div_rd != 0)) begin
      x_op_b = fwd_div_data;
    end 
    else if (m_valid && m_reg_we && !m_is_load && (m_rd == x_rs2_idx) && (m_rd != 0)) begin
      x_op_b = m_alu_res;
    end 
    else if (w_main_we && (w_rd == x_rs2_idx) && (w_rd != 0)) begin
      x_op_b = w_main_data;
    end
  end

  always @(*) begin
    x_store_val = x_op_b;
    if (fwd_div_valid && (fwd_div_rd == x_rs2_idx) && (fwd_div_rd != 0)) begin
      x_store_val = fwd_div_data;
    end
    else if (m_valid && m_is_load && (m_rd == x_rs2_idx) && (m_rd != 0)) begin
      if (w_main_we && (w_rd == x_rs2_idx) && (w_rd != 0)) begin
        x_store_val = w_main_data;
      end
    end
  end

  // Load-use hazard detection
  wire load_use_hazard = x_valid && x_is_load && (x_rd != 0) &&
                         ((x_rd == d_inst[19:15]) || (x_rd == d_inst[24:20]));

  // Divider dependency hazard
  function div_hazard_match;
    input [4:0] rs;
    integer k;
    begin
      div_hazard_match = 1'b0;
      // FIX: Only loop until DIV_STAGES-2.
      for (k = 0; k < DIV_STAGES - 2; k = k + 1) begin
        if (div_valid[k] && (div_rd_pipe[k] == rs) && (rs != 0)) begin
          div_hazard_match = 1'b1;
        end
      end
    end
  endfunction

  wire div_dep_hazard_rs1 = div_hazard_match(d_inst[19:15]);
  wire div_dep_hazard_rs2 = div_hazard_match(d_inst[24:20]);
  wire div_dep_hazard = d_valid && (div_dep_hazard_rs1 || div_dep_hazard_rs2);
  wire div_dep_hazard_xstage = x_valid && x_is_div && (x_rd != 0) &&
                               ((x_rd == d_inst[19:15]) || (x_rd == d_inst[24:20]));
  
  // Block non-divider instructions while any divider is in-flight
  // FIX: Exclude the last stage from 'busy' check to allow pipelining flow
  wire div_pipeline_busy = |div_valid[DIV_STAGES-3:0];
  wire d_is_div = (d_opcode == OpcodeRegReg) && (d_funct7 == 7'd1) && (d_funct3[2:0] >= 3'b100);
  wire stall_div_block = (div_pipeline_busy || (x_valid && x_is_div)) && !d_is_div;
  
  always @(*) begin
    stall_pipe = load_use_hazard || div_dep_hazard || div_dep_hazard_xstage || stall_div_block; 
  end

  wire stall_divider = 1'b0;

  // Branch/jump resolution
  reg branch_taken;
  reg [31:0] branch_target;
  always @(*) begin
    branch_taken  = 1'b0;
    branch_target = f_pc_current + 4;
    flush_pipe    = 1'b0;
    f_pc_next     = f_pc_current + 4;
    if (x_valid) begin
      case (1'b1)
        x_is_jal: begin
          branch_taken  = 1'b1;
          branch_target = x_pc + x_imm_j;
        end
        x_is_jalr: begin
          branch_taken  = 1'b1;
          branch_target = (x_op_a + x_imm_i) & ~32'd1;
        end
        x_is_branch: begin
          case (x_funct3)
            3'b000: branch_taken = (x_op_a == x_op_b);
            3'b001: branch_taken = (x_op_a != x_op_b);
            3'b100: branch_taken = ($signed(x_op_a) < $signed(x_op_b));
            3'b101: branch_taken = ($signed(x_op_a) >= $signed(x_op_b));
            3'b110: branch_taken = (x_op_a < x_op_b);
            3'b111: branch_taken = (x_op_a >= x_op_b);
            default: branch_taken = 1'b0;
          endcase
          branch_target = x_pc + x_imm_b;
        end
        default: begin end
      endcase
    end

    if (branch_taken) begin
      f_pc_next  = branch_target;
      flush_pipe = 1'b1;
    end else if (stall_all) begin
      f_pc_next  = f_pc_current;
    end
  end

  // ALU and store address generation
  reg [31:0] x_alu_res;
  reg [64:0] mul_temp_65;
  reg        m_reg_we_next;
  always @(*) begin
    x_alu_res     = 32'd0;
    m_reg_we_next = 1'b0;
    mul_temp_65   = 65'd0;

    if (x_valid) begin
      if (x_is_lui) begin
        x_alu_res     = {x_inst[31:12], 12'd0};
        m_reg_we_next = 1'b1;
      end else if (x_is_auipc) begin
        x_alu_res     = x_pc + {x_inst[31:12], 12'd0};
        m_reg_we_next = 1'b1;
      end else if (x_is_jal || x_is_jalr) begin
        x_alu_res     = x_pc + 4;
        m_reg_we_next = 1'b1;
      end else if (x_is_alu_imm) begin
        case (x_funct3)
          3'b000: x_alu_res = x_op_a + x_imm_i;
          3'b010: x_alu_res = ($signed(x_op_a) < $signed(x_imm_i)) ? 1 : 0;
          3'b011: x_alu_res = (x_op_a < x_imm_i) ? 1 : 0;
          3'b100: x_alu_res = x_op_a ^ x_imm_i;
          3'b110: x_alu_res = x_op_a | x_imm_i;
          3'b111: x_alu_res = x_op_a & x_imm_i;
          3'b001: x_alu_res = x_op_a << x_imm_i[4:0];
          3'b101: begin
            if (x_funct7 == 7'b0100000) begin
              x_alu_res = $signed(x_op_a) >>> x_imm_i[4:0];
            end else begin
              x_alu_res = x_op_a >> x_imm_i[4:0];
            end
          end
          default: x_alu_res = 32'd0;
        endcase
        m_reg_we_next = 1'b1;
      end else if (x_is_alu_reg && !x_is_mul && !x_is_div) begin
        case (x_funct3)
          3'b000: x_alu_res = (x_funct7 == 7'b0100000) ? (x_op_a - x_op_b) : (x_op_a + x_op_b);
          3'b001: x_alu_res = x_op_a << x_op_b[4:0];
          3'b010: x_alu_res = ($signed(x_op_a) < $signed(x_op_b)) ? 1 : 0;
          3'b011: x_alu_res = (x_op_a < x_op_b) ? 1 : 0;
          3'b100: x_alu_res = x_op_a ^ x_op_b;
          3'b101: begin
            if (x_funct7 == 7'b0100000) begin
              x_alu_res = $signed(x_op_a) >>> x_op_b[4:0];
            end else begin
              x_alu_res = x_op_a >> x_op_b[4:0];
            end
          end
          3'b110: x_alu_res = x_op_a | x_op_b;
          3'b111: x_alu_res = x_op_a & x_op_b;
          default: x_alu_res = 32'd0;
        endcase
        m_reg_we_next = 1'b1;
      end else if (x_is_mul) begin
        case (x_funct3)
          3'b000: x_alu_res = (x_op_a * x_op_b);
          3'b001: begin
             mul_temp_65 = $signed(x_op_a) * $signed(x_op_b);
             x_alu_res = mul_temp_65[63:32];
          end
          3'b010: begin
             mul_temp_65 = $signed(x_op_a) * $signed({1'b0, x_op_b});
             x_alu_res = mul_temp_65[63:32];
          end
          3'b011: begin
             mul_temp_65 = x_op_a * x_op_b;
             x_alu_res = mul_temp_65[63:32];
          end
          default: x_alu_res = 32'd0;
        endcase
        m_reg_we_next = 1'b1;
      end else if (x_is_load) begin
        x_alu_res     = x_op_a + x_imm_i;
        m_reg_we_next = 1'b1;
      end else if (x_is_store) begin
        x_alu_res     = x_op_a + x_imm_s;
        m_reg_we_next = 1'b0;
      end else if (x_is_div) begin
        x_alu_res     = 32'd0;
        m_reg_we_next = 1'b0;
      end
    end
  end

  /********************/
  /* MEMORY STAGE     */
  /********************/
  reg [3:0] m_store_we;
  reg [31:0] m_store_data_aligned;
  reg [31:0] m_addr;

  always @(*) begin
    m_addr              = m_alu_res;
    m_store_we          = 4'b0000;
    m_store_data_aligned= m_store_val;
    if (m_valid && m_is_store) begin
      case (m_funct3)
        3'b000: begin // sb
          m_store_we = 4'b0001 << m_addr[1:0];
          m_store_data_aligned = m_store_val << (8 * m_addr[1:0]);
        end
        3'b001: begin // sh
          m_store_we = (m_addr[1]) ? 4'b1100 : 4'b0011;
          m_store_data_aligned = m_store_val << (8 * m_addr[1:0]);
        end
        3'b010: begin // sw
          m_store_we = 4'b1111;
          m_store_data_aligned = m_store_val;
        end
        default: m_store_we = 4'b0000;
      endcase
    end
  end

  assign addr_to_dmem        = m_addr;
  assign store_data_to_dmem  = m_store_data_aligned;
  assign store_we_to_dmem    = m_store_we;

  reg [31:0] load_wb_value;
  always @(*) begin
    load_wb_value = load_data_from_dmem;
    if (m_valid && m_is_load) begin
      case (m_funct3)
        3'b000: load_wb_value = {{24{load_data_from_dmem[7 + 8*m_addr[1:0]]}}, load_data_from_dmem[8*m_addr[1:0]+:8]};
        3'b001: load_wb_value = {{16{load_data_from_dmem[15 + 8*m_addr[1:0]]}}, load_data_from_dmem[8*m_addr[1:0]+:16]};
        3'b010: load_wb_value = load_data_from_dmem;
        3'b100: load_wb_value = {24'd0, load_data_from_dmem[8*m_addr[1:0]+:8]};
        3'b101: load_wb_value = {16'd0, load_data_from_dmem[8*m_addr[1:0]+:16]};
        default: load_wb_value = load_data_from_dmem;
      endcase
    end
  end

  reg [31:0] w_wb_data_next;
  reg        w_reg_we_next;
  always @(*) begin
    w_wb_data_next = m_is_load ? load_wb_value : m_alu_res;
    w_reg_we_next  = m_valid && m_reg_we && (m_rd != 0) && !m_is_store && !m_is_load ? 1'b1 : 1'b0;
    if (m_valid && m_is_load && (m_rd != 0)) begin
      w_reg_we_next = 1'b1;
    end
  end

  /********************/
  /* DIVIDER PIPELINE */
  /********************/
  wire        div_is_signed_now = x_valid && x_is_div && (x_funct3[0] == 1'b0);
  wire [31:0] div_in_a_abs = (div_is_signed_now && x_op_a[31]) ? (~x_op_a + 1) : x_op_a;
  wire [31:0] div_in_b_abs = (div_is_signed_now && x_op_b[31]) ? (~x_op_b + 1) : x_op_b;

  wire [31:0] div_quotient_u;
  wire [31:0] div_remainder_u;
  DividerUnsignedPipelined u_divider (
    .clk(clk),
    .rst(rst),
    .stall(stall_divider),
    .i_dividend(div_in_a_abs),
    .i_divisor(div_in_b_abs),
    .o_remainder(div_remainder_u),
    .o_quotient(div_quotient_u)
  );
  integer div_i;
  always @(posedge clk) begin
    if (rst) begin
      div_valid <= {DIV_STAGES{1'b0}};
      for (div_i = 0; div_i < DIV_STAGES; div_i = div_i + 1) begin
        div_rd_pipe[div_i]    <= 0;
        div_is_rem[div_i]     <= 0;
        div_is_signed[div_i]  <= 0;
        div_pc_pipe[div_i]    <= 0;
        div_inst_pipe[div_i]  <= 0;
        div_sign_a[div_i]      <= 0;
        div_sign_b[div_i]      <= 0;
        div_src_a[div_i]       <= 0;
        div_src_b[div_i]       <= 0;
        div_div_zero[div_i]    <= 0;
      end
    end else begin
      // Shift pipeline
      for (div_i = DIV_STAGES-1; div_i > 0; div_i = div_i - 1) begin
        div_valid[div_i]       <= div_valid[div_i-1];
        div_rd_pipe[div_i]     <= div_rd_pipe[div_i-1];
        div_is_rem[div_i]      <= div_is_rem[div_i-1];
        div_is_signed[div_i]   <= div_is_signed[div_i-1];
        div_pc_pipe[div_i]     <= div_pc_pipe[div_i-1];
        div_inst_pipe[div_i]   <= div_inst_pipe[div_i-1];
        div_sign_a[div_i]      <= div_sign_a[div_i-1];
        div_sign_b[div_i]      <= div_sign_b[div_i-1];
        div_src_a[div_i]       <= div_src_a[div_i-1];
        div_src_b[div_i]       <= div_src_b[div_i-1];
        div_div_zero[div_i]    <= div_div_zero[div_i-1];
      end

      // Insert new divider operation
      if (x_valid && x_is_div) begin
        div_valid[0]      <= 1'b1;
        div_rd_pipe[0]    <= x_rd;
        div_is_rem[0]     <= (x_funct3[1:0] == 2'b10) || (x_funct3[1:0] == 2'b11);
        div_is_signed[0]  <= (x_funct3[0] == 1'b0); 
        div_pc_pipe[0]    <= x_pc;
        div_inst_pipe[0]  <= x_inst;
        div_sign_a[0]     <= x_op_a[31];
        div_sign_b[0]     <= x_op_b[31];
        div_src_a[0]      <= x_op_a;
        div_src_b[0]      <= x_op_b;
        div_div_zero[0]   <= (x_op_b == 0);
      end else begin
        div_valid[0]      <= 1'b0;
        div_rd_pipe[0]    <= 0;
        div_is_rem[0]     <= 1'b0;
        div_is_signed[0]  <= 1'b0;
        div_pc_pipe[0]    <= 0;
        div_inst_pipe[0]  <= 0;
        div_sign_a[0]     <= 0;
        div_sign_b[0]     <= 0;
        div_src_a[0]      <= 0;
        div_src_b[0]      <= 0;
        div_div_zero[0]   <= 0;
      end
    end
  end

  wire        div_ready_valid = div_valid[DIV_STAGES-1];
  wire [4:0]  div_ready_rd    = div_rd_pipe[DIV_STAGES-1];
  wire        div_ready_is_rem= div_is_rem[DIV_STAGES-1];
  wire        div_ready_signed= div_is_signed[DIV_STAGES-1];
  wire [31:0] div_ready_pc    = div_pc_pipe[DIV_STAGES-1];
  wire [31:0] div_ready_inst  = div_inst_pipe[DIV_STAGES-1];
  wire [31:0] div_ready_src_a = div_src_a[DIV_STAGES-1];
  wire [31:0] div_ready_src_b = div_src_b[DIV_STAGES-1];
  wire        div_ready_div0  = div_div_zero[DIV_STAGES-1];

  wire sign_a_last = div_sign_a[DIV_STAGES-1];
  wire sign_b_last = div_sign_b[DIV_STAGES-1];
  wire [31:0] div_quo_signed = (div_ready_signed && (sign_a_last ^ sign_b_last)) ? (~div_quotient_u + 1) : div_quotient_u;
  wire [31:0] div_rem_signed = (div_ready_signed && sign_a_last) ? (~div_remainder_u + 1) : div_remainder_u;
  wire        div_overflow   = div_ready_signed && 
                               (div_ready_src_a == 32'h8000_0000) && 
                               (div_ready_src_b == 32'hFFFF_FFFF);
  reg [31:0] div_result_final;
  always @(*) begin
    if (div_ready_div0) begin
      div_result_final = div_ready_is_rem ? div_ready_src_a : 32'hFFFF_FFFF;
    end else if (div_overflow) begin
      div_result_final = div_ready_is_rem ? 32'd0 : div_ready_src_a;
    end else begin
      if (div_ready_is_rem) begin
        div_result_final = div_ready_signed ? div_rem_signed : div_remainder_u;
      end else begin
        div_result_final = div_ready_signed ? div_quo_signed : div_quotient_u;
      end
    end
  end

  assign fwd_div_valid = div_ready_valid;
  assign fwd_div_rd    = div_ready_rd;
  assign fwd_div_data  = div_result_final;

  /********************/
  /* TRACE / HALT     */
  /********************/
  always @(*) begin
    halt = 1'b0;
    if (w_valid && w_is_ecall) begin
      halt = 1'b1;
    end
  end

  assign rf_we    = div_ready_valid ? (div_ready_rd != 0) : (w_valid && w_reg_we && (w_rd != 0));
  assign rf_rd    = div_ready_valid ? div_ready_rd        : w_rd;
  assign rf_wdata = div_ready_valid ? fwd_div_data        : w_wb_data;

  assign trace_writeback_pc   = div_ready_valid ? div_ready_pc   : (w_valid && w_reg_we ? w_pc   : 32'd0);
  assign trace_writeback_inst = div_ready_valid ? div_ready_inst : (w_valid && w_reg_we ? w_inst : 32'd0);

endmodule

module MemorySingleCycle #(
    parameter NUM_WORDS = 512
) (
    input                    rst,
    input                    clk,
    input      [`REG_SIZE:0] pc_to_imem,
    output reg [`REG_SIZE:0] inst_from_imem,
    input      [`REG_SIZE:0] addr_to_dmem,
    
    output reg [`REG_SIZE:0] load_data_from_dmem,
    input      [`REG_SIZE:0] store_data_to_dmem,
    input      [        3:0] store_we_to_dmem
);
  reg [`REG_SIZE:0] mem_array[0:NUM_WORDS-1];
  integer j;

  initial begin
    for (j = 0; j < NUM_WORDS; j = j + 1) begin
      mem_array[j] = 32'd0;
    end
    $readmemh("D:/SoC_lab/assignment/mem_initial_contents.hex", mem_array);
  end

  localparam AddrMsb = $clog2(NUM_WORDS) + 1;
  localparam AddrLsb = 2;
  
  always @(negedge clk) begin
    inst_from_imem <= mem_array[{pc_to_imem[AddrMsb:AddrLsb]}];
  end

  always @(negedge clk) begin
    if (store_we_to_dmem[0]) mem_array[addr_to_dmem[AddrMsb:AddrLsb]][7:0] <= store_data_to_dmem[7:0];
    if (store_we_to_dmem[1]) mem_array[addr_to_dmem[AddrMsb:AddrLsb]][15:8] <= store_data_to_dmem[15:8];
    if (store_we_to_dmem[2]) mem_array[addr_to_dmem[AddrMsb:AddrLsb]][23:16] <= store_data_to_dmem[23:16];
    if (store_we_to_dmem[3]) mem_array[addr_to_dmem[AddrMsb:AddrLsb]][31:24] <= store_data_to_dmem[31:24];
    load_data_from_dmem <= mem_array[{addr_to_dmem[AddrMsb:AddrLsb]}];
  end
endmodule

module Processor (
    input                 clk,
    input                 rst,
    input  [(8*32)-1:0]   test_case,
    output                halt,
    output [ `REG_SIZE:0] trace_writeback_pc,
    output [`INST_SIZE:0] trace_writeback_inst
);
  wire [`INST_SIZE:0] inst_from_imem;
  wire [ `REG_SIZE:0] pc_to_imem, mem_data_addr, mem_data_loaded_value, mem_data_to_write;
  wire [         3:0] mem_data_we;
 
  MemorySingleCycle #(
      .NUM_WORDS(8192)
  ) memory (
    .rst                 (rst),
    .clk                 (clk),
    .pc_to_imem          (pc_to_imem),
    .inst_from_imem      (inst_from_imem),
    .addr_to_dmem        (mem_data_addr),
    .load_data_from_dmem (mem_data_loaded_value),
    .store_data_to_dmem  (mem_data_to_write),
    .store_we_to_dmem    (mem_data_we)
  );

  DatapathPipelined datapath (
    .clk                  (clk),
    .rst                  (rst),
    .test_case            (test_case),
    .pc_to_imem           (pc_to_imem),
    .inst_from_imem       (inst_from_imem),
    .addr_to_dmem         (mem_data_addr),
    .store_data_to_dmem   (mem_data_to_write),
    .store_we_to_dmem     (mem_data_we),
    .load_data_from_dmem  (mem_data_loaded_value),
    .halt                 (halt),
    .trace_writeback_pc   (trace_writeback_pc),
    .trace_writeback_inst (trace_writeback_inst)
  );
endmodule