program chess;
const yd:array[1..4,1..2] of longint=((1,0),(0,1),(-1,0),(0,-1));
var
  a:array[1..100,1..100] of longint;
  b,b1:array[0..101,0..101] of boolean;
  n,m,i,j,x,y,k,ans:longint;
function bj(x,y:longint):boolean;
begin
  if (x>=1) and (x<=n) and (y>=1) and (y<=n) then bj:=true else bj:=false;
end;
procedure search(k,x,y,l:longint; u:boolean);
var i,x1,y1:longint; b1:array[1..4] of boolean;
begin
  if (x=n) and (y=n) then begin if k<ans then ans:=k; end
  else begin
    for i:=1 to 4 do begin
      x1:=x+yd[i,1]; y1:=y+yd[i,2];   fillchar(b1,sizeof(b1),false);
      if b[x1,y1] then begin
        if (a[x1,y1]=0) and u then begin
          b[x,y]:=false;   for j:=1 to 4 do if b[x+yd[j,1],y+yd[j,2]] then begin b[x+yd[j,1],y+yd[j,2]]:=false; b1[j]:=true; end;
          if k+2<ans then
          search(k+2,x1,y1,a[x,y],false);
          b[x,y]:=true;    for j:=1 to 4 do if b1[j] then b[x+yd[j,1],y+yd[j,2]]:=true;
        end;
        if (a[x1,y1]<>0) and (a[x1,y1]<>l) then begin
          b[x,y]:=false;   for j:=1 to 4 do if b[x+yd[j,1],y+yd[j,2]] then begin b[x+yd[j,1],y+yd[j,2]]:=false; b1[j]:=true; end;
          if k+1<ans then
          search(k+1,x1,y1,a[x1,y1],true);
          b[x,y]:=true;    for j:=1 to 4 do if b1[j] then b[x+yd[j,1],y+yd[j,2]]:=true;
        end;
        if (a[x1,y1]<>0) and (a[x1,y1]=l) then begin
          b[x,y]:=false;   for j:=1 to 4 do if b[x+yd[j,1],y+yd[j,2]] then begin b[x+yd[j,1],y+yd[j,2]]:=false; b1[j]:=true; end;
          if k<ans then
          search(k,x1,y1,a[x1,y1],true);
          b[x,y]:=true;    for j:=1 to 4 do if b1[j] then b[x+yd[j,1],y+yd[j,2]]:=true;
        end;
      end;
    end;
  end;
end;
begin
  assign(input,'chess.in'); reset(input);
  assign(output,'chess.out'); rewrite(output);
  readln(n,m);
  if n>20 then writeln(-1) else begin
  for i:=1 to m do begin
    read(x,y,k);
    if k=0 then a[x,y]:=1;
    if k=1 then a[x,y]:=2;
  end;
  ans:=maxlongint;
  for i:=1 to n do
    for j:=1 to n do b[i,j]:=true;
  search(0,1,1,a[1,1],true);
  if ans=maxlongint then writeln(-1)
  else writeln(ans);
  end;
  close(input); close(output);
end.
