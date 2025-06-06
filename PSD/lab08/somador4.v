module somador4 (
	input A0, 
	input A1, 
	input A2, 
	input A3, 
	input B0, 
	input B1, 
	input B2, 
	input B3,
	output S0, 
	output S1, 
	output S2, 
	output S3, 
	output S4);
	
	wire w0, w1, w2;
	
	somador_dataflow s0(
		.S(S0),
		.Cout(w0),
		.A(A0),
		.B(B0),
		.Cin(0));
		
	somador_dataflow s1(
		.S(S1),
		.Cout(w1),
		.A(A1),
		.B(B1),
		.Cin(w0));
		
	somador_dataflow s2(
		.S(S2),
		.Cout(w2),
		.A(A2),
		.B(B2),
		.Cin(w1));
		
	somador_dataflow s3(
		.S(S3),
		.Cout(S4),
		.A(A3),
		.B(B3),
		.Cin(w2));
endmodule
