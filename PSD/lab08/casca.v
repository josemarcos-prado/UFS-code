 module casca (
	input[0:7]SW,
	output[0:4]LEDG);
	
	somador4 s (
		.A0(SW[0]),
		.A1(SW[1]),
		.A2(SW[2]),
		.A3(SW[3]),
		.B0(SW[4]),
		.B1(SW[5]),
		.B2(SW[6]),
		.B3(SW[7]),
		.S0(LEDG[0]),
		.S1(LEDG[1]),
		.S2(LEDG[2]),
		.S3(LEDG[3]),
		.S4(LEDG[4]));
endmodule
