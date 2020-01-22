var
  s,x,y,c,m,n,i,j:longint;
  a:array[0..100,0..100]of longint;
procedure chess(x,y:longint);
var
  i,j:longint;
begin
  if (x=m)and(y=m) then exit;
  if a[x+1,y]<>4 then
  begin
    if (a[x+1,y]<>a[x,y])and(a[x+1,y]<>a[x,y]-5) then inc(s);
    chess(x+1,y);
  end
    else
      if a[x,y+1]<>4 then
        begin
          if (a[x,y+1]<>a[x,y])and(a[x,y+1]<>a[x,y]-5) then inc(s);
          chess(x,y+1);
        end
          else if a[x+1,y]<5 then
                begin
                  s:=s+2;
                  a[x+1,y]:=a[x,y]+5;
                  chess(x+1,y);
                end
                  else if a[x,y+1]<5 then
                    begin
                      s:=s+2;
                      a[x,y+1]:=a[x,y]+5;
                      chess(x,y+1);
                    end
                      else begin s:=-1; exit; end;
end;
begin
  input(input,'chess.in');
  output(output,'chess.out');
  reset(input);
  rewrite(output);
  read(m,n);
  for i:=0 to m+1 do
    for j:=0 to m+1 do
      a[i,j]:=4;
  for i:=1 to n do
  begin
    read(x,y,c);
    a[x,y]:=c;
  end;
  chess(1,1);
  write(s);
  close(input);
  close(output);
end.
