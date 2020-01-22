var m,n,k,zhong:longint;
begin
  assign(input,'score.in');
  reset(input);
  assign(output,'score.out');
  rewrite(output);

  read(m,n,k);
  zhong:=(m div 10)*2 +(n div 10)*3+(k div 10)*5;
  writeln(zhong);
  close(input);
  close(output);
end.
