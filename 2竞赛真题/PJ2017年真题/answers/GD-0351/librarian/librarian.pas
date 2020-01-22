var
  a,b:array [0..1001] of string;
  f,c:array [0..1001] of longint;
  i,j,n,q,g:longint;
begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,q);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to q do
    begin
      read(c[i]);
      readln(b[i]);
      b[i]:=copy(b[i],2,length(b[i])-1);
    end;
  for i:=1 to q do
    begin
      for j:=1 to n do
        if copy(a[j],length(a[j])-c[i]+1,c[i])=b[i] then
          begin
            val(a[j],g);
            if (f[i]>g) or (f[i]=0) then f[i]:=g;
          end;
      if f[i]>0 then writeln(f[i])
                else writeln('-',1);
    end;
  close(input);
  close(output);
end.
