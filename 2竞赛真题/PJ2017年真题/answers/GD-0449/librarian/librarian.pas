var
n,q,i,j,s:longint;
a:array[1..1000]of string;
b:array[1..1000]of string;
c:array[1..1000]of longint;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
read(n,q);
for i:=1 to n do
begin
read(a[i]);
readln;
end;
for i:=1 to q do
begin
readln(s,b[i]);
for j:=(length(a[i])) downto s do
if b[s]=a[j]   then
begin
s:=s-1;
break;
  end else writeln('-1');  end;
close(input);
close(output);
  end.


