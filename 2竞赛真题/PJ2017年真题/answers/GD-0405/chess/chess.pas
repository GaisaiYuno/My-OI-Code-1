VAR i,j,c,u,cc,uu,x,y,xx,yy,front,rear,m,n,count:longint;
    a:array[0..1001,0..1001]of 0..4;
    b:array[0..1001,0..1001]of longint;
    h:array[0..2002,1..4]of longint;
    dx,dy:array[1..4]of -1..1;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  dx[1]:=-1;dx[2]:=1;dx[3]:=0;dx[4]:=0;
  dy[1]:=0;dy[2]:=0;dy[3]:=-1;dy[4]:=1;
  readln(m,n);
  for i:=1 to m do
  begin
    for j:=1 to n do
    begin
      b[i,j]:=maxlongint;
    end;
  end;
  for i:=1 to n do
  begin
    readln(x,y,c);
    if c=0 then
    begin
      a[x,y]:=1;
    end
    else
    begin
      a[x,y]:=2;
    end;
  end;
  front:=0;
  rear:=1;
  h[1,1]:=1;
  h[1,2]:=1;
  h[1,3]:=a[1,1];
  h[1,4]:=0;
  while front<rear do
  begin
    inc(count);
    if count>=m*m*3 div 2 then
    begin
      writeln(-1);
      close(input);
      close(output);
      halt;
    end;
    inc(front);
    x:=h[front,1];
    y:=h[front,2];
    c:=h[front,3];
    u:=h[front,4];
    if (x=5)and(y=5) then
    begin
      break;
    end;
    for i:=1 to 4 do
    begin
      xx:=h[front,1]+dx[i];
      yy:=h[front,2]+dy[i];
      if (xx>=1)and(xx<=m)and(yy>=1)and(yy<=m) then
      begin
        cc:=a[xx,yy];
        uu:=b[xx,yy];
        if (c=1)or(c=2) then
        begin
          if cc=0 then
          begin
            if u+2<uu then
            begin
              inc(rear);
              //writeln(xx,yy);
              h[rear,1]:=xx;
              h[rear,2]:=yy;
              h[rear,3]:=c+2;
              a[xx,yy]:=c+2;
              h[rear,4]:=u+2;
              b[xx,yy]:=u+2;
            end;
          end
          else
          begin
            if cc=c then
            begin
              if u<uu then
              begin
                inc(rear);
                //writeln(xx,yy);
                h[rear,1]:=xx;
                h[rear,2]:=yy;
                h[rear,3]:=cc;
                a[xx,yy]:=cc;
                h[rear,4]:=u;
                b[xx,yy]:=u;
              end;
            end
            else if cc<>c then
            begin
              if u+1<uu then
              begin
                inc(rear);
                //writeln(xx,yy);
                h[rear,1]:=xx;
                h[rear,2]:=yy;
                h[rear,3]:=c;
                a[xx,yy]:=c;
                h[rear,3]:=u+1;
                b[xx,yy]:=u+1;
              end;
            end;
          end;
        end
        else
        begin
          if cc=c-2 then
          begin
            if u<uu then
            begin
              inc(rear);
              //writeln(xx,yy);
              h[rear,1]:=xx;
              h[rear,2]:=yy;
              h[rear,3]:=cc;
              a[xx,yy]:=cc;
              h[rear,4]:=u;
              b[xx,yy]:=u;
              h[front,3]:=c-2;
              a[x,y]:=c-2;
            end;
          end
          else if (cc<>c-2)and(cc<>0) then
          begin
            if u+1<uu then
            begin
              inc(rear);
              //writeln(xx,yy);
              h[rear,1]:=xx;
              h[rear,2]:=yy;
              h[rear,3]:=c-2;
              a[xx,yy]:=c-2;
              h[rear,4]:=u+1;
              b[xx,yy]:=u+1;
              h[front,3]:=c-2;
              a[x,y]:=c-2;
            end;
          end;
        end;
      end;
    end;
  end;
  writeln(b[m,m]);
  close(input);
  close(output);
end.
