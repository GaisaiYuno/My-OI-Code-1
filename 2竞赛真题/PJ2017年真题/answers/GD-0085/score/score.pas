var a,b,c:integer;
begin
  assign(input,'score.in');
  assign(output,'score.out');
  reset(input);
  rewrite(output); 
  read(a,b,c);
  writeln(trunc(a*0.2)+trunc(b*0.3)+trunc(c*0.5));
  close(input);
  close(output);
end.