var
  b:array [0..101,0..101] of boolean;
  a:array [0..101,0..101] of longint;
  z:longint;
  y,v,g,n,i,m,s:longint;
procedure tg(h,l,q:longint);
begin
  if(h=m) and (l=m) then
    begin
      if (q<s) or (s=0) then s:=q;
      exit;
    end;
  if (q>s) and (s<>0) then exit;
  if (b[h+1,l]=false) and (h+1<=m) then
    begin
      if (a[h,l]=a[h+1,l]) and (a[h+1,l]>0) then
        begin
          b[h+1,l]:=true;
          tg(h+1,l,q);
          z:=0;
        end
      else if a[h+1,l]>0 then
        begin
          b[h+1,l]:=true;
          tg(h+1,l,q+1);
          z:=0;
        end
      else if z=0 then
        begin
          z:=1;
          b[h+1,l]:=true;
          a[h+1,l]:=1;
          if a[h,l]<>1 then tg(h+1,l,q+3)
          else tg(h+1,l,q+2);
          a[h+1,l]:=2;
          if a[h,l]<>2 then tg(h+1,l,q+3)
          else tg(h+1,l,q+2);
          a[h+1,l]:=0;
          z:=0;
        end;
      b[h+1,l]:=false;
    end;
  if (b[h,l+1]=false) and (l+1<=m) then
    begin
      if (a[h,l]=a[h,l+1]) and (a[h,l+1]>0) then
        begin
          b[h,l+1]:=true;
          tg(h,l+1,q);
          z:=0;
        end
      else if a[h,l+1]>0 then
        begin
          b[h,l+1]:=true;
          tg(h,l+1,q+1);
          z:=0;
        end
      else if z=0 then
        begin
          z:=1;
          b[h,l+1]:=true;
          a[h,l+1]:=1;
          if a[h,l]<>1 then tg(h,l+1,q+3)
          else tg(h,l+1,q+2);
          a[h,l+1]:=2;
          if a[h,l]<>2 then tg(h,l+1,q+3)
          else tg(h,l+1,q+2);
          a[h,l+1]:=0;
          z:=0;
        end;
      b[h,l+1]:=false;
    end;
  if (b[h-1,l]=false) and (h-1>=1) then
    begin
      if (a[h,l]=a[h-1,l]) and (a[h-1,l]>0) then
        begin
          b[h-1,l]:=true;
          tg(h-1,l,q);
          z:=0;
        end
      else if a[h-1,l]>0 then
        begin
          b[h-1,l]:=true;
          tg(h-1,l,q+1);
          z:=0;
        end
      else if z=0 then
        begin
          z:=1;
          b[h-1,l]:=true;
          a[h-1,l]:=1;
          if a[h,l]<>1 then tg(h-1,l,q+3)
          else tg(h-1,l,q+2);
          a[h-1,l]:=2;
          if a[h,l]<>2 then tg(h-1,l,q+3)
          else tg(h-1,l,q+2);
          a[h-1,l]:=0;
          z:=0;
        end;
      b[h-1,l]:=false;
    end;
  if (b[h,l-1]=false) and (l-1>=1) then
    begin
      if (a[h,l]=a[h,l-1]) and (a[h,l-1]>0) then
        begin
          b[h,l-1]:=true;
          tg(h,l-1,q);
          z:=0;
        end
      else if a[h,l-1]>0 then
        begin
          b[h,l-1]:=true;
          tg(h,l-1,q+1);
          z:=0;
        end
      else if z=0 then
        begin
          z:=1;
          b[h,l-1]:=true;
          a[h,l-1]:=1;
          if a[h,l]<>1 then tg(h,l-1,q+3)
          else tg(h,l-1,q+2);
          a[h,l-1]:=2;
          if a[h,l]<>2 then tg(h,l-1,q+3)
          else tg(h,l-1,q+2);
          a[h,l-1]:=0;
          z:=0;
        end;
      b[h,l-1]:=false;
    end;
end;

begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);
  readln(m,n);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    begin
      readln(v,g,y);
      a[v,g]:=y+1;
    end;
  s:=0;
  b[1,1]:=true;
  tg(1,1,0);
  if s>0 then write(s)
              else write('-',1);
  close(input);
  close(output);
end.
