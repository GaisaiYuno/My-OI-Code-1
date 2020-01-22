var x,y,z:longint;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  read(x,y,z);
  write((x*2+y*3+z*5) div 10);
  close(input);
  close(output);
end.