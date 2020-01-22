var
 a:array[1..1000]of string;
 n,m,i,k,j,x,y:longint;
 c:char;
 s,ans:string;
begin
 assign(input,'librarian.in');reset(input);
 assign(output,'librarian.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do begin
  readln(a[i]);
 end;
 for i:=1 to m do begin
  readln(k,c,s);
  ans:='99999999';
  for j:=1 to n do begin
   val(a[j],x);
   val(ans,y);
   if(copy(a[j],length(a[j])-k+1,1000)=s)and(x<y)then ans:=a[j];
  end;
  if ans='99999999' then writeln('-1')else writeln(ans);
 end;
end.