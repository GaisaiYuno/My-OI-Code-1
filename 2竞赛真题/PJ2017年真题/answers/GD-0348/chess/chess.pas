const
  fx:array [1..6,1..2] of longint=((-1,0),
                                   (1,0),
                                   (0,1),
                                   (0,-1),
                                   (1,1),
                                   (1,-1));
var
  min,m,n,money,i,x,y:longint;
  gezi:array [1..100,1..100] of longint;
  panduan:array [1..100,1..100] of boolean;
procedure dfs(x,y:longint);
var i,j,nx,ny,t:longint;
begin
  if (x=m) and (y=m) then
    begin
      if money<min then
        min:=money;
    end
    else
    begin
    for i:=1 to 4 do
      begin
        nx:=fx[i,1]+x;
        ny:=fx[i,2]+y;
      if (nx>=1) and (ny>=1) and (nx<=m) and (ny<=m) and (gezi[nx,ny]<>0) then
        begin
          t:=0;
          if (gezi[nx,ny]<>gezi[x,y])  then
            inc(money);
            if panduan[x,y] then
              gezi[x,y]:=0
              else
              begin
            t:=gezi[x,y];
            gezi[x,y]:=0;
            end;
            dfs(nx,ny);
            gezi[x,y]:=t;
            if (gezi[nx,ny]<>gezi[x,y])   then
            dec(money);
        end
      end;
    if not panduan[x,y] then
      begin
    for i:=2 to 6 do
      begin
        nx:=fx[i,1]+x;
        ny:=fx[i,2]+y;
      if (nx>=1) and (ny>=1) and (nx<=m) and (ny<=m) and (gezi[nx,ny]<>0)  then
        begin
          money:=money+2;
          panduan[x,y]:=true;
          if (x+1=nx) and (y+1=ny)  then
            begin
                gezi[x,y+1]:=gezi[x,y];
              dfs(x,y+1);
                gezi[x,y+1]:=0;


                gezi[x+1,y]:=gezi[x,y];
              dfs(x+1,y);
                gezi[x+1,y]:=0;


            end;


          if (x+1=nx) and (y-1=ny) then
            begin
              gezi[x+1,y]:=gezi[x,y];
              dfs(x+1,y);
              gezi[x+1,y]:=0;
              gezi[x,y-1]:=gezi[x,y];
              dfs(x,y-1);
              gezi[x,y-1]:=0;
            end;


          money:=money-2;
        end;
      end;
      end;
    end;

end;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  fillchar(gezi,sizeof(gezi),0);
  fillchar(panduan,sizeof(panduan),false);
  readln(m,n);
  for i:=1 to n do
    begin
      read(x,y);
      readln(gezi[x,y]);
      if gezi[x,y]=0 then
      gezi[x,y]:=3;
    end;
  money:=0;
  min:=maxlongint;
  dfs(1,1);
  if min<>maxlongint then
  writeln(min)
  else
  writeln('-1');
  close(input);
  close(output);
end.
