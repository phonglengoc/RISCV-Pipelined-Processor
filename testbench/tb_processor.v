`timescale 1ns / 1ps

module tb_processor;

  // ===========================================================================
  // 1. SIGNAL DECLARATION
  // ===========================================================================
  reg clk;
  reg rst;
  reg [(8*32)-1:0] test_case; // Tên test case

  wire halt;
  wire [31:0] trace_writeback_pc;
  wire [31:0] trace_writeback_inst;

  // ===========================================================================
  // 2. CLOCK GENERATION (100MHz - 10ns period)
  // ===========================================================================
  initial begin
    clk = 0;
    forever #5 clk = ~clk; 
  end

  // ===========================================================================
  // 3. DUT INSTANTIATION
  // ===========================================================================
  Processor u_processor (
    .clk                  (clk),
    .rst                  (rst),
    .test_case            (test_case),
    .halt                 (halt),
    .trace_writeback_pc   (trace_writeback_pc),
    .trace_writeback_inst (trace_writeback_inst)
  );

  // ===========================================================================
  // 4. SPYING SIGNALS (VŨ KHÍ TỐI THƯỢNG CỦA MIT)
  // Sử dụng Hierarchical Reference (u_processor.datapath.signal_name)
  // ===========================================================================

  // --- GROUP 1: PIPELINE FLOW (Xem lệnh trôi qua các tầng) ---
  wire [31:0] SPY_PC_Fetch   = u_processor.datapath.f_pc_current;
  wire [31:0] SPY_PC_Decode  = u_processor.datapath.d_pc;
  wire [31:0] SPY_PC_Execute = u_processor.datapath.x_pc;
  wire [31:0] SPY_PC_Memory  = u_processor.datapath.m_pc;
  wire [31:0] SPY_PC_WB      = u_processor.datapath.w_pc;

  // --- GROUP 2: HAZARD & STALL (Quan trọng nhất cho Pipelined Divider) ---
  // Khi Stall = 1, PC Fetch phải đứng yên, và Decode phải giữ nguyên lệnh cũ
  wire        SPY_Stall_Global  = u_processor.datapath.stall_pipe;
  wire        SPY_Flush_Branch  = u_processor.datapath.flush_pipe;
  // Xem lý do tại sao Stall:
  wire        SPY_Stall_LoadUse = u_processor.datapath.load_use_hazard;
  wire        SPY_Stall_DivBusy = u_processor.datapath.stall_div_block; // Divider làm kẹt pipeline

  // --- GROUP 3: DIVIDER INTERNALS (Soi ruột bộ chia) ---
  // Input vào bộ chia (sau khi lấy trị tuyệt đối)
  wire [31:0] SPY_Div_In_A_Abs  = u_processor.datapath.div_in_a_abs;
  wire [31:0] SPY_Div_In_B_Abs  = u_processor.datapath.div_in_b_abs;
  // Trạng thái pipeline của bộ chia (Các bit valid trong thanh ghi dịch)
  // Nếu thấy các bit này 'trôi' đi sau mỗi clock nghĩa là bộ chia đang chạy tốt.
  wire [7:0]  SPY_Div_Valid_Pipe = u_processor.datapath.div_valid; 
  // Kết quả cuối cùng được chọn để Forward hoặc Writeback
  wire [31:0] SPY_Div_Result_Final = u_processor.datapath.div_result_final;
  
  // --- GROUP 4: EXECUTION DATA ---
  wire [31:0] SPY_ALU_Src_A     = u_processor.datapath.x_op_a;
  wire [31:0] SPY_ALU_Src_B     = u_processor.datapath.x_op_b;
  wire [31:0] SPY_ALU_Result    = u_processor.datapath.x_alu_res;
  
  // --- GROUP 5: WRITEBACK (Kết quả ghi vào thanh ghi) ---
  wire        SPY_WB_RegWrite   = u_processor.datapath.w_reg_we;
  wire [4:0]  SPY_WB_Rd_Index   = u_processor.datapath.w_rd;
  wire [31:0] SPY_WB_Data       = u_processor.datapath.w_wb_data;
    // ===========================================================================
  // GROUP 6: MEMORY INTERFACE (Soi kỹ Load/Store)
  // ===========================================================================
  
  // 1. Địa chỉ truy cập Memory (Quan trọng: Phải kiểm tra xem có bị lệch 4 byte không)
  wire [31:0] SPY_MEM_Addr         = u_processor.datapath.m_addr;
  
  // 2. Tín hiệu điều khiển Load/Store
  wire        SPY_MEM_Is_Load      = u_processor.datapath.m_is_load;
  wire        SPY_MEM_Is_Store     = u_processor.datapath.m_is_store;
  
  // 3. Write Mask (Quan trọng nhất cho Store Byte/Half):
  // Nếu là SW -> Phải là 4'b1111
  // Nếu là SB -> Phải là 4'b0001, 4'b0010, 4'b0100 hoặc 4'b1000 tùy địa chỉ
  wire [3:0]  SPY_MEM_Web_Mask     = u_processor.datapath.m_store_we;
  
  // 4. Dữ liệu ghi xuống (Store Data)
  // Lưu ý: Dữ liệu này đã được dịch (shifted) vào đúng vị trí byte chưa?
  wire [31:0] SPY_MEM_Store_Data   = u_processor.datapath.m_store_data_aligned;
  
  // 5. Dữ liệu đọc lên (Load Data)
  // Raw: Dữ liệu thô 32-bit lấy từ Memory
  wire [31:0] SPY_MEM_Load_Raw     = u_processor.datapath.load_data_from_dmem;
  
  // Final: Dữ liệu sau khi đã qua bộ xử lý Load (Sign-extension, Masking)
  // So sánh cái này với Raw để xem lệnh LB/LBU/LH có hoạt động đúng không.
  wire [31:0] SPY_MEM_Load_Final   = u_processor.datapath.load_wb_value;

  // ===========================================================================
  // 5. TEST SCENARIO
  // ===========================================================================
  initial begin
    // a. Setup Environment
    // Nếu dùng Vivado thì không cần $dumpfile, nhưng cứ để nếu dùng Icarus
    // $dumpfile("waveform.vcd");
    // $dumpvars(0, tb_processor);

    // b. Initialize
    rst = 1;
    test_case = "START_TRACE"; 
    
    // c. Reset Sequence
    #20;
    rst = 0;
    $display("[%0t] Reset released. Processor running...", $time);

    // d. Wait for HALT (ECALL)
    // Tăng timeout lên nếu chạy các phép chia dài
    wait(halt);
    
    // e. Finish
    $display("[%0t] SUCCESS: ECALL detected. Simulation finished.", $time);
    $display("       Final Writeback PC: %h", trace_writeback_pc);
    #50;
    $finish;
  end

  // ===========================================================================
  // 6. WATCHDOG TIMER
  // ===========================================================================
  initial begin
    // 50,000ns = 5000 cycles. Tăng lên nếu chương trình test dài.
    #50000;
    $display("[%0t] ERROR: Watchdog Timeout! Processor hung or loop infinite.", $time);
    $display("       Check SPY_Stall_Global signal. Is it stuck at 1?");
    $finish;
  end

  // ===========================================================================
  // 7. CONSOLE MONITOR (Optional - In ra màn hình để debug nhanh)
  // ===========================================================================
  always @(posedge clk) begin
    // In ra kết quả khi có Writeback (Ghi vào thanh ghi)
    if (!rst && SPY_WB_RegWrite && (SPY_WB_Rd_Index != 0)) begin
        $display("[%0t] WB: x%0d = %h (PC=%h)", 
                 $time, SPY_WB_Rd_Index, SPY_WB_Data, SPY_PC_WB);
    end
    // Đoạn code kiểm tra Stall cũ bị lỗi do thiếu biến stall_pipe_prev. 
    // Tôi đã xóa nó đi để cậu không bị lỗi nữa.
    // Nếu muốn debug stall, hãy nhìn tín hiệu SPY_Stall_Global trên Waveform!
  end

endmodule