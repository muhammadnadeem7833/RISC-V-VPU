module ALU(in1, in2, con_sig, out);
//2 operands of 16-bit
  input [15:0] in1;
  input [15:0] in2;

  input [2:0] con_sig; //operation selection bits
  output [31:0] out; //result

  reg [31:0] out;

  always @(*)
  begin
    case(con_sig)
    2'b000: out = in1 + in2; //addition
    2'b001: out = in1 * in2; //multiplication
    2'b010: out = in1 & in2; //and
    2'b011: out = in1 | in2; //or
    2'b100: out = in1 << in2; //sll
    2'b101: out = in1 >> in2; //slr
    endcase
  end

endmodule
