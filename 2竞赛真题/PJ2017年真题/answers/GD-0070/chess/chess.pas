var
  a,b:array[0..101,0..101] of longint;
  n,m,i,j,x,y,k,h,x1,y1,p,nh:longint;
function s(v,t:longint):longint;
begin
  if t=2
     then s:=2
      else if v<>t
              then s:=1
               else if v=t
                       then s:=0;
end;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  readln(m,n);
  for i:=0 to m+1 do
    for j:=0 to m+1 do
        a[i,j]:=2;
  for i:=1 to n do
    begin
      readln(x,y,k);
      a[x,y]:=k;
    end;
  fillchar(b,sizeof(b),0);
  x:=1; y:=1;
  for i:=0 to m+1 do
    begin
      b[i,m+1]:=1;
      b[m+1,i]:=1;
      b[i,0]:=1;
      b[0,i]:=1;
    end;
  b[1,1]:=1;
  p:=0; nh:=0;
  while (x<m) or (y<m) do
    begin
    if p>0
       then p:=p-1;
    h:=3; x1:=x; y1:=y;
    if b[x-1,y]=0
       then begin
            if s(a[x,y],a[x-1,y])<h
               then begin
                    h:=s(a[x,y],a[x-1,y]);
                    x1:=x-1;
                    y1:=y;
                    end;
            end;
    if b[x,y-1]=0
       then begin
            if s(a[x,y],a[x,y-1])<=h
               then begin
                    h:=s(a[x,y],a[x,y-1]);
                    x1:=x;
                    y1:=y-1;
                    end;
            end;
    if b[x,y+1]=0
       then begin
            if s(a[x,y],a[x,y+1])<=h
               then begin
                    h:=s(a[x,y],a[x,y+1]);
                    x1:=x;
                    y1:=y+1;
                    end;
            end;
    if b[x+1,y]=0
       then begin
            if s(a[x,y],a[x+1,y])<=h
               then begin
                    h:=s(a[x,y],a[x+1,y]);
                    x1:=x+1;
                    y1:=y;
                    end;
            end;
    if (p>0) and (h=2)
       then begin
            writeln('-1');
            close(input);
            close(output);
            exit;
            end;
    nh:=nh+h;
    if h=2
       then begin
            a[x1,y1]:=a[x,y];
            p:=2;
            end;
    x:=x1;
    y:=y1;
    b[x,y]:=1;
    if ((m-1)<=y) and ((m-1)<=x)
       then begin
            nh:=nh+s(a[m,m],a[x,y]);
            break;
            end;
    end;
  writeln(nh);
  close(input);
  close(output);
end.
