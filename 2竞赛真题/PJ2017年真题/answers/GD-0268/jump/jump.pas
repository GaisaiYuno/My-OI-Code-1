program jump;
var
	n, d, k, i, t : longint;
	a : array[1..500000]of longint;
	function check(coin, dist : longint):boolean;
	begin
	end;
begin
	assign(input,'jump.in');
	assign(output,'jump.out');
	reset(input);
	rewrite(output);
	read(n, d, k);
	for i:=1 to n do
	begin
		read(a[i]);
		if t<k then inc(t, a[i]);
	end;
	if t<k then begin
		write(-1);
		close(input);
		close(output);
	end;
	close(input);
	close(output);
end.
	
