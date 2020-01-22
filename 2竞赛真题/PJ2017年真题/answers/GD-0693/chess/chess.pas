const
  h:array[1..4] of longint=(1,-1,0,0);
  l:array[1..4] of longint=(0,0,1,-1);
  max=1000;
var
  min,n,m,i,j,v,f,q,p:longint;
  a,b:array[1..max,1..max] of longint;

procedure try(k,x,y:longint);
var
  i,j:longint;
begin
  if k>=min then exit;
  if (x=m)and(y=m) then
   begin
    if k<min then min:=k;
    exit;
   end;
  for i:=1 to 4 do
    if (x+h[i]>0)and(x+h[i]<=m)and(y+l[i]>0)and(y+l[i]<=m)and(b[x+h[i],y+l[i]]=0) then
      begin
        b[x+h[i],y+l[i]]:=1;
        if (a[x+h[i],y+l[i]]=0) and (a[x,y]>0) then begin  p:=a[x,y]; try(k+2,x+h[i],y+l[i]); end;
        if (a[x+h[i],y+l[i]]=a[x,y]) and (a[x,y]>0) then try(k,x+h[i],y+l[i]);
        if (a[x+h[i],y+l[i]]<>a[x,y]) and (a[x,y]>0) and (a[x+h[i],y+l[i]]>0) then try(k+1,x+h[i],y+l[i]);
        if (a[x,y]=0) and (a[x+h[i],y+l[i]]>0) then
         begin
          if p=a[x+h[i],y+l[i]] then try(k,x+h[i],y+l[i]);
          if p<>a[x+h[i],y+l[i]] then try(k+1,x+h[i],y+l[i]);
         end;
        b[x+h[i],y+l[i]]:=0;
      end;
end;

begin
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
  readln(m,n);
  min:=maxlongint;
  for i:=1 to n do
   begin
     read(v,f);
     readln(a[v,f]);
     inc(a[v,f]);
   end;
  try(0,1,1);
  if min<maxlongint then writeln(min) else writeln(-1);
close(input);
close(output);
end.























