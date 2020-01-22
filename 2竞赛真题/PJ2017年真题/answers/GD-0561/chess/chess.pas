const fx:array [1..4,1..2] of integer=((1,0),(0,1),(-1,0),(0,-1));
var n,m,x,y,c,i,j,ans:longint;
    v:array [1..1010,1..1010] of longint;
    p:array [1..1010,1..1010] of boolean;
function pd(a,b:longint):boolean;
begin
  if(a>=1) and (a<=m) and (b>=1) and (b<=m) and (p[a,b]) then exit(true) else exit(false);
end;
procedure dfs(xx,yy,dep,sum:longint);
var i,c1,c2:longint;
begin
  if(xx=m) and (yy=m) and (dep<ans) then begin ans:=dep; exit; end;
  for i:=1 to 4 do begin
    c1:=xx+fx[i,1];
    c2:=yy+fx[i,2];
    if(pd(c1,c2)) then begin
      if(sum=1) and (v[c1,c2]=2) then continue;
      if(sum=1) then begin
        if (v[c1,c2]<>v[xx,yy]) then begin
          p[c1,c2]:=false;
          dfs(c1,c2,dep+1,0);
          p[c1,c2]:=true;
        end else
        begin
          p[c1,c2]:=false;
          dfs(c1,c2,dep,0);
          p[c1,c2]:=true;
        end;
      end else begin
        if(v[c1,c2]=2) then begin
          p[c1,c2]:=false;
          v[c1,c2]:=v[xx,yy];
          dfs(c1,c2,dep+2,1);
          v[c1,c2]:=2;
          p[c1,c2]:=true;
        end else begin
          if(v[xx,yy]=v[c1,c2]) then begin
            p[c1,c2]:=false;
            dfs(c1,c2,dep,0);
            p[c1,c2]:=true;
          end else begin
            p[c1,c2]:=false;
            dfs(c1,c2,dep+1,0);
            p[c1,c2]:=true;
          end;
        end;
      end;
    end;
  end;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=1 to m do
    for j:=1 to m do v[i,j]:=2;
  for i:=1 to n do begin
    readln(x,y,c);
    v[x,y]:=c;
  end;
  fillchar(p,sizeof(p),true);
  ans:=maxlongint;
  dfs(1,1,0,0);
  if(ans=maxlongint) then writeln(-1) else writeln(ans);
  close(input);
  close(output);
end.