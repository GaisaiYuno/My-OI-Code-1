var
        f:array[1..100,1..100]of longint;
        fx:array[1..4,1..2]of longint=((0,1),(1,0),(0,-1),(-1,0));
        a:array[1..100,1..100]of longint;
        bz,bz1:array[1..100,1..100]of boolean;
        n,m,i,j,l,h,x,y,z,k:longint;
function min(a,b:longint):longint;
begin
        if a<b then exit(a) else exit(b);
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        fillchar(bz,sizeof(bz),false);
        fillchar(bz1,sizeof(bz1),false);
        read(n,m);
        for i:=1 to n do
                for j:=1 to n do
                begin
                        a[i,j]:=1000;
                        f[i,j]:=maxlongint-1;
                end;
        for i:=1 to m do
        begin
                read(x,y,z);
                a[x,y]:=z;
                bz1[x,y]:=true;
        end;
        f[1,1]:=0;
        bz[1,1]:=true;
        for k:=1 to 10 do
        begin
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        if (i<>1)or(j<>1) then
                        begin
                                for l:=1 to 4 do
                                begin
                                        x:=i+fx[l,1];
                                        y:=j+fx[l,2];
                                        if (x>0)and(x<=n)and(y>0)and(y<=n)and(bz[x,y])and((bz1[x,y])or(bz1[i,j])) then
                                        begin
                                                if not(bz1[i,j]) then
                                                begin
                                                        f[i,j]:=f[x,y]+2;
                                                        bz[i,j]:=true;
                                                        a[i,j]:=a[x,y];
                                                end
                                                else
                                                begin
                                                        f[i,j]:=min(f[i,j],f[x,y]+abs(a[x,y]-a[i,j]));
                                                        bz[i,j]:=true;
                                                end;
                                        end;
                                end;
                        end;
                end;
        end;
        end;
        if f[n,n]<maxlongint-1 then
                write(f[n,n])
        else
                write('-1');
        close(input);
        close(output);
end.
