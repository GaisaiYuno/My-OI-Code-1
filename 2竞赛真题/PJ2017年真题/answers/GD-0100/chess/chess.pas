var
        i,j,m,n,x,y,z:longint;
        a,bz:array[1..100,1..100]of longint;
        f:array[1..100,1..100,1..2]of longint;
        fx:array[1..4,1..2]of longint=((1,0),(0,1),(-1,0),(0,-1));
function min(a,b:longint):longint;
begin
        if a=-1 then exit(b);
        if b=-1 then exit(a);
        if a<b then exit(a) else exit(b);
end;
procedure dg(x,y,z,p:longint);
var
        i,xx,yy,l,l2:longint;
begin
        if (x=m)and(y=m) then exit;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if (xx>=1)and(xx<=m)and(yy>=1)and(yy<=m) then
                        if a[xx,yy]<>0 then
                        begin
                                if (a[xx,yy]=a[x,y])or((z=1)and(a[xx,yy]=p)) then
                                        l:=0
                                else
                                        l:=1;
                                if z=0 then l2:=f[x,y,1] else l2:=f[x,y,2];
                                if (f[xx,yy,1]=-1)or(l2+l<f[xx,yy,1]) then
                                begin
                                        f[xx,yy,1]:=l2+l;
                                        dg(xx,yy,0,0);
                                end;
                        end
                        else
                        begin
                                if z=0 then
                                begin
                                        l:=2;
                                        l2:=f[x,y,1];
                                        if (f[xx,yy,2]=-1)or(l2+l<f[xx,yy,2]) then
                                        begin
                                                f[xx,yy,2]:=l2+l;
                                                dg(xx,yy,1,a[x,y]);
                                        end;
                                end;
                        end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to n do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        for i:=1 to 100 do
                for j:=1 to 100 do
                begin
                        f[i,j,1]:=-1;
                        f[i,j,2]:=-1;
                end;
        f[1,1,1]:=0;
        f[1,1,2]:=0;
        bz[1,1]:=1;
        dg(1,1,0,0);
        writeln(min(f[m,m,1],f[m,m,2]));
        close(input);close(output);
end.
