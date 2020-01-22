var a,f:array[-11..1111,-11..1111] of longint;
    b:array[-11..1111,-11..1111] of boolean;
    n,m,i,j,t1,t2,x,y,z:longint;
function min(x,y:longint):longint;
begin
  if x>y then exit(y) else exit(x);
end;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);

  read(n,m);
  for i:=1 to n do for j:=1 to n do a[i,j]:=-1;
  fillchar(b,sizeof(b),false);
  for i:=1 to m do
  begin
    read(x,y,z);
    a[x,y]:=z; b[x,y]:=true;
  end;
  fillchar(f,sizeof(f),$7f div 3);
  f[1,1]:=0;
  for i:=1 to n do for j:=1 to n do if (i<>1)or(j<>1) then
  begin
    t1:=maxlongint div 3; t2:=t1;
    case a[i,j] of
      -1:
      begin
        if b[i-1,j] then t1:=f[i-1,j]+2;
        if b[i,j-1] then t2:=f[i,j-1]+2;
        if t1<t2 then
        begin
          a[i,j]:=a[i-1,j];
          f[i,j]:=t1;
        end else
        if t1>t2 then
        begin
          a[i,j]:=a[i,j-1];
          f[i,j]:=t2;
        end else
        if t1=t2 then
        begin
          if a[i-1,j]<>a[i,j-1] then a[i,j]:=2 else
          a[i,j]:=a[i-1,j];
          f[i,j]:=t1;
        end;
      end;
      0,1:
      begin
        if (a[i-1,j]<>2)and(a[i-1,j]<>a[i,j]) then
          t1:=f[i-1,j]+1 else t1:=f[i-1,j];
        if (a[i,j-1]<>2)and(a[i,j-1]<>a[i,j]) then
          t2:=f[i,j-1]+1 else t2:=f[i,j-1];
        f[i,j]:=min(t1,t2);
      end;
    end;
  end;
  if f[n,n]>=n*n*2 then write(-1) else write(f[n,n]);

  close(input); close(output);
end.
























