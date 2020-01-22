type new=record
     x,y,time:longint;
     end;
var colour:array[1..100,1..100] of 0..2;
    map,can:array[1..100,1..100] of integer;
    way:array[1..4,1..2] of shortint=((1,0),(0,1),(0,-1),(-1,0));
    que:array[1..1000] of new;
    h,t,x0,y0,n,m,a,b,c1,c2,color,cost:longint;
begin
  assign (input,'chess.in'); reset (input);
  assign(output,'chess.out');rewrite(output);
  read (m,n);
    for a:=1 to n do begin read (x0,y0,color);colour[x0,y0]:=color+1;
      for b:=1 to 4 do begin h:=x0+way[b,1];t:=y0+way[b,2];
      if (h<1) or (t<1) or (h>m) or (t>m) then continue;
      if can[h,t]=0 then inc(can[h,t]);end;
    end;
  h:=1;
  t:=1;
  que[1].x:=1;
  que[1].y:=1;
  map[1,1]:=1;
  que[1].time:=0;
  x0:=1;
  y0:=1;
    while h<=t do begin
      for a:=1 to 4 do begin
      x0:=que[h].x+way[a,1];
      y0:=que[h].y+way[a,2];
        if (x0<1) or (x0>m) or (y0<1) or (y0>m) then continue;
        if can[x0,y0]=0 then continue;
      c1:=colour[que[h].x,que[h].y];
      c2:=colour[x0,y0];
        if c1=0 then if c2=0 then continue else cost:=0;
        if c1=c2 then cost:=0;
        if (c1=1) and (c2=2) or (c1=2) and (c2=1) then cost:=1;
        if (c2=0) and (c2<c1) then cost:=2;
        if (map[x0,y0]>0) and (map[x0,y0]<=map[que[h].x,que[h].y]+cost) then continue else
          begin
          inc(t);
          que[t].x:=x0;
          que[t].y:=y0;
          map[x0,y0]:=map[que[h].x,que[h].y]+cost;
          que[t].time:=map[x0,y0];
          end;
        can[que[h].x,que[h].y]:=0;
      end;
    inc(h);
    end;
    if (abs(m-que[t].x)<2) and (abs(m-que[t].y)<2) then writeln (que[t].time)
    else writeln (-1);
  close (input);
  close(output);
end.
