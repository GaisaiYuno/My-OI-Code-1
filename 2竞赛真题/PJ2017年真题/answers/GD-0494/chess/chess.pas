var n,m,i,j,x,y,s,ans,t:longint;
    a:array[1..10000,1..10000] of longint;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  read(m,n);
  for i:=1 to n do
    for j:=1 to n do
      a[i,j]:=3;
  for i:=1 to n do
    begin
      read(x,y,s);
    a[x,y]:=s;
    end;
  x:=1;
  y:=1;
  while (x<>m)or(y<>m) do
    begin
      if (x=m)and(y=m) then break;
      if (a[x,y+1]<>3)and(a[x,y+1]=a[x,y]) then
      begin
      inc(y);
      t:=0;
      end

      else
      if (a[x+1,y]<>3)and(a[x+1,y]=a[x,y]) then
      begin
      inc(x);
      t:=0;
      end
      else
      if (a[x+1,y]<>3)and(a[x+1,y]<>a[x,y])
      then
      begin
        inc(ans);
        inc(x);
        t:=0;
      end
      else
      if (a[x,y+1]<>3)and(a[x,y+1]<>a[x,y])
      then
      begin
        inc(ans);
        inc(y);
        t:=0;
      end
      else
      if (t=0)and(a[x+1,y]=3)and(a[x,y+1]=3)and(a[x+1,y+1]<>3)
      then
        begin
          t:=1;
          inc(ans,2);
          a[x+1,y]:=a[x+1,y+1];
        end
      else
      if (t=0)and(a[x+1,y]=3)and(a[x,y+1]=3)and(a[x+2,y]<>3)
      then
        begin
          t:=1;
          inc(ans,2);
          a[x+1,y]:=a[x+2,y];
        end
      else
      if (t=0)and(a[x+1,y]=3)and(a[x,y+1]=3)and(a[x,y+2]<>3)
      then
        begin
          t:=1;

          inc(ans,2);
          a[x,y+1]:=a[x,y+2];
        end
      else
      begin
        write(-1);
        exit;
      end;
    end;
  write(ans);
  close(input);
  close(output);
end.