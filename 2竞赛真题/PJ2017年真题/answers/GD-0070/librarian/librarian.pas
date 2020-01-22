var
  n,m,i,j,k,g,r,s,p:longint;
  a:array[1..1001] of longint;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
      readln(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if a[j]<a[i]
           then begin
                g:=a[i];
                a[i]:=a[j];
                a[j]:=g;
                end;
      end;
  for i:=1 to m do
    begin
      readln(r,s);
      p:=0;
      g:=1;
      for k:=1 to r do
          g:=g*10;
      for j:=1 to n do
        begin
          if (a[j] mod g)=s
             then begin
                  writeln(a[j]);
                  p:=1;
                  break;
                  end;
        end;
      if p=0
         then writeln('-1');
    end;
  close(input);
  close(output);
end.
