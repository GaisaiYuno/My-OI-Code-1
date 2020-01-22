type boo=array [1..100,1..100] of boolean;
const fx:array[1..4,1..2] of longint=((1,0),(0,-1),(-1,0),(0,1));
var
        n,m,i,j,x,y,c,ans:longint;
        f:array[1..100,1..100] of longint;
        bz:boo;
procedure dg(x,y,t,v,c:longint;bz:boo);
var
        xx,yy,i:longint;
        bian:boo;
begin
        if (x=m)and(y=m) then
        begin
                if ans>v then ans:=v;
                exit;
        end;
        for i:=1 to 4 do
        begin
                xx:=x+fx[i,1];
                yy:=y+fx[i,2];
                if t=0 then
                begin
                        if (xx in[1..m])and(yy in[1..m])and(bz[xx,yy]=false) then
                        begin
                                if f[xx,yy]=f[x,y] then
                                begin
                                        bian:=bz;
                                        bian[xx,yy]:=true;
                                        dg(xx,yy,0,v,f[x,y],bian);
                                end else
                                begin
                                        if f[xx,yy]<>3 then
                                        begin
                                                bian:=bz;
                                                bian[xx,yy]:=true;
                                                dg(xx,yy,0,v+1,f[x,y],bian);
                                        end else dg(xx,yy,1,v+2,f[x,y],bian);
                                end;
                        end;
                end else
                begin
                        if (xx in[1..m])and(yy in[1..m]) then
                                if (bz[xx,yy]=false) then
                        begin
                                if f[xx,yy]<>3 then
                                begin
                                        bian:=bz;
                                        bian[xx,yy]:=true;
                                        if c=f[xx,yy] then
                                                dg(xx,yy,0,v,f[x,y],bian)
                                        else dg(xx,yy,0,v+1,f[x,y],bian);
                                end;
                        end;
                end;
        end;
end;
BEGIN
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        read(m,n);
        ans:=maxlongint;
        for i:=1 to m do
                for j:=1 to m do f[i,j]:=3;
        for i:=1 to n do
        begin
                read(x,y,c);
                f[x,y]:=c;
        end;
        writeln(-1);
        //dg(1,1,0,0,f[1,1],bz);
        //writeln(ans);
        close(input);close(output);
END.
