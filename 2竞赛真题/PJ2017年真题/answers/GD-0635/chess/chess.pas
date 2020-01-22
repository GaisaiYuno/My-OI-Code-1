var a:array[-10..110,-10..110] of longint;
    c:array[-10..110,-10..110] of longint;
    x,y:array[0..10100] of longint;
    q:array[-10..110,-10..110] of longint;
    f:array[1..4,1..2] of longint=((-1,0),
                                   (0,1),
                                   (1,0),
                                   (0,-1));
    i,j,k,h,z,s,l,m,n,top,tail:longint;
function pd(xh,yh,xq,yq:longint):boolean;
var j:longint;
begin
  if c[xh,yh]=1 then
  begin
    if q[xq,yq]+2>=q[xh,yh] then exit(false);
    q[xh,yh]:=q[xq,yq]+2;
    a[xh,yh]:=a[xq,yq];
    exit(true);
  end;
  if (a[xh,yh]<2) then
  begin
    if a[xh,yh]=a[xq,yq] then
      j:=0
    else
      j:=1;
  end;
  if a[xh,yh]=2 then
  begin
    if (c[xq,yq]=1) then exit(false);
    if q[xq,yq]+2<q[xh,yh] then
    begin
      a[xh,yh]:=a[xq,yq];
      c[xh,yh]:=1;
    end;
    j:=2;
  end;
  if (q[xq,yq]+j<q[xh,yh]) then
  begin
    q[xh,yh]:=q[xq,yq]+j;
    //writeln(xq,' ',yq,' ',q[xq,yq],'_',xh,' ',yh,' ',q[xh,yh]);
    exit(true)
  end
  else exit(false);
end;
begin
  assign(input,'chess.in'); reset(input);
  assign(output,'chess.out'); rewrite(output);
  readln(m,n);
  for i:=1 to m do
    for j:=1 to m do
      a[i,j]:=2;
  for i:=1 to n do
  begin
    readln(h,z,s);
    a[h,z]:=s;
  end;
  top:=1; tail:=1;
  x[1]:=1; y[1]:=1;
  fillchar(q,sizeof(q),$7f);
  fillchar(c,sizeof(c),0);
  q[1,1]:=0;
  while top<=tail do
  begin
    for i:=1 to 4 do
      if (x[top]+f[i,1]>0)and(x[top]+f[i,1]<=m)and(y[top]+f[i,2]>0)and(y[top]+f[i,2]<=m) then
      //begin
        if pd(x[top]+f[i,1],y[top]+f[i,2],x[top],y[top]) then
        begin
          inc(tail);
          x[tail]:=x[top]+f[i,1];
          y[tail]:=y[top]+f[i,2];
        end;
      //end;
    if c[x[top],y[top]]=1 then
    begin
      a[x[top],y[top]]:=2;
      c[x[top],y[top]]:=0;
    end;
    inc(top);
  end;
  {for i:=1 to tail do
    writeln(x[i],' ',y[i]);}
  if q[m,m]<>2139062143 then write(q[m,m])
    else write(-1);
  close(input); close(output);
end.