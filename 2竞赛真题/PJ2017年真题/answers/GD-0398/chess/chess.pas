const
  sx:array[1..4] of longint=(1,0,-1,0);
  zy:array[1..4] of longint=(0,1,0,-1);
type wz=record
  x,y,lastx,lasty,now,num:longint;
  bo:boolean;
  s:array[1..100,1..100] of boolean;
end;

var
  a:array[0..101,0..101] of longint;
  n,m,i,j,ans,xx,yy,head,tail,nowx,nowy,gox,goy,count:longint;
  d:array[0..5000] of wz;

procedure bfs;
var
  i:longint;
begin
  d[1].x:=1;
  d[1].y:=1;
  d[1].bo:=false;
  d[1].s[1,1]:=true;
  head:=0;
  tail:=1;
  while head<tail do begin
    if tail=5000 then begin
      for i:=1 to head do
       if (d[i].x=m) and (d[i].y=m) then
        if d[i].now<ans then ans:=d[i].now;
      exit;
    end;
    inc(head);
    if (d[head].x=m) and (d[head].y=m) then begin
      if d[head].now<ans then ans:=d[head].now;
      continue;
    end;
    nowx:=d[head].x;
    nowy:=d[head].y;
    d[head].s[nowx,nowy]:=true;
    if (nowx=8) and (nowy=8) then inc(count);
    //if d[head].bo then a[d[head].x,d[head].y]=-1;
    for i:=1 to 4 do begin
      gox:=nowx+sx[i];
      goy:=nowy+zy[i];
      if (gox<1) or (gox>m) or (goy<1) or (goy>m)
      or {(gox=d[head].lastx) and (goy=d[head].lasty)}
      d[head].s[gox,goy] then continue;

      if d[head].bo=true then begin
        if a[gox,goy]=-1 then continue;
        if d[head].num<>a[gox,goy] then begin
          if d[head].now+1<ans then begin
            inc(tail);
            d[tail].x:=gox;
            d[tail].y:=goy;
            d[tail].lastx:=nowx;
            d[tail].lasty:=nowy;
            d[tail].bo:=false;
            d[tail].now:=d[head].now+1;
            d[tail].num:=a[gox,goy];
            d[tail].s:=d[head].s;
            d[tail].s[nowx,nowy]:=true;
             d[tail].s[gox,goy]:=true;
          end;
        end
        else begin
          inc(tail);
          d[tail].x:=gox;
          d[tail].y:=goy;
          d[tail].lastx:=nowx;
          d[tail].lasty:=nowy;
          d[tail].bo:=false;
          d[tail].now:=d[head].now;
          d[tail].num:=a[gox,goy];
           d[tail].s:=d[head].s;
            d[tail].s[nowx,nowy]:=true;
             d[tail].s[gox,goy]:=true;
        end;
      end

      else begin
        if a[gox,goy]=-1 then begin
          if d[head].now+2<ans then begin
            inc(tail);
            d[tail].x:=gox;
            d[tail].y:=goy;
            d[tail].lastx:=nowx;
            d[tail].lasty:=nowy;
            d[tail].bo:=true;
            d[tail].now:=d[head].now+2;
            d[tail].num:=d[head].num;
            d[tail].s:=d[head].s;
            d[tail].s[nowx,nowy]:=true;
             d[tail].s[gox,goy]:=true;
          end;
        end
        else begin
          if d[head].num<>a[gox,goy] then begin
            if d[head].now+1<ans then begin
              inc(tail);
              d[tail].x:=gox;
              d[tail].y:=goy;
              d[tail].lastx:=nowx;
              d[tail].lasty:=nowy;
              d[tail].bo:=false;
              d[tail].now:=d[head].now+1;
              d[tail].num:=a[gox,goy];
              d[tail].s:=d[head].s;
              d[tail].s[nowx,nowy]:=true;
               d[tail].s[gox,goy]:=true;
            end;
          end
          else begin
            inc(tail);
            d[tail].x:=gox;
            d[tail].y:=goy;
            d[tail].lastx:=nowx;
            d[tail].lasty:=nowy;
            d[tail].bo:=false;
            d[tail].now:=d[head].now;
            d[tail].num:=a[gox,goy];
            d[tail].s:=d[head].s;
            d[tail].s[nowx,nowy]:=true;
             d[tail].s[gox,goy]:=true;
          end;
        end;
      end;
    end;
  end;
end;





begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);

  readln(m,n);
  for i:=0 to m+1 do
   for j:=0 to m+1 do
    a[i,j]:=-1;
  for i:=1 to n do
   readln(xx,yy,a[xx,yy]);
  ans:=maxlongint;

  bfs;

  if ans=maxlongint then writeln(-1)
   else writeln(ans);

close(input);close(output);
end.


