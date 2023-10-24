module VALU(ALU_A, ALU_B, ALU_ans, ALU_op);

	input [31:0] ALU_A, ALU_B;  //ALU operands from Operand-Queues
	input [2:0] ALU_op;  //ALU operation from ALU-operation-Queue
	output reg [31:0] ALU_ans;  //ALU-result
	
	always @(*)
	begin
		if(ALU_op == 0)
			ALU_ans = ALU_A + ALU_B;  //elemrnts' addition
		else if(ALU_op == 1)
			ALU_ans = ALU_A - ALU_B;  //elemrnts' subtraction
		else if(ALU_op == 2)
			ALU_ans = ALU_A & ALU_B;  //elemrnts' AND operation
		else if(ALU_op == 3)
			ALU_ans = ALU_A | ALU_B;  //elemrnts' OR operation
		else if(ALU_op == 4)
			ALU_ans = ALU_A ^ ALU_B;  //elemrnts' XOR operation
		else
			ALU_ans = -1;
	end	    
endmodule 