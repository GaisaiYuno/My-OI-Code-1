var n,k,x,i,a,b,max,max2:longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);
  rewrite(output);
  readln(n,k,x);
  for i:=1 to n do
    begin
      readln(a,b);
      if b>0 then max:=max+b;
      max2:=max2+b;
    end;
  max2:=max2 div 6;
  if max<x then writeln(-1)
           else if max2>0 then writeln(max2)
                          else writeln(max2*(-9)+5);
  close(input);
  close(output);
end.