module IR(in_inst,out_inst,clk);
  input [15:0] in_inst; //instruction from ROM
  input clk;
  output reg [15:0] out_inst; //output register

  always @(posedge clk) //run on positive edge only
  begin
    out_inst <= in_inst; //value assigning(non-blocking statement)
  end
endmodule
