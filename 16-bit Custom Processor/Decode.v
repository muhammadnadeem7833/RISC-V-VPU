module Decode(instr, PC_select, source2_select, ALU_out_select, jump_addr, immediate_addr, Rreg_sig1, Rreg_sig2, Wreg_sig, opcode);
  input [15:0] instr; //from instruction register(IR)

  output PC_select; //control line to decide PC's next value
  output source2_select; //control line to decide 2nd input for ALU
  output ALU_out_select; //control line to decide value for write-register
  output [7:0] jump_addr; //8-bit address for PC in case of jump
  output [5:0] immediate_addr; //6-bit address for ALU input for I-type instr.
  output [2:0] Rreg_sig1; //for source-1 register
  output [2:0] Rreg_sig2; //for source-2 register
  output [2:0] Wreg_sig; //for destination register
  output [3:0] opcode; //for ALU-con module

  reg PC_select, source2_select, ALU_out_select;
  reg [7:0] jump_addr;
  reg [5:0] immediate_addr;
 
//block to set PC_select control line and send address to jump
  always @(*)
  begin 
    if(instr[3:0] == 4'b1001) //if jump instruction, PC_select == 1, otherwise 0
    begin
      PC_select = 1;
      jump_addr = instr[11:4];
    end
    else
      PC_select = 0;
  end

//block to set source2_select control line and send address to ALU
  always @(*)
  begin 
    if(instr[3:0] >= 5 && instr[3:0] <= 8) //if I-type instructions, source2_select == 1, otherwise 0
    begin
      source2_select = 1;
      immediate_addr = instr[15:10];
    end
    else
      source2_select = 0;
  end

//block to set ALU_out_select control line
 always @(*)
  begin 
    if(instr[3:0] == 4'b0111) //if lw instruction, ALU_out_select == 1, otherwise 0
    begin
      ALU_out_select = 1;
    end
    else
      ALU_out_select = 0;
  end

  assign Rreg_sig1 = instr[9:7]; //3-bits for source-1 register
  assign Rreg_sig2 = instr[12:10]; //next 3-bits for source-2 register
  assign Wreg_sig = instr[6:4]; //3-bits for destination register
  assign opcode = instr[3:0]; //opcode slicing

endmodule
