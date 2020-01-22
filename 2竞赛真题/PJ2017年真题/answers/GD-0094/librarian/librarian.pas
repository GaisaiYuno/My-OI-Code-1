var f:array[0..10000] of longint;
	n,q,l,a,i,j:longint;
	s,s1:string;
	p:boolean;

procedure sort(l,r:longint);
var i,j,mid:longint;
begin
	i:=l;
	j:=r;
	mid:=f[(i+j) div 2];
	while i<=j do begin
		while (f[i]<mid) do inc(i);
		while (f[j]>mid) do dec(j);
		if i<=j then begin
			f[0]:=f[i];
			f[i]:=f[j];
			f[j]:=f[0];
			inc(i);dec(j);
		end;
	end;
	if i<r then sort(i,r);
	if l<j then sort(l,j);
end;

begin
	assign(input,'librarian.in');reset(input);
	assign(output,'librarian.out');rewrite(output);
	readln(n,q);
	for i:=1 to n do readln(f[i]);
	sort(1,n);
	for i:=1 to q do begin
		readln(l,a);
		p:=false;
		for j:=1 to n do begin
			str(f[j],s);
			str(a,s1);
			if length(s1)>length(s) then continue;
			s:=copy(s,length(s)-length(s1)+1,length(s1));
			if s=s1 then begin
				writeln(f[j]);
				p:=true;
				break;
			end;
		end;
		if p=false then writeln('-1');
	end;
	close(input);
	close(output);
end.
