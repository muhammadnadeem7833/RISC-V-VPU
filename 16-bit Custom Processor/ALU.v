module ALU(in1,in2,out,con_sig,hi,lo);
  input [15:0] in1;
  input [15:0] in2;
  input [2:0] con_sig;
  output reg [15:0] out;
  output reg [15:0] hi;
  output reg [15:0] lo;

  always @(*)
  begin
    case(con_sig)
    3'b000: out = in1 + in2;
    3'b001: out = in1 - in2;
    3'b010: {hi,lo} = in1 * in2;
    3'b011: out = in1 / in2;
    3'b100: out = in1 & in2;
    3'b101: out = in1 | in2; 
    endcase
  end

endmodule
