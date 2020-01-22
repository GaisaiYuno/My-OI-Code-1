var
        a,f:array[0..101,0..101]of longint;
        b:array[1..4,1..2]of longint=((1,0),(-1,0),(0,1),(0,-1));
        i,j,n,m,k,l,o,p,ans:longint;
procedure dg(x,y,z,w:longint);
var
        i,j:longint;
begin
        if z>=ans then exit;
        if f[x,y]>z then f[x,y]:=z else exit;
        if (x=n)and(y=n) then
        begin
                if ans>z then ans:=z;
                exit;
        end;
        for i:=1 to 4 do
        begin
                o:=x+b[i,1];
                p:=y+b[i,2];
                if (o>0)and(p>0)and(o<=n)and(p<=n) then
                begin
                        if a[x,y]=0 then
                        begin
                                if a[o,p]=0 then dg(o,p,z,2);
                                if a[o,p]=1 then dg(o,p,z+1,2);
                                if a[o,p]=2 then dg(o,p,z+2,0);
                        end;
                        if a[x,y]=1 then
                        begin
                                if a[o,p]=0 then dg(o,p,z+1,2);
                                if a[o,p]=1 then dg(o,p,z,2);
                                if a[o,p]=2 then dg(o,p,z+2,1);
                        end;
                        if a[x,y]=2 then
                        begin
                                if a[o,p]=0 then
                                begin
                                        if w=0 then dg(o,p,z,2);
                                        if w=1 then dg(o,p,z+1,2);
                                end;
                                if a[o,p]=1 then
                                begin
                                        if w=0 then dg(o,p,z+1,2);
                                        if w=1 then dg(o,p,z,2);
                                end;
                                if a[o,p]=2 then continue;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        read(n,m);
        ans:=maxlongint;
        for i:=1 to n do
          for j:=1 to n do
          begin
                a[i,j]:=2;
                f[i,j]:=maxlongint;
          end;
        for i:=1 to m do
        begin
                read(o,p,l);
                a[o,p]:=l;
        end;
        dg(1,1,0,2);
        if ans=maxlongint then writeln(-1) else writeln(ans);
        close(input);close(output);
end.
