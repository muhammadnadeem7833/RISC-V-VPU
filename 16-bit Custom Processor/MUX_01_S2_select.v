module MUX_1(Source2_select, Dout2, Ext_Immed_Addr, out);
  input Source2_select; //select line
  input [15:0] Dout2, Ext_Immed_Addr; //2 options for MUX

  output [15:0] out; //result of MUX

  reg [15:0] out;

  always @(*)
  begin
    if(Source2_select)  //if select line == 1, immediate address will go
      out = Ext_Immed_Addr;  
    else
      out = Dout2; //if select line == 0, source-2 Data will go
  end

endmodule
