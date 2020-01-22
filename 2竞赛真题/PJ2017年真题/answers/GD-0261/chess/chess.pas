var     n,m,i,j,k,l,ans,x,y,z:longint;
        a:array[0..201,0..201] of -4..4;
        f:array[0..201,0..201] of longint;
        fx:array[1..4,1..2] of -2..2=((1,0),(0,1),(-1,0),(0,-1));
function min(a,b:longint):longint;
begin
        if a<b then min:=a else min:=b;
end;
procedure dg(x,y,k,sum:longint);
var     i,xx,yy:longint;
begin
        if (x=n)and(y=n) then
        begin
                f[n,n]:=min(f[n,n],sum);
                exit;
        end;
        if f[x,y]>sum then f[x,y]:=sum else exit;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if (xx>=1)and(xx<=n)and(yy>=1)and(yy<=n) then
                begin
                        if k=1 then
                        begin
                                if a[xx,yy]<>0 then
                                begin
                                        if a[xx,yy]=a[x,y] then dg(xx,yy,0,sum)
                                        else dg(xx,yy,0,sum+1);
                                end;
                        end
                        else
                        begin
                                if a[xx,yy]=a[x,y] then dg(xx,yy,x,sum)
                                else
                                begin
                                        if a[xx,yy]=0 then
                                        begin
                                                a[xx,yy]:=a[x,y];
                                                dg(xx,yy,1,sum+2);
                                                a[xx,yy]:=0;
                                        end
                                        else dg(xx,yy,k,sum+1);
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(n,m);
        fillchar(f,sizeof(f),127);
        ans:=f[1,1];
        for i:=1 to m do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        dg(1,1,0,0);
        if ans=f[n,n] then writeln(-1) else writeln(f[n,n]);
        close(input);close(output);
end.

