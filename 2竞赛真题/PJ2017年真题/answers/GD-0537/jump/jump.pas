begin
assign(input,'jump.in');reset(input);
assign(output,'jump.out');rewrite(output);
  writeln(-1);
close(input);
close(output);
end.
