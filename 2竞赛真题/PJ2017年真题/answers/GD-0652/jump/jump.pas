var
 b:boolean;
 i,n,num,d,s,z,x,g:longint;
 a:array[1..500000]of longint;
 procedure dfs(nn,ss:longint);
  var i:longint;
 begin
  if (nn>x) then
  begin
   if ss>=num then b:=true;
   exit;
  end;
  for i:=nn+d+g downto nn+d-g do
   if a[i]>=0 then dfs(i,ss+a[i]);
 end;
procedure readd;
begin
 read(n,d,num);
 for i:=1 to n do
 begin
  read(x,z);
  a[x]:=z;
  s:=s+z;
 end;
end;
begin
 assign(input,'jump.in');
 assign(output,'jump.out');
 reset(input);
 rewrite(output);
 readd;
 if s<num then g:=-1
 else
 begin
  b:=false;
  while b=false do
  begin
   inc(g);
   dfs(0,0);
  end;
 end;
 write(g+1);
 close(input);
 close(output);
end.
