RISC-V Cross-Compilation Toolchain Setup
========================================

Pre-requisites:
---------------
* Any version of `UBUNTU` (preferably the latest)
* `WSL` from Microsoft Store
* `Terminal` from Microsoft Store (optional)

Step-by-Step guide:
-------------------
	Open the terminal and start following the given steps.
+ #### Set your environment variables or Paths:
  - **Open the `.bashrc` file:**
    * `nano ~/.bashrc`
  - **Paste the following commands to the `.bashrc` file:**
       ``` shell
       export RISCV_PATH="$HOME/proj/binaries/riscv-toolchain"
       export RISCV_TOOLCHAIN=$RISCV_PATH
       export RISCV_GCC="$RISCV_TOOLCHAIN/bin/riscv64-unknown-elf-gcc"
       export RISCV_OBJCOPY="$RISCV_TOOLCHAIN/bin/riscv64-unknown-elf-objcopy"
       export RISCV_LD="$RISCV_TOOLCHAIN/bin/riscv64-unknown-elf-ld"
       export RISCV_OBJDUMP="$RISCV_TOOLCHAIN/bin/riscv64-unknown-elf-objdump"
       export SPIKE_PATH=$RISCV_TOOLCHAIN/bin
       export SPIKE_PATH_32=$RISCV_TOOLCHAIN/bin/spike32
       export SPIKE_PATH_64=$RISCV_TOOLCHAIN/bin/spike64
       export SPIKE_PATH_DEFAULT=$RISCV_TOOLCHAIN/bin/default
       export PK_PATH=$RISCV_TOOLCHAIN/bin
       export PK_PATH_32=$RISCV_TOOLCHAIN/bin/pk32
       export PK_PATH_64=$RISCV_TOOLCHAIN/bin/pk64
       export PATH=$RISCV_TOOLCHAIN/rv64/bin:$PATH
       export PATH=$RISCV_TOOLCHAIN/rv32/bin:$PATH
       export PATH=$RISCV_TOOLCHAIN/multi/bin:$PATH
       export PATH=$RISCV_TOOLCHAIN/riscv32-unknown-elf/bin:$PATH
       export PATH=$RISCV_TOOLCHAIN/riscv64-unknown-elf/bin:$PATH
       export PATH=$SPIKE_PATH_32/bin:$PATH
       export PATH=$SPIKE_PATH_64/bin:$PATH
       export PATH=$SPIKE_PATH_DEFAULT/bin:$PATH
       export PATH=$PK_PATH_32/riscv32-unknown-elf/bin:$PATH
       export PATH=$PK_PATH_64/bin:$PATH
       export pk=$RISCV_TOOLCHAIN/bin/pk32/riscv32-unknown-elf/bin/pk 
       ```
       	**Like this:**
