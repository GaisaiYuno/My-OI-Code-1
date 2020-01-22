var
 a:array[1..1000]of string;
 s,ss,ans,maxs:string;
 i,j,n,m,x,l,num:longint;
 b:boolean;
 function min(s1,s2:string):string;
  var i:longint;
 begin
  if length(s1)>length(s2)then exit(s2);
  if length(s2)>length(s1)then exit(s1);
  for i:=1 to length(s1) do
   begin
    if s1[i]>s2[i] then exit(s2);
    if s2[i]>s1[i] then  exit(s1);
   end;
 end;
begin
 assign(input,'librarian.in');
 assign(output,'librarian.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to n do
 begin
  readln(a[i]);
  if min(a[i],maxs)=maxs then maxs:=a[i];
 end;
 for i:=1 to m do
 begin
  b:=false;
  ans:=maxs;
  readln(l,x);
  str(x,s);
  for j:=1 to n do
   if l<=length(a[j]) then
   begin
    num:=length(a[j])-l+1;
    ss:=copy(a[j],num,l);
    if (ss=s) then
    begin
     b:=true;
     if min(ans,a[j])=a[j] then ans:=a[j];
    end;
   end;
  if b then writeln(ans) else writeln(-1);
 end;
 close(input);
 close(output);
end.
