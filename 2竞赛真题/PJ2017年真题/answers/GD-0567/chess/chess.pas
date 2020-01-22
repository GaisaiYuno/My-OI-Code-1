var
        a,f:array[1..100,1..100]of longint;
        bz:array[1..100,1..100]of boolean;
        w:array[1..4,1..2]of longint=((-1,0),(0,-1),(1,0),(0,1));
        n,m,x,y,z,i,j,min,k:longint;
procedure dg(x,y,s:longint);
var
        i,xx,yy,xxx,yyy,j:longint;
begin
        if(x=m)and(y=m)then
        begin
                if s<min then min:=s;
        end
        else
        begin
                if s<f[x,y]then f[x,y]:=s
                else exit;
                for i:=1 to 4 do
                begin
                        xx:=x+w[i,1];
                        yy:=y+w[i,2];
                        if(xx>0)and(xx<=m)and(yy>0)and(yy<=m)and(bz[xx,yy]=false)then
                        begin
                                if a[xx,yy]=a[x,y] then
                                begin
                                        bz[xx,yy]:=true;
                                        dg(xx,yy,s);
                                        bz[xx,yy]:=false;
                                end
                                else if(a[xx,yy]=1)and(a[x,y]=0)or(a[xx,yy]=0)and(a[x,y]=1)then
                                begin
                                        bz[xx,yy]:=true;
                                        dg(xx,yy,s+1);
                                        bz[xx,yy]:=false;
                                end
                                else if(a[x,y]<>-1)and(a[xx,yy]=-1)then
                                begin
                                        for j:=1 to 4 do
                                        begin
                                                xxx:=xx+w[j,1];
                                                yyy:=yy+w[j,2];
                                                if(xxx<=m)and(xxx>=1)and(yyy<=m)and(yyy>=1)and(bz[xxx,yyy]=false)then
                                                begin
                                                        if a[xxx,yyy]<>-1 then
                                                        begin
                                                                bz[xx,yy]:=true;
                                                                bz[xxx,yyy]:=true;
                                                                if a[x,y]=a[xxx,yyy] then dg(xxx,yyy,s+2)
                                                                else dg(xxx,yyy,s+3);
                                                                bz[xx,yy]:=false;
                                                                bz[xxx,yyy]:=false;
                                                        end;
                                                end;
                                        end;
                                end;
                        end;
                end;
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to m do
                for j:=1 to m do
                begin
                        a[i,j]:=-1;
                        bz[i,j]:=false;
                        f[i,j]:=maxlongint;
                end;
        for i:=1 to n do
        begin
                readln(x,y,z);
                a[x,y]:=z;
        end;
        bz[1,1]:=true;
        min:=maxlongint;
        dg(1,1,0);
        if min=maxlongint then write('-1')
        else writeln(min);
        close(input);
        close(output);
end.