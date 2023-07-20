module Bits_E(in, out);
  input [5:0] in; //6-bit immediate address
  output [15:0] out; //16-bit output address for ALU

  assign out = {10'd0 , in}; //16-bit extended output

endmodule
