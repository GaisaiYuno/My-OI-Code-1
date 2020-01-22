var
  x,s:array[1..500000]of longint;
  n,d,k,i,j,g,sum,now:longint;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  read(n,d,k);g:=0;sum:=0;now:=0;
  for i:=1 to n do
  begin
    read(x[i],s[i]);
    if g<d then
    begin
      if x[i]-now<d-g then
        while (x[i]-now<d-g) do inc(g)
      else
      if x[i]-now>d+g then
        while (x[i]-now>d+g) do inc(g);
    end
    else
      if g+now+d<x[i] then g:=x[i]-now-d;
    now:=x[i];
    sum:=sum+s[i];
    if sum>=k then
    begin
      writeln(g);
      close(input);close(output);
      exit;
    end;
  end;
  writeln(-1);
  close(output);close(input);
end.

