var
  n,q,i,j,min,k,t,g,p:longint;
  a:array[0..1200]of longint;
  s,s1:string;
  c:char;
begin
assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);
  readln(n,q);
  for i:=1 to n do
  readln(a[i]);
  for j:=1 to q do
  begin
    readln(k,c,s);
    min:=maxlongint;
    for i:=1 to n do
    begin
      str(a[i],s1);
      if copy(s1,length(s1)-k+1,k)=s then if a[i]<min then min:=a[i];
    end;
    if min<maxlongint then writeln(min) else writeln(-1);
  end;
close(input);
close(output);
end.
