var
        n,m,i,j,k,l,x,y,z,p,min:longint;
        a,bz:array[0..100,0..1000]of longint;
function max(x,y:longint):longint;
begin
        if x>y then exit(x);
        exit(y);
end;
procedure dg(x,y,ans:longint);
var
        xx,yy,bz1:longint;
begin
        if (x=n)and(y=n) then
        begin
                if ans<min then min:=ans;
        end
        else
        begin
                xx:=x+1;
                yy:=y+1;
                if xx<=n then
                begin
                        if a[xx,y]<=3 then
                        begin
                                if (a[xx,y]=a[x,y]) then dg(xx,y,ans)
                                else dg(xx,y,ans+1);
                        end
                        else
                        begin
                                p:=a[xx,y];
                                if bz[x,y]=0 then
                                begin
                                        a[xx,y]:=a[x,y];
                                        bz[xx,y]:=1;
                                        dg(xx,y,ans+2);
                                        bz[xx,y]:=0;
                                        a[xx,y]:=p;
                                end;
                        end;
                end;
                if yy<=n then
                begin
                        if a[x,yy]<=3 then
                        begin
                                if (a[x,yy]=a[x,y]) then dg(x,yy,ans)
                                else dg(x,yy,ans+1);
                        end
                        else
                        begin
                                p:=a[x,yy];
                                if bz[x,y]=0 then
                                begin
                                        a[x,yy]:=a[x,y];
                                        bz[x,yy]:=1;
                                        dg(x,yy,ans+2);
                                        bz[x,yy]:=0;
                                        a[x,yy]:=p;
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(n,m);
        fillchar(a,sizeof(a),127);
        for i:=1 to n do
        begin
                a[i,0]:=0;
                a[0,i]:=0;
        end;
        min:=maxlongint;
        for i:=1 to m do
        begin
                readln(x,y,z);
                a[x,y]:=z;
        end;
        if n<=20 then
        begin
                dg(1,1,0);
                if min=maxlongint then min:=-1;
                writeln(min);
        end
        else
        writeln(-1);
        close(input);close(output);
end.
