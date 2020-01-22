var i,j,k,n,m,x,y,ans:longint;
a:array[0..1000,0..1000]of integer;
b:array[-1..1000,-1..1000]of boolean;
procedure f(l,r,money,bian:longint);
var s:longint;
begin
  if money>=ans then
  exit;
  if (l=n)and(r=n)then
  begin
    if money<ans then
    ans:=money;
    exit;
  end;
  if not b[l+1,r] then
  begin
    if l+1<=n then
    begin
      if (a[l+1,r]=0) then
      begin
        if bian=0 then
        begin
          a[l+1,r]:=a[l,r];
          b[l+1,r]:=true;
          f(l+1,r,money+2,1);
          b[l+1,r]:=false;
          a[l+1,r]:=0;
        end;
      end
      else
      if a[l+1,r]<>a[l,r]then
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l+1,r]:=true;
        f(l+1,r,money+1,0);
        if bian=1 then
        a[l,r]:=s;
        b[l+1,r]:=false;
      end
      else
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l+1,r]:=true;
        f(l+1,r,money,0);
        if bian=1 then
        a[l,r]:=s;
        b[l+1,r]:=false;
      end;
    end;
  end;
  if not b[l,r+1] then
  begin
    if r+1<=n then
    begin
      if a[l,r+1]=0 then
      begin
        if bian=0 then
        begin
          b[l,r+1]:=true;
          a[l,1+r]:=a[l,r];
          f(l,1+r,money+2,1);
          b[l,r+1]:=false;
          a[l,1+r]:=0;
        end;
      end
      else
      if a[l,1+r]<>a[l,r]then
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l,r+1]:=true;
        f(l,1+r,money+1,0);
        if bian=1 then
        a[l,r]:=s;
        b[l,r+1]:=false;
      end
      else
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l,r+1]:=true;
        f(l,1+r,money,0);
        if bian=1 then
        a[l,r]:=s;
        b[l,r+1]:=false;
      end;
    end;
  end;
  if not b[l-1,r] then
  begin
    if l-1>=1 then
    begin
      if a[l-1,r]=0 then
      begin
        if bian=0 then
        begin
          a[l-1,r]:=a[l,r];
          b[l-1,r]:=true;
          f(l-1,r,money+2,1);
          a[l-1,r]:=0;
          b[l-1,r]:=false;
        end;
      end
      else
      if a[l-1,r]<>a[l,r]then
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l-1,r]:=true;
        f(l-1,r,money+1,0);
        if bian=1 then
        a[l,r]:=s;
        b[l-1,r]:=false;
      end
      else
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l-1,r]:=true;
        f(l-1,r,money,0);
        if bian=1 then
        a[l,r]:=s;
        b[l-1,r]:=false;
      end;
    end;
  end;
  if not b[l,r-1] then
  begin
    if r-1>=0 then
    begin
      if a[l,r-1]=0 then
      begin
        if bian=0 then
        begin
          b[l,r-1]:=true;
          a[l,r-1]:=a[l,r];
          f(l,r-1,money+2,1);
          b[l,r-1]:=false;
          a[l,r-1]:=0;
        end;
      end
      else
      if a[l,r-1]<>a[l,r]then
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l,r-1]:=true;
        f(l,r-1,money+1,0);
        b[l,r-1]:=false;
      end
      else
      begin
        if bian=1 then
        begin
          s:=a[l,r];
          a[l,r]:=0;
        end;
        b[l,r-1]:=true;
        f(l,r-1,money,0);
        b[l,r-1]:=false;
      end;
    end;
  end;
  if bian=1 then
  a[l,r]:=0;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
    read(x,y,k);
    a[x,y]:=k+1;
  end;
  b[1,1]:=true;
  ans:=maxlongint;
  f(1,1,0,0);
  if ans=maxlongint then
  writeln(-1)
  else
  writeln(ans);
  close(input);close(output);
end.