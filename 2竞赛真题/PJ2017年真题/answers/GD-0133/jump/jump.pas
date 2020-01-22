var
  n,d,k,i,max:longint;
  a:array[0..501,1..2] of longint;
begin
 assign(input,'jump.in');reset(input);
 assign(output,'jump.out');rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
   begin
   readln(a[i,1],a[i,2]);
   if a[i,2]>0 then max:=max+a[i,2];
   end;
  if max<k then begin
                 writeln('-1');
                 close(input);
                 close(output);
                 halt;
                end;
  if d=1 then writeln('0');
  close(input);
  close(output);
end.