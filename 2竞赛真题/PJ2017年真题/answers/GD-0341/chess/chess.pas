var
        fx:array[1..4] of longint=(0,1,-1,0);
        fy:array[1..4] of longint=(1,0,0,-1);
        a,b:array[1..1000,1..1000] of longint;
        i,n,m,x,y,z,min,o,t:longint;
procedure dfs(x,y,detp:longint);
var     i,nx,ny:longint;
begin
        if (x=m)and(y=m) then begin
                if detp<min then min:=detp;
                end
        else
        for i:=1 to 4 do
        begin
                nx:=x+fx[i];ny:=y+fy[i];
                if(nx>=1)and(nx<=m)and(ny>=1)and(ny<=m)and(b[nx,ny]=0) then
                begin
                        if a[nx,ny]=a[x,y] then begin
                                b[x,y]:=1;
                                o:=t;
                                if t>0 then t:=t-1;
                                dfs(nx,ny,detp);
                                t:=o;
                                b[x,y]:=0;
                                end;
                        if (a[nx,ny]<>a[x,y])and(a[nx,ny]<>0)then begin
                                b[x,y]:=1;
                                o:=t;
                                if t>0 then t:=t-1;
                                dfs(nx,ny,detp+1);
                                t:=o;
                                b[x,y]:=0;
                                end;
                        if (a[nx,ny]=0)and(t<1) then begin
                                b[x,y]:=1;
                                a[nx,ny]:=a[x,y];
                                t:=t+1;
                                dfs(nx,ny,detp+2);
                                t:=t-1;
                                a[nx,ny]:=0;
                                b[x,y]:=0;
                                end;
                end;
        end;
end;
begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
readln(m,n);
min:=maxlongint;
for i:=1 to n do
begin
        readln(x,y,z);
        a[x,y]:=z+1;
end;
dfs(1,1,0);
if min<>maxlongint then writeln(min)
        else writeln(-1);
close(input);
close(output);
end.