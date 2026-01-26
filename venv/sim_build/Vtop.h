// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(halt,0,0);
    VL_OUT(trace_writeback_pc,31,0);
    VL_OUT(trace_writeback_inst,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ Processor__DOT__clk;
        CData/*0:0*/ Processor__DOT__rst;
        CData/*0:0*/ Processor__DOT__halt;
        CData/*3:0*/ Processor__DOT__mem_data_we;
        CData/*0:0*/ Processor__DOT__memory__DOT__rst;
        CData/*0:0*/ Processor__DOT__memory__DOT__clk;
        CData/*3:0*/ Processor__DOT__memory__DOT__store_we_to_dmem;
        CData/*0:0*/ Processor__DOT__datapath__DOT__clk;
        CData/*0:0*/ Processor__DOT__datapath__DOT__rst;
        CData/*3:0*/ Processor__DOT__datapath__DOT__store_we_to_dmem;
        CData/*0:0*/ Processor__DOT__datapath__DOT__halt;
        CData/*0:0*/ Processor__DOT__datapath__DOT__d_valid;
        CData/*4:0*/ Processor__DOT__datapath__DOT__d_rs1;
        CData/*4:0*/ Processor__DOT__datapath__DOT__d_rs2;
        CData/*4:0*/ Processor__DOT__datapath__DOT__d_rd;
        CData/*2:0*/ Processor__DOT__datapath__DOT__d_funct3;
        CData/*6:0*/ Processor__DOT__datapath__DOT__d_funct7;
        CData/*6:0*/ Processor__DOT__datapath__DOT__d_opcode;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_valid;
        CData/*4:0*/ Processor__DOT__datapath__DOT__x_rd;
        CData/*2:0*/ Processor__DOT__datapath__DOT__x_funct3;
        CData/*6:0*/ Processor__DOT__datapath__DOT__x_funct7;
        CData/*6:0*/ Processor__DOT__datapath__DOT__x_opcode;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_load;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_store;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_branch;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_jal;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_jalr;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_lui;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_auipc;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_alu_imm;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_alu_reg;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_mul;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_div;
        CData/*0:0*/ Processor__DOT__datapath__DOT__x_is_ecall;
        CData/*0:0*/ Processor__DOT__datapath__DOT__m_valid;
        CData/*4:0*/ Processor__DOT__datapath__DOT__m_rd;
        CData/*2:0*/ Processor__DOT__datapath__DOT__m_funct3;
        CData/*0:0*/ Processor__DOT__datapath__DOT__m_is_load;
        CData/*0:0*/ Processor__DOT__datapath__DOT__m_is_store;
        CData/*0:0*/ Processor__DOT__datapath__DOT__m_reg_we;
        CData/*0:0*/ Processor__DOT__datapath__DOT__w_valid;
        CData/*4:0*/ Processor__DOT__datapath__DOT__w_rd;
        CData/*0:0*/ Processor__DOT__datapath__DOT__w_reg_we;
        CData/*0:0*/ Processor__DOT__datapath__DOT__rf_we;
        CData/*4:0*/ Processor__DOT__datapath__DOT__rf_rd;
        CData/*0:0*/ Processor__DOT__datapath__DOT__stall_pipe;
        CData/*0:0*/ Processor__DOT__datapath__DOT__flush_pipe;
        CData/*0:0*/ Processor__DOT__datapath__DOT__fwd_div_valid;
        CData/*4:0*/ Processor__DOT__datapath__DOT__fwd_div_rd;
        CData/*0:0*/ Processor__DOT__datapath__DOT__w_main_we;
        CData/*4:0*/ Processor__DOT__datapath__DOT__x_rs1_idx;
        CData/*4:0*/ Processor__DOT__datapath__DOT__x_rs2_idx;
        CData/*0:0*/ Processor__DOT__datapath__DOT__load_use_hazard;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_dep_hazard_rs1;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_dep_hazard_rs2;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_dep_hazard;
        CData/*0:0*/ Processor__DOT__datapath__DOT__branch_taken;
        CData/*0:0*/ Processor__DOT__datapath__DOT__m_reg_we_next;
        CData/*3:0*/ Processor__DOT__datapath__DOT__m_store_we;
        CData/*0:0*/ Processor__DOT__datapath__DOT__w_reg_we_next;
        CData/*7:0*/ Processor__DOT__datapath__DOT__div_valid;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_is_signed_now;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_ready_valid;
    };
    struct {
        CData/*4:0*/ Processor__DOT__datapath__DOT__div_ready_rd;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_ready_is_rem;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_ready_signed;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_ready_div0;
        CData/*0:0*/ Processor__DOT__datapath__DOT__sign_a_last;
        CData/*0:0*/ Processor__DOT__datapath__DOT__sign_b_last;
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_overflow;
        CData/*4:0*/ Processor__DOT__datapath__DOT__rf__DOT__rd;
        CData/*4:0*/ Processor__DOT__datapath__DOT__rf__DOT__rs1;
        CData/*4:0*/ Processor__DOT__datapath__DOT__rf__DOT__rs2;
        CData/*0:0*/ Processor__DOT__datapath__DOT__rf__DOT__clk;
        CData/*0:0*/ Processor__DOT__datapath__DOT__rf__DOT__we;
        CData/*0:0*/ Processor__DOT__datapath__DOT__rf__DOT__rst;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__clk;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__rst;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__stall;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__condition;
        CData/*0:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__condition;
        IData/*31:0*/ Processor__DOT__trace_writeback_pc;
        IData/*31:0*/ Processor__DOT__trace_writeback_inst;
        IData/*31:0*/ Processor__DOT__inst_from_imem;
        IData/*31:0*/ Processor__DOT__pc_to_imem;
        IData/*31:0*/ Processor__DOT__mem_data_addr;
        IData/*31:0*/ Processor__DOT__mem_data_loaded_value;
        IData/*31:0*/ Processor__DOT__mem_data_to_write;
        WData/*255:0*/ Processor__DOT__test_case[8];
        IData/*31:0*/ Processor__DOT__memory__DOT__pc_to_imem;
        IData/*31:0*/ Processor__DOT__memory__DOT__inst_from_imem;
        IData/*31:0*/ Processor__DOT__memory__DOT__addr_to_dmem;
        IData/*31:0*/ Processor__DOT__memory__DOT__load_data_from_dmem;
        IData/*31:0*/ Processor__DOT__memory__DOT__store_data_to_dmem;
        IData/*31:0*/ Processor__DOT__datapath__DOT__pc_to_imem;
        IData/*31:0*/ Processor__DOT__datapath__DOT__inst_from_imem;
        IData/*31:0*/ Processor__DOT__datapath__DOT__addr_to_dmem;
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__load_data_from_dmem;
        IData/*31:0*/ Processor__DOT__datapath__DOT__store_data_to_dmem;
        IData/*31:0*/ Processor__DOT__datapath__DOT__trace_writeback_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__trace_writeback_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__cycles_current;
        IData/*31:0*/ Processor__DOT__datapath__DOT__f_pc_current;
        IData/*31:0*/ Processor__DOT__datapath__DOT__f_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__f_pc_next;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_rs1_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_rs2_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_imm_i;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_imm_s;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_imm_b;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_imm_j;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_store_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_alu_res;
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_store_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__w_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__w_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__w_wb_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf_wdata;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rs1_data_raw;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rs2_data_raw;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_imm_i;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_imm_s;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_imm_b;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_imm_j;
        IData/*31:0*/ Processor__DOT__datapath__DOT__fwd_div_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_rs1_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__d_rs2_val;
        IData/*31:0*/ Processor__DOT__datapath__DOT__w_main_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_op_a;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_op_b;
        IData/*31:0*/ Processor__DOT__datapath__DOT__branch_target;
        IData/*31:0*/ Processor__DOT__datapath__DOT__x_alu_res;
        WData/*64:0*/ Processor__DOT__datapath__DOT__mul_temp_65[3];
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_store_data_aligned;
        IData/*31:0*/ Processor__DOT__datapath__DOT__m_addr;
        IData/*31:0*/ Processor__DOT__datapath__DOT__load_wb_value;
        IData/*31:0*/ Processor__DOT__datapath__DOT__w_wb_data_next;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_in_a_abs;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_in_b_abs;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_quotient_u;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_remainder_u;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_i;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_ready_pc;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_ready_inst;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_ready_src_a;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_ready_src_b;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_quo_signed;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_rem_signed;
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_result_final;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf__DOT__rd_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf__DOT__rs1_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf__DOT__rs2_data;
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf__DOT__i;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__i_divisor;
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_divisor;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__i_quotient;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_dividend;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
    };
    struct {
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__diff;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__remainder_next;
        QData/*32:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__diff;
        IData/*31:0*/ Processor__DOT__memory__DOT__mem_array[8192];
        CData/*4:0*/ Processor__DOT__datapath__DOT__div_rd_pipe[8];
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_is_rem[8];
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_is_signed[8];
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_pc_pipe[8];
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_inst_pipe[8];
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_sign_a[8];
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_sign_b[8];
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_src_a[8];
        IData/*31:0*/ Processor__DOT__datapath__DOT__div_src_b[8];
        CData/*0:0*/ Processor__DOT__datapath__DOT__div_div_zero[8];
        IData/*31:0*/ Processor__DOT__datapath__DOT__rf__DOT__regs[32];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__stage_dividend[9];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__stage_remainder[9];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__stage_quotient[9];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__stage_divisor[9];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__t_remainder[5];
    };
    struct {
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__t_quotient[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__t_dividend[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__t_remainder[5];
        IData/*31:0*/ Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__t_quotient[5];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __Vfunc_Processor__DOT__datapath__DOT__div_hazard_match__0__Vfuncout;
        CData/*4:0*/ __Vfunc_Processor__DOT__datapath__DOT__div_hazard_match__0__rs;
        CData/*0:0*/ __Vfunc_Processor__DOT__datapath__DOT__div_hazard_match__1__Vfuncout;
        CData/*4:0*/ __Vfunc_Processor__DOT__datapath__DOT__div_hazard_match__1__rs;
        CData/*0:0*/ __Vclklast__TOP__clk;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__0__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_remainder;
    };
    struct {
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__1__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__2__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_remainder;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__ITER__BRA__3__KET____DOT__u_iter__DOT__o_quotient;
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__0__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__1__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__2__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__3__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__4__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__5__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__6__KET____DOT__t_dividend[5];
        IData/*31:0*/ __Vchglast__TOP__Processor__DOT__datapath__DOT__u_divider__DOT__STAGE__BRA__7__KET____DOT__t_dividend[5];
        CData/*0:0*/ __Vm_traceActivity[1];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
