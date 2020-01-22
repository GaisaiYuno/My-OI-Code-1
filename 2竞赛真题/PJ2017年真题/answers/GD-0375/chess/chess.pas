var
        i,j,n,m,ans,max:longint;
        x,y,c:array[1..1000]  of  longint;
        f,a:array[0..1000,0..1000]  of  longint;
        p:array[0..1000,0..1000]  of  boolean;
        dx:array[1..4]  of  integer=(0,0,1,-1);
        dy:array[1..4]  of  integer=(1,-1,0,0);
        tt:boolean;
Procedure       dfs(x,y:longint);
var
        i,k,kk:longint;
begin
        if  (x=m)  and  (y=m)  then
        begin
                if   ans<max   then  max:=ans;
                exit;
        end;
        if   (x<1)  or  (x>m)  or  (y<1)  or  (y>m)  then  exit;
        p[x,y]:=false;
        for  i:=1  to  4  do
                        if  p[x+dx[i],y+dy[i]]  and  (a[x+dx[i],y+dy[i]]=1)  then
                                if  f[x+dx[i],y+dy[i]]=f[x,y]  then
                                begin
                                        dfs(x+dx[i],y+dy[i]);
                                        p[x+dx[i],y+dy[i]]:=true;
                                end;
        for  i:=1  to  4  do
                        if   p[x+dx[i],y+dy[i]]  and  (a[x+dx[i],y+dy[i]]=1) then
                                if  f[x+dx[i],y+dy[i]]<>f[x,y]  then
                                begin
                                        ans:=ans+1;
                                        dfs(x+dx[i],y+dy[i]);
                                        p[x+dx[i],y+dy[i]]:=true;
                                        ans:=ans-1;
                                end;
        for  i:=1  to  4  do
                        if   (p[x+dx[i],y+dy[i]])  and  (a[x,y]=1)  then
                        begin
                                tt:=false;
                                for  k:=1  to  4  do
                                        for  kk:=1  to  4  do
                                                if  p[(x+dx[i])+dx[k],(y+dy[i])+dy[kk]]  and  (a[(x+dx[i])+dx[k],(y+dy[i])+dy[kk]]=1)  then
                                                        tt:=true;
                                if  tt=true  then
                                begin
                                        ans:=ans+2;
                                        a[x+dx[i],y+dy[i]]:=2;
                                        dfs(x+dx[i],y+dy[i]);
                                        p[x+dx[i],y+dy[i]]:=true;
                                        ans:=ans-2;
                                end     else  exit;
                        end;
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        readln(m,n);
        for  i:=1  to  n  do
        begin
                readln(x[i],y[i],c[i]);
                f[x[i],y[i]]:=c[i];
                a[x[i],y[i]]:=1;
        end;
        if   (a[m-1,m]=0)  and  (a[m,m-1]=0)  and  (a[m-1,m-1]=0)  then
        begin
                writeln(-1);
                halt;
        end;
        max:=maxlongint;
        for  i:=1  to  m  do
                for  j:=1  to  m  do
                        p[i,j]:=true;
        dfs(1,1);
        if  max=maxlongint  then  writeln(-1)
        else    writeln(max);
        close(input);
        close(output);
end.
