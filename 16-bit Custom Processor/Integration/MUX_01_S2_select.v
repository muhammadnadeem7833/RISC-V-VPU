module MUX_1(Source2_select, Dout2, Ext_Immed_Addr, shift_amm, out);
  input [1:0] Source2_select; //select line
  input [15:0] Dout2, Ext_Immed_Addr;
  input [2:0] shift_amm; //3rd input of shift ammount in case of sll or slr

  output [15:0] out; //result of MUX

  reg [15:0] out;

  always @(*)
  begin
    case(Source2_select)
    2'b00: out = Dout2; //if select line == 0, source-2 Data will go
    2'b01: out = Ext_Immed_Addr; //if select line == 1, immediate address will go 
    2'b10: out = shift_amm; //if select line == 2, shift ammount will go
    endcase     
  end

endmodule
