var a,s,d,f,g,h,j:longint;

    z,c:array[1..50000]of longint;
procedure pp(x,y,m,n,i:longint);
var q,w,e,r:longint;
begin
 if y>d then begin if (i<j)and(i>0) then j:=i; end
        else begin
  for q:=x to a do
  begin
   if q<>x then begin
    e:=z[q]-z[x];
    if (e>=m)and(e<=n) then pp(q,y+c[q],m,n,i)
                                       else begin
           if e<m then begin w:=m-e;pp(q,y+c[q],m-w,n+w,i+w);end;
           if e>n then begin w:=n-e;pp(q,y+c[q],m-w,n+w,i+w);end;
                                            end;
  end;
                end;
                end;
end;
begin
 assign(input,'jump.in');
 assign(output,'jump.out');
 reset(input);
 rewrite(output);
 j:=1000000000;
 readln(a,s,d);
 for f:=1 to a do
 begin
  readln(z[f],c[f]);
  if c[f]>0 then g:=g+c[f];
 end;
 if d>g then begin writeln('-1');exit;end;
 pp(1,0,s,s,0);
 writeln(j);
 close(input);
 close(output);
end.