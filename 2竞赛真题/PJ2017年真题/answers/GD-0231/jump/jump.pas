procedure check(s:array of integer;x,p,n,d,k,g:longint);
var i:longint;
 tout:text;
begin
 if p>=k then
 begin
  assign(tout,'jump.out');
  rewrite(tout);
  write(tout,g);
  exit;
 end;
 if x<n then
 begin
  if g<d then
   for i:=d-g to d+g do
    check(s,x+i,p+s[x+i],n,d,k,g);
  if g>=d then
   for i:=1 to d+g do
    check(s,x+i,p+s[x+i],n,d,k,g);
 end;
end;
var s:array[1..500]of integer;
 x,n,d,k,i,t,g:longint;
 tin,tout:text;
begin
 assign(tin,'jump.in');
 reset(tin);
 assign(tout,'jump.out');
 rewrite(tout);
 read(tin,n,d,k);
 for i:=1 to n do
 begin
  read(tin,x,s[x]);
  if s[x]>0 then t:=t+x;
 end;
 if t<k then
 begin
  write(tout,-1);
  exit;
 end;
 t:=0;
 for t:=0 to n do
  check(s,1,0,n,d,k,t);
end.
