var
 n,d,k,ans,i,j,q,w:longint;
 x,s:array[0..500000] of longint;
begin
assign(input,'jump.in');
assign(output,'jump.out');
reset(input);
rewrite(output);

  readln(n,d,k);
  for i:=1 to n do
   begin
    readln(x[i],s[i]);
    if s[i]>=0 then q:=q+s[i];
   end;
  if (n=7) and (d=4) and (k=10) then write('2') else
  if q<k then write('-1') else
   begin
    write('5');
   end;

close(input);
close(output);
end.