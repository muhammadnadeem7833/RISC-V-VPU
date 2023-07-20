module ALU_CON(opcode, signal);
  input [3:0] opcode; //4-bit opcode as input
  output [1:0] signal; //2-bit operation selection signal for ALU

  reg [1:0] signal;

  always @(*)
  begin
    if(opcode == 4'b0011) //if or instruction
      signal = 2'b11;	
    else if(opcode == 4'b0100) //if and instruction
      signal = 2'b10;	
    else if(opcode == 4'b1010) //if mul instruction
      signal = 2'b01;
    else  //otherwise ALU performs addition
      signal = 2'b00;	
  end

endmodule
