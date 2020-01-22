var i,j,k:real;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);
  read(i,j,k);
  k:=i*0.2+j*0.3+k*0.5;
  write(k:0:0);
  close(input);
  close(output);
end.
