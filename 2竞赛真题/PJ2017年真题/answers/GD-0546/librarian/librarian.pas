var
a : array[0..1000] of longint;
n,i,q,len,num,j,d,ans : longint;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
readln(n,q);
for i := 1 to n do readln(a[i]);
for i := 1 to n-1 do
for j := i+1 to n do
        if a[i]>a[j] then
        begin
                a[0] := a[i];
                a[i] := a[j];
                a[j] := a[0];
        end;
for i := 1 to q do
begin
        ans :=-1;
        readln(len,num);d :=1;
        for j := 1 to len do
        d := d*10;
        for j := 1 to n do
        if (a[j] mod d)=num then
        begin
                ans := a[j];
                break;
        end;
        writeln(ans);
end;
close(input);close(output);
end.
