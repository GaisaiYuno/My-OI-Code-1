var n,i,j,k,l,m:real;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output);
  read(n,i,j);
  write(n*0.2+i*0.3+j*0.5:0:0);
  close(input);
  close(output);
end.