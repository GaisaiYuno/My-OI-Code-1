var a,b,c,i,j:longint;
    x,y,z,ans:real;
begin
  assign(input,'score.in');reset(input);
  assign(output,'score.out');rewrite(output);
  readln(a,b,c);
  x:=a/5;
  y:=b/10*3;
  z:=c/2;
  ans:=x+y+z;
  write(ans:0:0);
  close(input);
  close(output);
end.
