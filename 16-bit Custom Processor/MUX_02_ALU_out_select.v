module MUX_2(ALU_out_Select, ALU_res, Mem_Data, out);
  input ALU_out_Select; //select line
  input [15:0] ALU_res, Mem_Data; //2 options for MUX

  output [15:0] out; //result of MUX

  reg [15:0] out;

  always @(*)
  begin
    if(ALU_out_Select)  //if select line == 1, memory data will go
      out = Mem_Data;  
    else
      out = ALU_res; //if select line == 0, alu result will go
  end

endmodule
