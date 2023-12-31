module IM_ROM(instr_addr, instr);

  output [15:0] instr; //16-bit instr. to be fetched from this module
  input [7:0] instr_addr;  //address of instruction from PC module

  reg [15:0] ROM[0:255];  //memry array

  integer i;

  initial  //to store the instructions in memory(ROM)
  begin
    ROM[0] = 16'b000_010_001_001_0110; //li
    ROM[1] = 16'b000_110_001_000_0110; //li
    ROM[2] = 16'b000_000_001_010_0000; //ADD
    ROM[3] = 16'b010_010_000_000_0001; //sll
    ROM[4] = 16'b011_010_001_001_0010; //slr
    ROM[5] = 16'b010_001_000_011_0011; //or
    ROM[6] = 16'b010_000_001_100_0100; //and
    ROM[7] = 16'b000_011_100_101_0101; //addi
    ROM[8] = 16'b000_000_000_000_1000; //sw
    ROM[9] = 16'b000_000_000_110_0111; //lw
    ROM[10] = 16'b000_000_001_000_1010; //mul	
    ROM[11] = 16'b000_011_001_111_1011; //mflo	
    ROM[12] = 16'b000_000_000_000_1100; //mfhi
    ROM[13] = 16'b000_000_000_000_1001; //b
    for(i=14; i<256; i=i+1)
      ROM[i]=0;	
    //ROM[13] = 16'b000_010_001_000_1101; //please add conditional instrs as per your code
    //ROM[14] = 16'b000_010_001_000_1110; //please add conditional instrs as per your code
  end

  assign instr = ROM[instr_addr]; //fetching instruction from address

endmodule
