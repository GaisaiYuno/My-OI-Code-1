program librarian;
var
  i,j,k,n,m,q,sum:longint;
  a,b,c,d:array[0..100000000] of longint;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to m do
    readln(b[i],c[i]);
  for i:=1 to m do
  begin
    sum:=100000000;
    for j:=1 to n do
    begin
      q:=a[j];
      for k:=1 to b[i] do
      begin
        d[k]:=q mod 10;
        q:=q div 10;
      end;
      q:=0;
      for k:=b[i] downto 1 do
        q:=q*10+d[k];
      if q=c[i] then
        if a[j]<sum then sum:=a[j];
    end;
    if sum=100000000 then writeln('-1')
                     else writeln(sum);
  end;
  close(input);
  close(output);
end.
