var
        m,n,i,j,l,k,s,x,y,t:longint;
        a:array[1..1000,1..1000] of longint;
        b:array[1..1000,1..1000] of longint;
        c:array[1..1000,1..1000] of longint;
procedure dg(x,y,ans,t:longint);
var
        i,j:longint;
begin
        if ans<b[x,y] then b[x,y]:=s;
        if (x=n)and(y=n) then
        begin
                if ans<s then s:=ans;
                exit;
        end;
        if (x+1<=n)and(c[x+1,y]=0) then
        begin
                c[x+1,y]:=1;
                if a[x+1,y]<>maxlongint then
                begin
                        if a[x+1,y]=a[x,y] then
                        begin
                                if b[x+1,y]>ans then dg(x+1,y,ans,0);
                        end
                        else
                        begin
                                if b[x+1,y]>ans+1 then dg(x+1,y,ans+1,0);
                        end;
                end
                else
                begin
                        if t=0 then if b[x+1,y]>ans+2 then
                        begin
                                a[x+1,y]:=a[x,y];
                                dg(x+1,y,ans+2,1);
                                a[x+1,y]:=maxlongint;
                        end;
                end;
                c[x+1,y]:=0;
        end;
        if (y+1<=n)and(c[x,y+1]=0) then
        begin
                c[x,y+1]:=1;
                if a[x,y+1]<>maxlongint then
                begin
                        if a[x,y+1]=a[x,y] then
                        begin
                                if b[x,y+1]>ans then dg(x,y+1,ans,0);
                        end
                        else
                        begin
                                if b[x,y+1]>ans+1 then dg(x,y+1,ans+1,0);
                        end;
                end
                else
                begin
                        if t=0 then if b[x,y+1]>ans+2 then
                        begin
                                a[x,y+1]:=a[x,y];
                                dg(x,y+1,ans+2,1);
                                a[x,y+1]:=maxlongint;
                        end;
                end;
                c[x,y+1]:=0;
        end;
        if (x-1>0)and(c[x-1,y]=0) then
        begin
                c[x-1,y]:=1;
                if a[x-1,y]<>maxlongint then
                begin
                        if a[x-1,y]=a[x,y] then
                        begin
                                if b[x-1,y]>ans then dg(x-1,y,ans,0);
                        end
                        else
                        begin
                                if b[x-1,y]>ans+1 then dg(x-1,y,ans+1,0);
                        end;
                end
                else
                begin
                        if t=0 then if b[x-1,y]>ans+2 then
                        begin
                                a[x-1,y]:=a[x,y];
                                dg(x-1,y,ans+2,1);
                                a[x-1,y]:=maxlongint;
                        end;
                end;
                c[x-1,y]:=0;
        end;
        if (y-1>0)and(c[x,y-1]=0) then
        begin
                c[x,y-1]:=1;
                if a[x,y-1]<>maxlongint then
                begin
                        if a[x,y-1]=a[x,y] then
                        begin
                                if b[x,y-1]>ans then dg(x,y-1,ans,0);                       end
                        else
                        begin
                                if b[x,y-1]>ans+1 then dg(x,y-1,ans+1,0);
                        end;
                end
                else
                begin
                        if t=0 then if b[x,y-1]>ans+2 then
                        begin
                                a[x,y-1]:=a[x,y];
                                dg(x,y-1,ans+2,1);
                                a[x,y-1]:=maxlongint;
                        end;
                end;
                c[x,y-1]:=0;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        read(n,m);
        for i:=1 to 1000 do
                for j:=1 to 1000 do
                begin
                        a[i,j]:=maxlongint;
                        b[i,j]:=a[i,j];
                end;
        for i:=1 to m do
        begin
                read(x,y,j);
                a[x,y]:=j;
        end;
        s:=maxlongint;
        b[1,1]:=0;
        c[1,1]:=1;
        dg(1,1,0,0);
        if s<>maxlongint then write(s)
        else write(-1);
        close(input);
        close(output);
end.
