module cocotb_iverilog_dump();
initial begin
    $dumpfile("/mnt/d/SoC_lab/assignment/sim_build/Processor.fst");
    $dumpvars(0, Processor);
end
endmodule
