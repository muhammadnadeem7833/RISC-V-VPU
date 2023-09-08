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
    
    * ```shell
      nano ~/.bashrc
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
    
       ![image](https://github.com/muhammadnadeem7833/RISC-V-VPU/assets/124807084/05fd2908-9060-4cb6-a6bf-5c34bd2c4bad)

  - **Press `Ctrl+S` to save. Then press `Ctrl+X` to exit.**
    
  - **To apply the changes in the `.bashrc` file we made, run the following command on the terminal:**
    
    ``` shell
    source ~/.bashrc

+ **Make directories:**
  
  ``` shell
  mkdir -p ~/proj/tools; cd ~/proj; mkdir -p binaries/riscv-toolchain; cd tools;

+ **Clone the official `RISC-V` GitHub repository, this will make the directory `riscv-gnu-toolchain` inside the `tools` directory:**
  
  ``` shell
  git clone  https://github.com/riscv/riscv-gnu-toolchain

+ **For `Ubuntu` dependencies, run the following commands:**
  
  ``` shell
  sudo apt-get install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
  ```
  ``` shell
  sudo apt-get -y install python3-pip

+ **Inside the `riscv-gnu-toolchain` directory, make a directory `build` and open it:**
  
  ``` shell
  cd riscv-gnu-toolchain; mkdir build; cd build
  
+ **Configure the toolchain:**
  
  - **For pure `64-bit` toolchain:**
    
    ``` shell
    ../configure --prefix=$RISCV_PATH/rv64  --enable-multilib --with-arch=rv64imafdqcv_zifencei_zicsr
    ```
    ``` shell
    make -j3
    
  - **For pure `32-bit` toolchain:**
    
    ``` shell
    ../configure --prefix=$RISCV_PATH/rv32  --enable-multilib --with-arch=rv32imafdqcv_zifencei_zicsr
    ```
    ``` shell
    make -j3
    
  - **For `multi-bit support` toolchain:**
    
    ``` shell
    ../configure --prefix=$RISCV_PATH/multi  --enable-multilib
    ```
    ``` shell
    make -j3
    ```
    
    **NOTE: `C` extension of RISC-V architecture in `--with-arch=rv32/64 imafdqcv_zifencei_zicsr` is for compressed instructions support, you can remove if you don’t want compressed instructions.**
