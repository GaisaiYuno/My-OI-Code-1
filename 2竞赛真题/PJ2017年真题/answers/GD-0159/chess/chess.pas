var
        a,f:array[0..101,0..101]of longint;
        b:array[0..101,0..101]of boolean;
        o:array[1..4,1..2]of longint=((-1,0),(0,1),(1,0),(0,-1));
        n,m,i,j,k,x,y,z,s,ls:longint;
procedure dg(x,y,t,p:longint);
var
        i,j,k,z,s,ls:longint;
begin
        if f[x,y]<=t then exit;
        f[x,y]:=t;
        if (x=n)and(y=n) then exit;
        for i:=1 to 4 do
        if (x+o[i,1]>0)and(x+o[i,1]<=n)and(y+o[i,2]>0)and(y+o[i,2]<=n)and(b[x+o[i,1],y+o[i,2]]=false) then
        begin
                if a[x+o[i,1],y+o[i,2]]<>0 then
                begin
                        b[x+o[i,1],y+o[i,2]]:=true;
                        dg(x+o[i,1],y+o[i,2],t+abs(a[x,y]-a[x+o[i,1],y+o[i,2]]),0);
                        b[x+o[i,1],y+o[i,2]]:=false;
                end
                else
                begin
                        if p=0 then
                        begin
                                b[x+o[i,1],y+o[i,2]]:=true;
                                a[x+o[i,1],y+o[i,2]]:=a[x,y];
                                dg(x+o[i,1],y+o[i,2],t+2,1);
                                a[x+o[i,1],y+o[i,2]]:=0;
                                b[x+o[i,1],y+o[i,2]]:=false;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        readln(n,m);
        for i:=1 to m do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        for i:=1 to n do
        for j:=1 to n do
        f[i,j]:=maxlongint;
        b[1,1]:=true;
        dg(1,1,0,0);
        if f[n,n]=maxlongint then writeln(-1)
        else writeln(f[n,n]);
        close(input);
        close(output);
end.
