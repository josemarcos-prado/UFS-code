module somador_estrutural(
	output S,
	output Cout,
	input A,
	input B,
	input Cin);

	wire w0, w1 ,w2;
	xor x1(w0, A, B);
	xor x2(S, w0, Cin);
	and a1(w1, w0, Cin);
	and a2(w2, A, B);
	or o(Cout, w1, w2);
endmodule
