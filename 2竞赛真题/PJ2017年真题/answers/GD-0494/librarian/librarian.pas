var n,m,i,j,t,b,t1,ws,s,x:longint;
    a:array[1..10010] of longint;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  read(n,m);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
      begin
        t:=a[i];
        a[i]:=a[j];
        a[j]:=t;
      end;
  for i:=1 to m do
    begin
      readln(x,b);
      s:=1;
      while (x>0) do
        begin
          dec(x);
          s:=s*10;
        end;
      for j:=1 to n do
        begin
          ws:=a[j] mod s;
          if ws=b then
            begin
              writeln(a[j]);
              inc(t1);
              break;
            end;
        end;
      if t1=0 then writeln(-1);
      t1:=0;
    end;
  close(input);
  close(output)
end.
