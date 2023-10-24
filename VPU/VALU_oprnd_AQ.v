module VALU_AQ(clk, rstn, Write, Read, Oprnd_A, DataOut);

	input clk, rstn, Read, Write;
	input [31:0] Oprnd_A;  //ALU result
	output reg [31:0] DataOut;  //Dequeue Data
	integer i;
	integer EnQ_index = 0;  //available index to enqueue element
	
	reg [31:0] Queue[0:4];  //Queue array

	always@(posedge clk or negedge rstn)
	begin
		if(!rstn)
		begin
			for(i = 0; i<5; i=i+1)
				Queue[i] = -1;  // '-1' indicates empty location
		end
		else
		begin
			if(Write)
			begin
				Queue[EnQ_index] <= Oprnd_A;
				EnQ_index = EnQ_index + 1;
			end
			else if(Read)
			begin
				DataOut = Queue[0];  // FIFO
				//----Shifting each element one index backward----\\
				//begin
				for(i = 0; i<4; i=i+1)	
					Queue[i] <= Queue[i+1];
				Queue[4] = -1;		
				//end
				EnQ_index = EnQ_index - 1;
			end
		end
	end

endmodule
