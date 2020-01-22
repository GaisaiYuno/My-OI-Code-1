const
tx:array[1..4]of longint=(0,1,-1,0);
ty:array[1..4]of longint=(1,0,0,-1);
var
m,n,i,x,y,c,j,ans,bz:longint;
a,f:array[-10..110,-10..110]of longint;

procedure dfs(x,y,s,tj:longint);
var
i:longint;
begin
    if (x<1)or(x>m)or(y<1)or(y>m) then exit;
    if tj>=ans then exit;
    if (x=m)and(y=m) then
    begin
        if tj<ans then ans:=tj;
        exit;
    end;
    for i:=1 to 4 do
    if f[x+tx[i],y+ty[i]]=0 then
    begin
        f[x+tx[i],y+ty[i]]:=1;
        if (a[x,y]=a[x+tx[i],y+ty[i]])and(a[x,y]<>2) then dfs(x+tx[i],y+ty[i],1,tj) else
        if (a[x,y]=a[x+tx[i],y+ty[i]])and(a[x,y]=2) then inc(bz) else
        if (a[x,y]<>a[x+tx[i],y+ty[i]])and(a[x+tx[i],y+ty[i]]<>2) then dfs(x+tx[i],y+ty[i],1,tj+1) else
        if (a[x,y]<>a[x+tx[i],y+ty[i]])and(a[x+tx[i],y+ty[i]]=2)and(s=1) then
        begin
            a[x+tx[i],y+ty[i]]:=0;
            if a[x,y]=1 then dfs(x+tx[i],y+ty[i],0,tj+3) else dfs(x+tx[i],y+ty[i],0,tj+2);
            a[x+tx[i],y+ty[i]]:=1;
            if a[x,y]=0 then dfs(x+tx[i],y+ty[i],0,tj+3) else dfs(x+tx[i],y+ty[i],0,tj+2);
            a[x+tx[i],y+ty[i]]:=2;
        end else
        if (a[x,y]<>a[x+tx[i],y+ty[i]])and(a[x+tx[i],y+ty[i]]=2)and(s=0) then inc(bz);
        f[x+tx[i],y+ty[i]]:=0;
    end;
end;

begin
    assign(input,'chess.in');
    reset(input);
    assign(output,'chess.out');
    rewrite(output);
    readln(m,n);
    for i:=1 to m do
    for j:=1 to m do
    a[i,j]:=2;
    for i:=1 to n do
    begin
        read(x,y,c);
        a[x,y]:=c;
    end;
    if (a[m-1,m-1]=2)and(a[m-1,m]=2)and(a[m,m-1]=2)and(a[m,m-2]=2)and(a[m-2,m]=2) then
    begin
        write(-1);
        close(input);
        close(output);
        halt;
    end;

    fillchar(f,sizeof(f),0);
    f[1,1]:=1;bz:=0;
    ans:=maxlongint;
    dfs(1,1,1,0);
    if ans=maxlongint then write(-1) else write(ans);
    close(input);
    close(output);
end.
