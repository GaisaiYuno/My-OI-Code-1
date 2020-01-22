var i,j,m,n,x,y,b,money,xx:longint;
    boo:boolean;
    a:array[0..110,0..110]of longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  for i:=0 to 110 do
    for j:=0 to 110 do
      a[i,j]:=2;
  readln(m,n);
  for i:=1 to n do
    begin
      readln(x,y,b);
      a[x,y]:=b;
    end;
  {for i:=1 to m do
    begin
    for j:=1 to m do
      write(a[i,j],' ');
    writeln;
    end;}
  x:=1; y:=1; money:=0;
  while (true) do
    begin
      boo:=true;
      if a[x,y]=1 then xx:=0
                  else xx:=1;
      if a[x,y+1]=a[x,y] then begin y:=y+1; boo:=false; end
                         else
      if a[x+1,y]=a[x,y] then begin x:=x+1; boo:=false; end
                         else
      if a[x,y+1]=xx then begin y:=y+1; money:=money+1; boo:=false; end
                         else
      if a[x+1,y]=xx then begin x:=x+1; money:=money+1; boo:=false; end
                         else
      if a[x,y+2]<>2 then
            begin
              y:=y+2; money:=money+2;
              if a[x,y]=xx then money:=money+1;
              boo:=false;
            end
                     else
      if a[x+1,y+1]<>2 then
            begin
              x:=x+1; y:=y+1; money:=money+2;
              if a[x,y]=xx then money:=money+1;
              boo:=false;
            end
                       else
      if a[x+2,y]<>2 then
            begin
              x:=x+2; money:=money+2;
              if a[x,y]=xx then money:=money+1;
              boo:=false;
            end;
      if (x>=m)or(y>=m)or(boo) then break;
    end;
  if (x=m)and(y=m)then writeln(money)
                  else writeln(-1);
  close(input);
  close(output);
end.
