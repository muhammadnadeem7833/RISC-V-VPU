RISC-V Cross-Compilation Toolchain Setup
========================================

Pre-requisites:
---------------

* Download `WSL` or `Vitual Machine`.
* Install any version of `UBUNTU` on `WSL` or `VM`. (preferably the latest)
* Download `Terminal` from Microsoft Store. (optional)

Step-by-Step guide:
-------------------
	Open the terminal and start following the given steps.
+ #### Set your environment variables or Paths:
  
  - **Open the `.bashrc` file:**
    
    * ```shell
      nano ~/.bashrc
  - **Paste the following commands in the end of the `.bashrc` file.**
    
       ``` shell
       export RISCV_PATH="$HOME/proj/binaries/riscv-toolchain"
       export RISCV_TOOLCHAIN=$RISCV_PATH
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

  - **Press `Ctrl+S` to save. Then press `Ctrl+X` to exit.**
    
  - **To apply the changes we made in the `.bashrc` file, run the following command on the terminal:**
    
    ``` shell
    source ~/.bashrc

+ **Make directories:**
  
  ``` shell
  mkdir -p ~/proj/tools; cd ~/proj; mkdir -p binaries/riscv-toolchain; cd tools;

+ **Clone the official `RISC-V` GitHub repository, this will make the directory `riscv-gnu-toolchain` inside the `tools` directory:**
  
  ``` shell
  git clone --recursive  https://github.com/riscv/riscv-gnu-toolchain
**NOTE: You can remove `--recursive` if you have stable internet connection because the recursive approach downloads all submodules of the `Git` and vice versa.**


+ **For `Ubuntu` dependencies, run the following commands:**
  
  ``` shell
  sudo apt-get -y install autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev python3-pip

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
    
    **NOTE: `C` extension of RISC-V architecture in `--with-arch=rv32/64 imafdqcv_zifencei_zicsr` is for compressed instructions support, you can remove if you don’t want compressed instructions.And in the command `make -j3`, `3` represents the utilization of the number of `CPU cores` while installing, you can increase this accordingly.**

+ **Installation of `spike`:**
  
  - **Move to the `tools` directory and clone the link below which will make a directory `spike-riscv` inside the `tools` directory:**
    
    ``` shell
    git clone --recursive https://github.com/riscv-software-src/riscv-isa-sim.git spike-riscv
  - **This step will build the necessary dependencies:**
    
    ``` shell
    sudo apt-get install device-tree-compiler
  - **Inside the `spike-riscv` directory:**
    
    ``` shell
    mkdir build;cd build
    ```
    
    * **Configure `32-bit` `spike`: (for `32-bit` toolchain)**
      
      ``` shell
      ../configure --prefix=$SPIKE_PATH_32 --with-isa=RV32IMAFDQCV
      ```
      
      ``` shell
      make -j3
      ```
      
      ``` shell
      sudo make install

    * **Configure `64-bit` `spike`: (for `64-bit` toolchain)**
      
      ``` shell
      ../configure --prefix=$SPIKE_PATH_64
      ```
      
      ``` shell
      make -j3
      ```
   
      ``` shell
      sudo make install
      
    **NOTE: Also here `C` extension should be removed if you have done this earlier while configuring the toolchain.**

+ **Installation of `Pk`:**

  - **Clone inside the `tools` directory which will make a directory `riscv-pk` inside the `tools` directory:**
    
    ``` shell
    git clone --recursive https://github.com/riscv-software-src/riscv-pk.git

  - **Inside the `riscv-pk` directory:**

    ``` shell
    mkdir build;cd build
    ```
    
    * **Configure 32-bit pk: (for 32-bit toolchain & 32-bit spike)**
      
      ``` shell
      ../configure --prefix=$PK_PATH_32 --host=riscv32-unknown-elf --with-arch=rv32imafdqcv_zifencei_zicsr --with-abi=ilp32d
      ```

      ``` shell
      make -j3
      ```

      ``` shell
      sudo make install

    * **Configure 64-bit pk: (for 64-bit toolchain & 64-bit spike)**

      ``` shell
      ../configure --prefix=$PK_PATH_64 --host=riscv64-unknown-elf --with-arch=rv64imafdqcv_zifencei_zicsr
      ```
   
      ``` shell
      make -j3
      ```
   
      ``` shell
      sudo make install
    **NOTE: Also here `C` extension should be removed if you have done this earlier while configuring the toolchain and the `spike`.**

Toolchain test with an example:
-------------------------------

+ **Download `VS Code` and link it with `WSL`.**

+ **On the terminal, create a separate directory in the `proj` directory for test code files. (good practice)**

+ **Write a short `C` code in VS code and save it in the test code folder you made in the previous step.**

+ **On the terminal, move to the code directory and run the C code using the following command:**

  ``` shell
  riscv32-unknown-elf-gcc -o (output filename) (C filename).c
  
+ **You will find the output file in the same directory.**

+ **Now, run the output file using `spike` simulator and `pk` using the following command:**
  - **To run the assembly programe normally:**
    
  ``` shell
  spike $pk (output filename)
  ```
  - **To run the assembly programe line-by-line:**
    
  ``` shell
  spike -d $pk (output filename)

Screenshots of Example:
-----------------------

![image](https://github.com/muhammadnadeem7833/RISC-V-VPU/assets/124807084/4cb2fa6f-7dbc-4617-8d16-610cacad045d)

![image](https://github.com/muhammadnadeem7833/RISC-V-VPU/assets/124807084/71afd9ed-ef08-477a-b445-0648b80e788b)
