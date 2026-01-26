# 5-Stage Pipelined RISC-V Processor (RV32IM)

![Status](https://img.shields.io/badge/Status-Development-yellow)
![Language](https://img.shields.io/badge/Verilog-SystemVerilog-blue)
![Simulation](https://img.shields.io/badge/Simulation-Cocotb%20%7C%20Icarus-green)
![Target](https://img.shields.io/badge/FPGA-Arty--Z7--20-orange)

## 📖 Project Overview
[cite_start]This repository contains the RTL implementation of a **5-stage Pipelined RISC-V Processor** targeting the **Arty-Z7 FPGA board**. The core implements the **RV32IM** instruction set (Integer + Multiplication/Division) and is designed to handle complex pipeline hazards including data forwarding and control flushing.

### Key Features
* **5-Stage Pipeline:** Fetch, Decode, Execute, Memory, and Writeback stages.
* **Hazard Handling:**
    * **Data Hazard:** Full Forwarding unit implementing MX, WX, and WD bypasses to resolve Read-After-Write (RAW) dependencies.
    * **Control Hazard:** Pipeline flushing on taken branches to maintain correct execution flow.
    * **Load-Use Hazard:** Intelligent stall logic insertion in the Decode stage.
* **Arithmetic Extensions:**
    * Hardware Multiplier support.
    * **Pipelined Divider:** Non-restoring division algorithm with an 8-stage internal pipeline for high-frequency operation.
* **Verification:** Fully verified using **Cocotb** (Python-based testbench) against official RISC-V architectural tests.

---

## 📂 Repository Structure
* `rtl/`: Core Verilog source files (Datapath, CLA, Pipelined Divider).
* `testbench/`: Python verification environment and scripts.
* `testcase_python/`: Binary and Hex files for RISC-V architectural tests.
* `venv/`: Python virtual environment and simulation build artifacts.

---

## 🛠️ Simulation & Testing Guide

To ensure all Verilog includes and Python paths are resolved correctly, please follow this **"All-in-One"** consolidation method.

### Prerequisites
* **WSL (Windows Subsystem for Linux)** or a native Linux environment[cite: 444].
* **Icarus Verilog** (`iverilog`) installed.
* **Python 3.x** with `cocotb` and `pytest` installed.

### 🚀 Running the Testbench
Since the project relies on specific file hierarchies, the most robust way to run simulation is to consolidate all necessary files into a single workspace.

**Step 1: Consolidate Files**
Create a new folder (e.g., `sim_run`) and copy **ALL contents** from the following directories into it:
1. Copy all files from inside `/rtl`
2. Copy all files from inside `/testbench`
3. Copy all files from inside `/testcase_python`
4. Copy necessary environment files from `/venv`

**Step 2: Execute Simulation in WSL**
Open your WSL terminal, navigate to your consolidated folder, and run the following command:

```bash
pytest -o "python_functions=run*" testbench.py::runCocotbTestsProcessor
📊 Expected Verification Output
A successful run should produce an output similar to the log below, showing PASS status for the architectural tests:

Plaintext
*****************************************************************************************
** testbench.riscvTest_033            PASS        1372.00           0.07       18440.35  **
** testbench.riscvTest_034            PASS        1272.00           0.07       17362.36  **
** testbench.riscvTest_035            PASS        1272.00           0.07       19071.71  **
** testbench.riscvTest_036            PASS        2416.00           0.13       18496.71  **
** testbench.riscvTest_037            PASS        2388.00           0.13       19064.01  **
** testbench.riscvTest_038            PASS        2176.00           0.11       19848.87  **
** testbench.riscvTest_039            PASS        2156.00           0.10       20598.30  **
** testbench.riscvTest_040            PASS        2156.00           0.11       19661.99  **
** testbench.riscvTest_041            PASS        2156.00           0.11       19685.02  **
** testbench.riscvTest_042            PASS        2156.00           0.11       19860.68  **
** testbench.riscvTest_043            PASS         836.00           0.04       18723.29  **
** testbench.riscvTest_044            PASS         840.00           0.04       19580.62  **
** testbench.riscvTest_045            PASS         836.00           0.04       19495.72  **
** testbench.riscvTest_046            PASS         836.00           0.04       18791.83  **
** testbench.dhrystone                FAIL     1120012.00          47.98       23341.38  **
*****************************************************************************************
** TESTS=77 PASS=75 FAIL=2 SKIP=0             1195832.08          52.74       22673.23  **
*****************************************************************************************
🧪 Testbench Explanation (testbench.py)
The verification environment uses Cocotb to drive the Verilog simulation through Python. Key functions include:

1. runCocotbTestsProcessor
This is the main entry point that configures the simulation runner.

Icarus Verilog Flags: It uses -g2012 to enable SystemVerilog features and passes the DIVIDER_STAGES macro to match the hardware configuration.

Automated Build: It handles the compilation of DatapathPipelined.v and its dependencies automatically.

2. preTestSetup
This function ensures every test starts from a known state.

Clock & Reset: It generates a 4ns clock and asserts the reset signal for one cycle.

Binary Loading: It uses riscv_binary_utils to load the target assembly or binary into the processor's memory before execution begins.

3. rvTestFactory
To avoid manual repetition, a factory pattern is used to generate test cases.

Dynamic Generation: It iterates through RV_TEST_BINARIES and creates individual test cases for each architectural test (e.g., riscvTest_033).

Scalability: This allows for running the entire ISA test suite with a single command.

Author: Le Ngoc Uy Phong

Course: Introduction to SoC Design


University: Ho Chi Minh City University of Technology (HCMUT)
