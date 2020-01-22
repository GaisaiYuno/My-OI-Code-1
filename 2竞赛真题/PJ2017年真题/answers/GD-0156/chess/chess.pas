var
        m,n,i,x,y,c,ans,s:longint;
        b:boolean;
        a:array[0..100,0..100]of longint;
        bz:array[0..100,0..100]of boolean;
        f:array[0..100,0..100]of boolean;
procedure dg(x,y,t:longint);
begin
        if not f[x,y] then exit;
        if (x=m)and(y=m) then
        begin
                if ans<t then ans:=t;
        end
        else
        begin
                if (bz[x+1,y]) then
                begin
                        bz[x+1,y]:=false;
                        b:=false;
                end;
                if (bz[x-1,y]) then
                begin
                        bz[x-1,y]:=false;
                        b:=false;
                end;
                if (bz[x,y+1]) then
                begin
                        bz[x,y+1]:=false;
                        b:=false;
                end;
                if (bz[x,y-1]) then
                begin
                        bz[x,y-1]:=false;
                        b:=false;
                end;
                if x+1<=m then
                begin
                        if (a[x+1,y]=2)and(b=false) then
                        begin
                                f[x+1,y]:=false;
                                if a[x,y]=0 then
                                begin
                                        a[x+1,y]:=0;
                                        bz[x+1,y]:=true;
                                        b:=true;
                                        dg(x+1,y,t+2);
                                        a[x+1,y]:=1;
                                        bz[x+1,y]:=true;
                                        b:=true;
                                        dg(x+1,y,t+3);
                                end
                                else
                                begin
                                        a[x+1,y]:=0;
                                        bz[x+1,y]:=true;
                                        b:=true;
                                        dg(x+1,y,t+3);
                                        a[x+1,y]:=1;
                                        bz[x+1,y]:=true;
                                        b:=true;
                                        dg(x+1,y,t+2);
                                end;
                        end;
                        if (a[x+1,y]<2) then
                        begin
                                f[x+1,y]:=false;
                                if a[x+1,y]=a[x,y] then dg(x+1,y,t)
                                else dg(x+1,y,t+1);
                        end;
                end;
                if x-1>=1 then
                begin
                        if (a[x-1,y]=2)and(not b) then
                        begin
                                f[x-1,y]:=false;
                                if a[x,y]=0 then
                                begin
                                        a[x-1,y]:=0;
                                        bz[x-1,y]:=true;
                                        b:=true;
                                        dg(x-1,y,t+2);
                                        a[x-1,y]:=1;
                                        bz[x-1,y]:=true;
                                        b:=true;
                                        dg(x-1,y,t+3);
                                end
                                else
                                begin
                                        a[x-1,y]:=0;
                                        bz[x-1,y]:=true;
                                        b:=true;
                                        dg(x-1,y,t+3);
                                        a[x-1,y]:=1;
                                        bz[x-1,y]:=true;
                                        b:=true;
                                        dg(x-1,y,t+2);
                                end;
                        end;
                        if (a[x-1,y]<2) then
                        begin
                                f[x-1,y]:=false;
                                if a[x-1,y]=a[x,y] then dg(x-1,y,t)
                                else dg(x-1,y,t+1);
                        end;
                end;
                if y+1<=m then
                begin
                        if (a[x,y+1]=2)and(not b) then
                        begin
                                f[x,y+1]:=false;
                                if a[x,y]=0 then
                                begin
                                        a[x,y+1]:=0;
                                        bz[x,y+1]:=true;
                                        b:=true;
                                        dg(x,y+1,t+2);
                                        a[x,y+1]:=1;
                                        bz[x,y+1]:=true;
                                        b:=true;
                                        dg(x,y+1,t+3);
                                end
                                else
                                begin
                                        a[x,y+1]:=0;
                                        bz[x,y+1]:=true;
                                        b:=true;
                                        dg(x,y+1,t+3);
                                        a[x,y+1]:=1;
                                        bz[x,y+1]:=true;
                                        b:=true;
                                        dg(x,y+1,t+2);
                                end;
                        end;
                        if (a[x,y+1]<2) then
                        begin
                                f[x,y+1]:=false;
                                if a[x,y+1]=a[x,y] then dg(x,y+1,t)
                                else dg(x,y+1,t+1);
                        end;
                end;
                if y-1>=1 then
                begin
                        if (a[x,y-1]=2)and(not b) then
                        begin
                                f[x,y-1]:=false;
                                if a[x,y]=0 then
                                begin
                                        a[x,y-1]:=0;
                                        bz[x,y-1]:=true;
                                        b:=true;
                                        dg(x,y-1,t+2);
                                        a[x,y-1]:=1;
                                        bz[x,y-1]:=true;
                                        b:=true;
                                        dg(x,y-1,t+3);
                                end
                                else
                                begin
                                        a[x,y-1]:=0;
                                        bz[x,y-1]:=true;
                                        b:=true;
                                        dg(x,y-1,t+3);
                                        a[x,y-1]:=1;
                                        bz[x,y-1]:=true;
                                        b:=true;
                                        dg(x,y-1,t+2);
                                end;
                        end;
                        if (a[x,y-1]<2) then
                        begin
                                f[x,y-1]:=false;
                                if a[x,y-1]=a[x,y] then dg(x,y-1,t)
                                else dg(x,y-1,t+1);
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        fillchar(a,sizeof(a),2);
        fillchar(bz,sizeof(bz),false);
        fillchar(f,sizeof(f),true);
        b:=false;
        for i:=1 to n do
        begin
                readln(x,y,c);
                a[x,y]:=c;
        end;
        dg(1,1,0);
        if ans=0 then writeln(-1)
        else writeln(ans);
        close(input);close(output); 
end.
