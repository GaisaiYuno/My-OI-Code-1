const
 dx:array[1..4]of longint=(1,0,-1,0);
 dy:array[1..4]of longint=(0,1,0,-1);
var
 a:array[0..101,0..101]of longint;
 v:array[0..101,0..101]of boolean;
 sx,sy:array[0..4]of longint;
 n,m,x,y,c,i,j,ans:longint;
 pp:boolean;
function check(x,y:longint):boolean;
begin
 if (x<1) or (x>m) or (y<1) or (y>m) or (v[x,y]) or (pp) then exit(false);
 exit(true);
end;
procedure pai;
var
 i,j:longint;
begin
 for i:=1 to 3 do
  for j:=i+1 to 4 do
   if ((a[sx[i],sy[i]]<>a[x,y]) and  (a[sx[j],sy[j]]=a[x,y])) or
      ((a[sx[i],sy[i]]=0) and  (a[sx[j],sy[j]]<>0)) then
                                                     begin
                                                      sx[0]:=sx[i];sx[i]:=sx[j];sx[j]:=sx[0];
                                                      sy[0]:=sy[i];sy[i]:=sy[j];sy[j]:=sy[0];
                                                     end;

end;
procedure try(x,y,q:longint;p:boolean);
var
 xx,yy,i:longint;
begin
 if a[1,1]=0 then exit;
 v[x,y]:=true;
 inc(j);
 if j>100000 then pp:=true;
 if (x=m) and (y=m)then
  begin
   if q<ans then ans:=q;
   pp:=true;
   exit;
  end;
 for i:=1 to 4 do
  begin
   sx[i]:=x+dx[i];
   sy[i]:=y+dy[i];
  end;
 pai;
 for i:=1 to 4 do
  begin
   xx:=sx[i];yy:=sy[i];
   if check(xx,yy) then
   if (a[xx,yy]=0) and (p) then
                            begin
                             a[xx,yy]:=a[x,y];
                             try(xx,yy,q+2,false);
                             a[xx,yy]:=0;
                            end
    else if a[xx,yy]=a[x,y] then
                             begin
                              if not(p)then a[x,y]:=0;                              try(xx,yy,q,true);
                             end
     else if a[xx,yy]<>0 then
                          begin
                           if not(p)then a[x,y]:=0;
                           try(xx,yy,q+1,true);
                          end;
   v[xx,yy]:=false;
  end;
end;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
 read(m,n);
 for i:=1 to n do
  begin
   read(x,y,c);
   a[x,y]:=c+1;
  end;
 ans:=maxlongint;
 try(1,1,0,true);
 if ans<>maxlongint then write(ans)
                    else write(-1);
close(input);close(output);
end.
