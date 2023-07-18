module tb_CL01();
  reg clk, rstn;
  wire instr_addr;

  Control_logic_01 obj_CL01(clk, rstn, instr_addr);

  initial
  begin
    rstn = 0;
    #10
    rstn = 1;
  end

endmodule
