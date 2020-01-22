var
n,q,s,ss,i,j,k,m:longint;
a,b,c,d:array[1..1000] of longint;
begin
assign(input,'librarian.in');reset(input);
assign(output,'librarian.out');rewrite(output);
  readln(n,q);
  for i:=1 to q do d[i]:=-1;
  ss:=1;
  for i:=1 to n do readln(a[i]);
  for i:=1 to q do readln(c[i],b[i]);
  for i:=1 to q do
    for j:=1 to n do
    begin
      s:=a[j]-b[i];
        for k:=1 to c[i] do ss:=ss*10;
          if s mod ss=0 then
          begin
            if d[i]=-1 then d[i]:=a[j];
            if d[i] > a[j] then d[i]:=a[j];
          end;
          ss:=1;
    end;
    for i:=1 to q do writeln(d[i]);
close(input);
close(output);
end.
