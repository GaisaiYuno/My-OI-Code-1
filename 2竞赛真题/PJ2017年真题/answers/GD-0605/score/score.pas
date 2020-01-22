var
  x,y,z,i,j,k,n,m:longint;
begin
  assign(input,'score.in'); reset(input);
  assign(output,'score.out'); rewrite(output);
  readln(x,y,z);
  x:=(x div 10)*2;
  y:=(y div 10)*3;
  z:=(z div 10)*5;
  x:=x+y+z;
  writeln(x);
  close(input);
  close(output);
end.
