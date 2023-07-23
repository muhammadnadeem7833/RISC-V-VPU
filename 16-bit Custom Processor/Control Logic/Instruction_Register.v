module IR(in_instr, clk, rstn, out_instr);
  input [15:0] in_instr; //instruction from ROM
  input clk, rstn;
  
  output [15:0] out_instr; //output wire of 16-bit instruction
  reg [15:0] out_instr;

  always @(posedge clk or negedge rstn) //run on positive edge of every clock cycle
  begin
    if(!rstn)        //if reset == 0, reset registr value
      out_instr <= 0;
    else
      out_instr <= in_instr; //making memory
  end

endmodule
