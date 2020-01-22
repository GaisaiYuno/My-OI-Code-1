var m,n,i,x,y,cd:integer;
    map:array[0..101,0..101] of integer;
    ok:array[0..101,0..101] of boolean;
    cost:array[0..101,0..101] of longint;
    c:array[0..10001,1..2] of longint;
    walk:array[1..4,1..2] of integer;
    can:array[0..101,0..101] of boolean;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  walk[1,1]:=0;
  walk[1,2]:=1;
  walk[2,1]:=0;
  walk[2,2]:=-1;
  walk[3,1]:=1;
  walk[3,2]:=0;
  walk[4,1]:=-1;
  walk[4,2]:=0;
  readln(m,n);
  for i:=1 to n do
    begin
      readln(x,y,cd);
      if cd=0 then map[x,y]:=2 else map[x,y]:=1;
    end;
  x:=1;
  y:=1;
  c[1,1]:=1;
  c[1,2]:=1;
  cost[1,1]:=0;
  ok[1,1]:=true;
  repeat
    for i:=1 to 4 do
      begin
        if (c[x,1]+walk[i,1]<=m)and (c[x,1]+walk[i,1]>=1) and (c[x,2]+walk[i,2]>=1) and (c[x,2]+walk[i,2]<=m) and (ok[c[x,1]+walk[i,1],c[x,2]+walk[i,2]]=false) then
          begin
            inc(y);
            c[y,1]:=c[x,1]+walk[i,1];
            c[y,2]:=c[x,2]+walk[i,2];
            ok[c[y,1],c[y,2]]:=true;
            if map[c[x,1]+walk[i,1],c[x,2]+walk[i,2]]=0 then
              begin
                if can[c[x,1],c[x,2]]=true then
                  begin
                    ok[c[y,1],c[y,2]]:=false;
                    c[y,1]:=0;
                    c[y,2]:=0;
                    dec(y);
                  end
                  else
                  begin
                    cost[c[y,1],c[y,2]]:=cost[c[x,1],c[x,2]]+2;
                    map[c[y,1],c[y,2]]:=map[c[x,1],c[x,2]];
                    can[c[y,1],c[y,2]]:=true;
                  end
              end
              else
            if map[c[x,1]+walk[i,1],c[x][2]+walk[i,2]]=map[c[x,1],c[x,2]] then
              begin
                cost[c[y,1],c[y,2]]:=cost[c[x,1],c[x,2]];
              end
              else
              begin
                cost[c[y,1],c[y,2]]:=cost[c[x,1],c[x,2]]+1;
              end;
          end;
      end;
    inc(x);
  until x>y;
  if ok[m,m] then writeln(cost[m,m]) else writeln(-1);
  close(input);
  close(output);
end.
