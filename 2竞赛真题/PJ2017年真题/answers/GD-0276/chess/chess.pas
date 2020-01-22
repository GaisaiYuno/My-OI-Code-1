var f:array[1..100,1..100] of longint;
    m,n,min,x,y,k,i:longint;
procedure lnj(xx,yy,q,qq,u:longint);
begin
  if (xx=m) and (yy=m) then if min>q then begin
    min:=q;
    exit;
  end;
  if (xx>0) and(xx<m+1) and (yy+1>0) and (yy+1<m+1) then begin
    if (abs(f[xx,yy+1]-f[xx,yy])<2) then begin
      if f[xx,yy+1]=f[xx,yy] then begin
        if u=1 then f[xx,yy]:=0;
        lnj(xx,yy+1,q,qq+1,0);
      end else begin
        if u=1 then f[xx,yy]:=0;
        lnj(xx,yy+1,q+1,qq+1,0);
      end;
    end
    else begin
      if u=0 then begin
        f[xx,yy+1]:=f[xx,yy];
        lnj(xx,yy+1,q+2,qq+1,1);
      end;
    end;
  end;
  if (xx+1>0) and(xx+1<m+1) and (yy>0) and (yy<m+1) then begin
    if (abs(f[xx+1,yy]-f[xx,yy])<2) then begin
      if f[xx+1,yy]=f[xx,yy] then begin
        if u=1 then f[xx,yy]:=0;
        lnj(xx+1,yy,q,qq+1,0);
      end else begin
        if u=1 then f[xx,yy]:=0;
        lnj(xx+1,yy,q+1,qq+1,0);
      end;
    end
    else begin
      if u=0 then begin
       f[xx+1,yy]:=f[xx,yy];
       lnj(xx+1,yy,q+2,qq+1,1);
      end;
    end;
  end;
  if u=1 then f[xx,yy]:=0;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=1 to n do begin
    readln(x,y,k);
    f[x,y]:=k+2;
  end;
  min:=maxlongint;
  lnj(1,1,0,0,0);
  if min=maxlongint then min:=-1;
  writeln(min);
  close(input);
  close(output);
end.
