var i,j,k,ans:longint;

begin
    assign(input,'score.in');reset(input);
    assign(output,'score.out');rewrite(output);
	readln(i,j,k);
	ans:=i div 10*2+j div 10*3+k div 10*5;
	writeln(ans);
	close(input);
	close(output);
end.
