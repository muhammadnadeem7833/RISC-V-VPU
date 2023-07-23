module MUX_3(Rd_select, MUX_02_res, Ext_Immed_Addr, out);
  input Rd_select; //select line
  input [15:0] MUX_02_res, Ext_Immed_Addr; //2 options for MUX

  output [15:0] out; //result of MUX
  reg [15:0] out;

  always @(*)
  begin
    if(Rd_select)  //if select line == 1, immediate value will go
      out = Ext_Immed_Addr;  
    else
      out = MUX_02_res; //if select line == 0, MUX-02 result will go
  end

endmodule
