var   n,m,ans,max,i,x,y,c,j:longint; a,b:array[-1..101,-1..101] of integer;
      dx,dy:array[1..4] of integer;


procedure dfs(x,y:longint);
var  i:longint;
begin
    if (x=m)and(y=m)and(ans>max) then begin max:=ans; exit; end;
    for i:=1 to 4 do
      begin
        if (x+dx[i]>0)and(x+dx[i]<=m)and(y+dy[i]>0)and(y+dy[i]<=m)
         and (b[x+dx[i],y+dy[i]]=0) then
         begin
           if (a[x+dx[i],y+dy[i]]<>-1) then
            begin
              if (a[x,y]<>a[x+dx[i],y+dy[i]]) then
               begin
                 inc(ans);
                 x:=x+dx[i]; y:=y+dy[i];
                 b[x,y]:=1;
                 dfs(x,y);
                 x:=x-dx[i]; y:=y-dy[i];
                 ans:=ans-1; b[x,y]:=0;
               end
              else
              begin
                x:=x+dx[i]; y:=y+dy[i];
                b[x,y]:=1;
                dfs(x,y);
                x:=x-dx[i]; y:=y-dy[i]; b[x,y]:=0;
              end;
            end
           else
           begin
             if (b[x,y]=2) then  exit
              else
               begin
                 x:=x+dx[i]; y:=y+dy[i]; ans:=ans+2;
                 a[x,y]:=0; b[x,y]:=2;
                 dfs(x,y);
                 a[x,y]:=1;
                 dfs(x,y);
                 ans:=ans-2; a[x,y]:=-1;
                 b[x,y]:=2; x:=x-dx[i]; y:=y-dy[i];
               end;
           end;
        end;
      end;
end;

begin
  assign(input,'chess.in'); assign(output,'chess.out');
  reset(input); rewrite(output);
  readln(m,n);
  for i:=1 to m do
    for j:=1 to m do a[i,j]:=-1;
  for i:=1 to n do
    begin
      readln(x,y,c);
      a[x,y]:=c;
    end;
  fillchar(b,sizeof(b),0);
  ans:=0; max:=0;
  dx[1]:=-1; dy[1]:=0; dx[2]:=1; dy[2]:=0;
  dx[3]:=0; dy[3]:=-1; dx[4]:=1; dy[4]:=0;
  //dfs(1,1);
  writeln('-1');
  close(input); close(output);
end.