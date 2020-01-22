var     n,m,i,j,k,l,ans,x,y,z:longint;
        a:array[0..101,0..1001] of -1..2;
        bz:array[0..101,0..1001] of boolean;
        fx:array[1..4,1..2] of -1..1=((1,0),(0,1),(-1,0),(0,-1));
function min(a,b:longint):longint;
begin
        if a<b then min:=a else min:=b;
end;
procedure dg(x,y,k,sum:longint);
var     i,xx,yy:longint;
begin
        if (x=n)and(y=n) then
        begin
                ans:=min(ans,sum);
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if (xx>=1)and(xx<=n)and(yy>=1)and(yy<=n)and(not bz[xx,yy]) then
                begin
                        if k=1 then
                        begin
                                if a[xx,yy]<>0 then
                                begin
                                        bz[xx,yy]:=true;
                                        if a[xx,yy]=a[x,y] then dg(xx,yy,0,sum)
                                        else dg(xx,yy,0,sum+1);
                                        bz[xx,yy]:=false;
                                end;
                        end
                        else
                        begin
                                if a[xx,yy]=a[x,y] then dg(xx,yy,x,sum)
                                else
                                begin
                                        if a[xx,yy]=0 then
                                        begin
                                                bz[xx,yy]:=true;
                                                a[xx,yy]:=a[x,y];
                                                dg(xx,yy,1,sum+2);
                                                a[xx,yy]:=0;
                                                bz[xx,yy]:=false;
                                        end
                                        else
                                        begin
                                                bz[xx,yy]:=true;
                                                dg(xx,yy,k,sum+1);
                                                bz[xx,yy]:=false;
                                        end;
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        ans:=maxlongint;
        bz[1,1]:=true;
        dg(1,1,0,0);
        if ans=maxlongint then writeln(-1) else writeln(ans);
        close(input);close(output);
end.
