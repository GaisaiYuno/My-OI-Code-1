program jump(input,output);
var
  n,d,k,i,j,s,r,g,t:longint;
  a,b,c:array[0..30000] of longint;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(n,d,k);t:=0; a[0]:=0;
  for i:=1 to n do
   begin
     readln(a[i],b[i]);
     if b[i]>=0 then begin s:=s+b[i]; c[i]:=1; end
      else begin s:=s+0;c[i]:=0; end;
   end;
  if s<k then write(-1)
   else begin
    i:=0;t:=a[i+1]-a[i];
    write(t);
   end;
  close(input);close(output);
end.