# OS in 1,000 Lines
This repository contains my implementation of the OS from the online book [Operating System in 1,000 Lines](https://operating-system-in-1000-lines.vercel.app/en/).

## Getting started
1. Install dependencies
    ```bash
    sudo apt update && sudo apt install -y clang llvm lld qemu-system-riscv32 curl
    ```
2. Download OpenSBI
    ```bash
    curl -LO https://github.com/qemu/qemu/raw/v8.0.4/pc-bios/opensbi-riscv32-generic-fw_dynamic.bin
    ```
3. Build and run the OS
    ```bash
    ./run.sh
    ```

## Overview
```
├── disk/     - File system contents
├── common.c  - Kernel/user common library: printf, memset, ...
├── common.h  - Kernel/user common library: definitions of structs and constants
├── kernel.c  - Kernel: process management, system calls, device drivers, file system
├── kernel.h  - Kernel: definitions of structs and constants
├── kernel.ld - Kernel: linker script (memory layout definition)
├── shell.c   - Command-line shell
├── user.c    - User library: functions for system calls
├── user.h    - User library: definitions of structs and constants
├── user.ld   - User: linker script (memory layout definition)
└── run.sh    - Build script
```