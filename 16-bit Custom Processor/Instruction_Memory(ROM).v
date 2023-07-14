module IM_ROM(pc,instr);

  output reg [15:0] instr;
  input [7:0] pc;  //program counter value from PC module
  reg [15:0] ROM[0:12];  //memry array

  initial  //to store the instructions in memory(ROM)
  begin
    ROM[0] = 16'b000_010_001_000_0000; //ADD
    ROM[1] = 16'b010_010_000_001_0001; //sll
    ROM[2] = 16'b001_010_001_010_0010; //slr
    ROM[3] = 16'b010_010_000_011_0011; //or
    ROM[4] = 16'b010_010_011_100_0100; //and
    ROM[5] = 16'b000_011_100_101_0101; //addi
    ROM[6] = 16'b000_000_001_011_0110; //li
    ROM[7] = 16'b000_100_011_000_0111; //lw
    ROM[8] = 16'b000_010_000_000_1000; //sw
    ROM[9] = 16'b000_000_000_011_1001; //b
    ROM[10] = 16'b000_011_001_000_1010; //mul	
    ROM[11] = 16'b000_011_001_000_1011; //mflo	
    ROM[12] = 16'b000_000_000_011_1100; //mfhi	
    //ROM[13] = 16'b000_010_001_000_1101; //please add conditional instrs as per your code
    //ROM[14] = 16'b000_010_001_000_1110; //please add conditional instrs as per your code
  end

  //an easier approach to picking instruction from ROM is as follows:
  //assing inst = ROM[pc];
  //This avoids the MUX, here PC acts as the address line of the ROM
  
  always @(*) //MUX with 'pc' as select line of 8-bit
  begin  //for initial 13 locations only
    case(pc)
      8'd0: instr=ROM[0];
      8'd1: instr=ROM[1];
      8'd2: instr=ROM[2];
      8'd3: instr=ROM[3];
      8'd4: instr=ROM[4];
      8'd5: instr=ROM[5];
      8'd6: instr=ROM[6];
      8'd7: instr=ROM[7];
      8'd8: instr=ROM[8];
      8'd9: instr=ROM[9];
      8'd10: instr=ROM[10];
      8'd11: instr=ROM[11];
      8'd12: instr=ROM[12];
    endcase
  end

endmodule
