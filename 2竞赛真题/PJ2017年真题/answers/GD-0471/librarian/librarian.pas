var
  i,j,k,n,q,x,y,max:longint;
  s:string;
  check:boolean;
  a:array[1..8,1..1000]of string;
  b:array[1..8]of longint;
function cl(s1,s2:string):boolean;
 var
  i,j,k,l1,l2:longint;
 begin
  l1:=length(s1);l2:=length(s2);
  while (l1>0)and(l2>0) do
   begin
    if s1[l1]<>s2[l2] then exit(false);
    dec(l1);dec(l2);
   end;
  exit(true);
 end;
begin
  assign(input,'librarian.in');reset(input);
  assign(output,'librarian.out');rewrite(output);
  readln(n,q);max:=0;
  for i:=1 to n do
   begin
    readln(s);
    k:=length(s);
    if k>max then max:=k;
    inc(b[k]);
    a[k,b[k]]:=s;;
   end;
  for i:=1 to 8 do
   for j:=1 to b[i]-1 do
    for k:=j+1 to b[i] do
     if a[i,j]>a[i,k] then
      begin
       s:=a[i,j];a[i,j]:=a[i,k];a[i,k]:=s;
      end;
  for i:=1 to q do
   begin
    readln(x,s);delete(s,1,1);
    y:=length(s);check:=true;
    for j:=y to max do
     begin
      if check=false then break;
      for k:=1 to b[j] do
       begin
        if (j=y)and(a[j,k]=s) then
         begin writeln(a[j,k]);check:=false;break;end;
        if cl(a[j,k],s) then
         begin writeln(a[j,k]);check:=false;break;end;
       end;
     end;
    if check then writeln(-1);
   end;
  close(input);close(output);
end.