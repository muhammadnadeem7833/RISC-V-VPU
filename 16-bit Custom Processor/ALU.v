module ALU(in1, in2, con_sig, out);
//2 operands of 16-bit
  input [15:0] in1;
  input [15:0] in2;

  input [1:0] con_sig; //operation selection bits
  output [15:0] out; //result

  reg [15:0] out;
  

  always @(*)
  begin
    case(con_sig)
    2'b00: out = in1 + in2; //addition
    //2'b01: out = in1 * in2; //subtraction
    2'b10: out = in1 & in2; //and
    2'b11: out = in1 | in2; //or
    endcase
  end

endmodule
