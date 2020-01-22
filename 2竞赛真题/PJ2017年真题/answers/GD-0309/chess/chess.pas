var a,s,d,q,w,e,min:longint;
    f:array[1..100,1..100] of longint;
    l:array[1..4,1..2] of longint=((0,1),(1,0),(-1,0),(0,-1));
procedure ss(x,y,dep,o:longint);
var xx,yy,i,t:longint;
    p:boolean;
begin
  if dep>=min then exit;
  if (x=a) and (y=a) then begin
    if min>dep then min:=dep;
  end else begin
    p:=true;
    for i:=1 to 4 do begin
      xx:=x+l[i,1];
      yy:=y+l[i,2];
      if (xx>0)and(xx<=a)and(yy>0)and(yy<=a)and(f[xx,yy]<>0)and
      (f[xx,yy]<>9) then begin
        t:=f[x,y];
        f[x,y]:=9;
        p:=false;
        if f[xx,yy]<>t then ss(xx,yy,dep+1,0) else ss(xx,yy,dep,0);
        f[x,y]:=t;
      end;
    end;
    if (p) and (o=0) then begin
      for i:=1 to 4 do begin
        xx:=x+l[i,1];
        yy:=y+l[i,2];
        if (xx>0)and(xx<=a)and(yy>0)and(yy<=a)and(f[xx,yy]=0) then begin
          f[xx,yy]:=f[x,y];
          ss(xx,yy,dep+2,1);
          f[xx,yy]:=0;
        end;
      end;
    end;
  end;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(a,s);
  for d:=1 to s do begin
    readln(q,w,e);
    f[q,w]:=e+1;
  end;
  min:=100000;
  ss(1,1,0,0);
  if min=100000 then writeln(-1)
  else writeln(min);
  close(input);
  close(output);
end.
