var
        fx:array[1..4,1..2]of longint=((0,1),(0,-1),(1,0),(-1,0));
        n,m,i,j,ans,x,y,z:longint;
        a:array[0..101,0..101]of longint;
        bz:array[0..101,0..101]of boolean;
function min(a,b:longint):longint;
begin
        if a>b then exit(b);
        exit(a);
end;
procedure dg(x,y,t,s:longint);
var
        i,xx,yy:longint;
begin
        if(x=m)and(y=m)then
        begin
                ans:=min(ans,s);
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if bz[xx,yy] then continue;
                if a[xx,yy]=0 then continue;
                if(a[x,y]=-1)and(a[xx,yy]=-1)then continue;
                if a[xx,yy]=-1 then
                begin
                        bz[xx,yy]:=true;
                        dg(xx,yy,t,s+2);
                        bz[xx,yy]:=false;
                end
                else
                begin
                        if t=a[xx,yy] then
                        begin
                                bz[xx,yy]:=true;
                                dg(xx,yy,t,s);
                                bz[xx,yy]:=false;
                        end;
                        if t<>a[xx,yy] then
                        begin
                                bz[xx,yy]:=true;
                                dg(xx,yy,a[xx,yy],s+1);
                                bz[xx,yy]:=false;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        ans:=maxlongint;
        for i:=1 to m do
                for j:=1 to m do
                        a[i,j]:=-1;
        for i:=1 to n do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        bz[1,1]:=true;
        dg(1,1,a[x,y],0);
        if ans=maxlongint then writeln('-1')
        else writeln(ans);
        close(input);
        close(output);
end.
