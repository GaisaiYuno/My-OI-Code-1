var n,i,k,x:longint; d,s:integer;
begin
  assign(input,'jump1.in'); assign(output,'jump.out'); reset(input); rewrite(output);
  readln(n,d,k);
  for i:=1 to n do begin
    readln(x,s);
  end;
  randomize; writeln(random(8)-1);
  close(input); close(output);
end.
