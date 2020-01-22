type node=record
            x,m:longint;
          end;
var i,ans,j,k,l,m,n,c,h,t,x,y:longint;
    tm:array[-1..4000001,1..5]of longint;
    a:array[0..100,0..100]of longint;
    b:array[0..100,0..100]of node;


function coin(i,j,c,x,y:longint):longint;
begin
  if (a[i,j]=-1)and(a[x,y]=-1) then exit(-1);
  if a[x,y]=-1 then exit(2);
  if c=a[x,y] then exit(0);
  if c<>a[x,y] then exit(1);
end;

function min(i,j:longint):longint;
begin
  if i<j then  exit(i) else exit(j);
end;

begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=1 to m do
      for j:=1 to m do begin
                         a[i,j]:=-1;
                         b[i,j].x:=-1;
                         b[i,j].m:=maxlongint;
                       end;
  for i:=1 to n do readln(x,y,a[x,y]);

  ans:=maxlongint;
  h:=0;t:=1;
  tm[1,1]:=1;tm[1,2]:=1;tm[1,3]:=a[1,1];
  b[1,1].x:=1;b[1,1].m:=0;

  repeat
    inc(h);
    if h=4000001 then h:=1;
    if tm[h,5]=1 then continue;
    x:=tm[h,1];y:=tm[h,2];c:=tm[h,3];
    if (x=m)and(y=m) then continue;

    k:=coin(x,y,c,x+1,y);
    x:=x+1;
    if (k<>-1)and(tm[h,4]+k<b[x,y].m) then begin
                                            l:=b[x,y].x;
                                            tm[l,5]:=1;
                                            inc(t);
                                            if t=4000001 then t:=1;
                                            tm[t,1]:=x;
                                            tm[t,2]:=y;
                                            tm[t,3]:=c;
                                            if k=1 then tm[t,3]:=a[x,y];
                                            tm[t,4]:=tm[h,4]+k;
                                            tm[t,5]:=0;
                                            b[x,y].x:=t;
                                            b[x,y].m:=tm[t,4];
                                            end;
    x:=x-1;

    k:=coin(x,y,c,x-1,y);
    x:=x-1;
    if (k<>-1)and(tm[h,4]+k<b[x,y].m) then begin
                                            l:=b[x,y].x;
                                            tm[l,5]:=1;
                                            inc(t);
                                            if t=4000001 then t:=1;
                                            tm[t,1]:=x;
                                            tm[t,2]:=y;
                                            tm[t,3]:=c;
                                            if k=1 then tm[t,3]:=a[x,y];
                                            tm[t,4]:=tm[h,4]+k;
                                            tm[t,5]:=0;
                                            b[x,y].x:=t;
                                            b[x,y].m:=tm[t,4];
                                            end;
    x:=x+1;

    k:=coin(x,y,c,x,y+1);
    y:=y+1;
    if (k<>-1)and(tm[h,4]+k<b[x,y].m) then begin
                                            l:=b[x,y].x;
                                            tm[l,5]:=1;
                                            inc(t);
                                            if t=4000001 then t:=1;
                                            tm[t,1]:=x;
                                            tm[t,2]:=y;
                                            tm[t,3]:=c;
                                            if k=1 then tm[t,3]:=a[x,y];
                                            tm[t,4]:=tm[h,4]+k;
                                            tm[t,5]:=0;
                                            b[x,y].x:=t;
                                            b[x,y].m:=tm[t,4];
                                            end;
    y:=y-1;

    k:=coin(x,y,c,x,y-1);
    y:=y-1;
    if (k<>-1)and(tm[h,4]+k<b[x,y].m) then begin
                                            l:=b[x,y].x;
                                            tm[l,5]:=1;
                                            inc(t);
                                            if t=4000001 then t:=1;
                                            tm[t,1]:=x;
                                            tm[t,2]:=y;
                                            tm[t,3]:=c;
                                            if k=1 then tm[t,3]:=a[x,y];
                                            tm[t,4]:=tm[h,4]+k;
                                            tm[t,5]:=0;
                                            b[x,y].x:=t;
                                            b[x,y].m:=tm[t,4];
                                            end;
    y:=y+1;

  until h=t;
  if b[m,m].m=maxlongint then writeln(-1)
    else writeln(b[m,m].m);
  close(input);close(output);
end.
