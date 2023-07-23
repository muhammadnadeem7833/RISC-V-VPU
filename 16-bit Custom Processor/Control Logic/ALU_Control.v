module ALU_CON(opcode, signal);
  input [3:0] opcode; //4-bit opcode as input
  output [2:0] signal; //3-bit operation selection signal for ALU

  reg [2:0] signal;

  always @(*)
  begin
    if(opcode == 4'b0011) //if or instruction
      signal = 3'b011;	
    else if(opcode == 4'b0100) //if and instruction
      signal = 3'b010;	
    else if(opcode == 4'b1010) //if mul instruction
      signal = 3'b001;
    else if(opcode == 4'b0001) //if sll instruction
      signal = 3'b100;
    else if(opcode == 4'b0010) //if slr instruction
      signal = 3'b101;
    else  //otherwise ALU performs addition
      signal = 3'b000;	
  end

endmodule
