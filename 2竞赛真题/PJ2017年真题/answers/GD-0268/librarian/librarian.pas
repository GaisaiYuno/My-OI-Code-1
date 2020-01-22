program librarian;
var
	book : array[1..1000]of longint;
	i, j, k, ta, tb, n, q, g, min : longint;
	flag : boolean;
	s : string;
begin
	assign(input,'librarian.in');
	assign(output,'librarian.out');
	reset(input);
	rewrite(output);
	read(n,q);
	for i:=1 to n do
		readln(book[i]);
	for i:=1 to q do
	begin
		readln(s);
		for j:=1 to length(s) do
			if s[j]=' ' then break;
		delete(s, 1, j);
		val(s, g);
		min := maxlongint;
		for j:=1 to n do
		begin
			ta:=g;
			tb:=book[j];
			flag:=true;
			while (ta<>0) and (tb<>0) do
			begin
				if (ta mod 10)<>(tb mod 10) then
					begin
						flag:=false;
						break;
					end;
				ta:=ta div 10;
				tb:=tb div 10;
			end;
			if ta<>0 then continue;
			if (book[j]<min) and flag then min:=book[j];
		end;
		if min<>maxlongint then writeln(min) else writeln(-1);
	end;
	close(input);
	close(output);
end.
