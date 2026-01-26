// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTOP__SYMS_H_
#define _VTOP__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vtop.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vtop__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtop*                          TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_Processor;
    VerilatedScope __Vscope_Processor__datapath;
    VerilatedScope __Vscope_Processor__datapath__rf;
    VerilatedScope __Vscope_Processor__datapath__u_divider;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__0__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__1__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__2__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__3__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__4__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__5__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__6__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__0__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__0__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__1__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__1__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__2__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__2__KET____u_iter;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__3__KET__;
    VerilatedScope __Vscope_Processor__datapath__u_divider__STAGE__BRA__7__KET____ITER__BRA__3__KET____u_iter;
    VerilatedScope __Vscope_Processor__memory;
    VerilatedScope __Vscope_TOP;
    
    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;
    
    // CREATORS
    Vtop__Syms(Vtop* topp, const char* namep);
    ~Vtop__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
