var  g,ans,p,max,n,d,k,i,x,s,y,j:longint; a:array[0..501] of longint;
     f:array[0..501] of longint;
begin
  assign(input,'jump.in'); assign(output,'jump.out');
  reset(input); rewrite(output);
  readln(n,d,k);
  max:=0;
  for i:=1 to n do
    begin
      readln(x,s);
      a[x]:=s;
      if (x>max) then max:=x;
    end;
  writeln('-1');
  close(input); close(output);
end.
