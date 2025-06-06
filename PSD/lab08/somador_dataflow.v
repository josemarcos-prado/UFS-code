module somador_dataflow(
	output S,
	output Cout,
	input A,
	input B,
	input Cin);

	assign S = A ^ B ^ Cin;
	assign Cout = A & B | Cin & (A ^ B);
endmodule
