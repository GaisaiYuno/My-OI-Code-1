var
  i,j,k,m,n,a,b,c:longint;
  f,r:array[0..1002,0..1002]of longint;
  p,l:array[1..4]of longint;
  t:boolean;

  procedure work(x,y,t,x1,y1:longint);
  var i,j,k:longint;
  begin
   if (x<=0)or(y<=0)or(x>m)or(y>m) then exit;
   for i:=1 to 4 do
    begin
    if(f[x,y]=f[x+p[i],y+l[i]])and(r[x+p[i],y+l[i]]>r[x,y])then begin
                                                                     r[x+p[i],y+l[i]]:=r[x,y];
                                                                     if (x+p[i]<>x)and(y+l[i]<>y)then work(x+p[i],y+l[i],1,x,y);
                                                                    end
       else if f[x+p[i],y+l[i]]>0 then begin
                                        r[x+p[i],y+l[i]]:=r[x,y]+1;
                                        if (x+p[i]<>x)and(y+l[i]<>y)then work(x+p[i],y+l[i],1,x,y);
                                       end
         else if t=1 then begin
                           r[x+p[i],y+l[i]]:=r[x,y]+2;
                           if (x+p[i]<>x)and(y+l[i]<>y)then work(x+p[i],y+l[i],0,x,y);
                          end
    end;

  end;

begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
p[1]:=0;l[1]:=1;
p[2]:=0;l[2]:=-1;
p[3]:=1;l[3]:=0;
p[4]:=-1;l[4]:=0;
t:=true;
 readln(m,n);
for i:=1 to m do
  for j:=1 to m do r[i,j]:=maxlongint;
r[1,1]:=0;
 for i:=1 to n do
   begin
    read(a,b,c);
    if c=0 then f[a,b]:=2;
   end;
  work(1,1,1,1,1);

 if r[m,n]<>maxlongint then write(r[m,n])
  else write(-1);
close(input);close(output);
end.
