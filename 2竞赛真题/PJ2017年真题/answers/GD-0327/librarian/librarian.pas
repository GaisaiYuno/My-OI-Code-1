var	n,m,i,j,k,l,ki:longint;
	a,b,c,d,e:array[0..1001]of longint;
function kp(x,y:longint):longint;
var     i,j,mid,p:longint;
begin
        i:=x;
        j:=y;
        mid :=a[(x+y) div 2];
        while (j>i) do
        begin
                while a[i]<mid do inc(i);
                while a[j]>mid do dec(j);
                if j>=i then
                begin
                        a[0]:=a[i];
                        a[i]:=a[j];
                        a[j]:=a[0];
                        inc(i);
                        dec(j);
                end;
        end;
        if y>i then p:=kp(i,y);
        if j>x then p:=kp(x,j);
        exit(0);
end;
begin
	assign(input,'librarian.in');reset(input);
	assign(output,'librarian.out');rewrite(output);
        read(n,m);
        for i:=1 to n do
        read(a[i]);
        for i:=1 to m do
        read(b[i],c[i]);
        ki:=kp(1,n);
        d[0]:=1;
	for i:=1 to 9 do
	d[i]:=d[i-1]*10;
	for i:=1 to m do
	begin
		for j:=1 to n+1 do
		begin
			if j=n+1 then 
			begin
				e[i]:=-1;
				break;
			end;
			if a[j] mod d[b[i]]=c[i] then
			begin
				e[i]:=a[j];
				break;
			end;
		end;
	end;
	for i:=1 to m do
	writeln(e[i]);
        close(input);close(output);
end.
