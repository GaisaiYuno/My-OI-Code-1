var
        a:array[0..200,0..200]of longint;
        n,m,i,j,n1,n2,ans:longint;
function pd(i,j:longint):boolean;
begin
        if(i>0)and(i<=n)and(j>0)and(j<=n)then exit(true);
        exit(false);
end;
procedure dg(i,j,k,c:longint;bz1:boolean);
var
        f1,f2:boolean;
begin
        if(i=n)and(j=n)then
        begin
                if k<ans then ans:=k;
                exit;
        end;
        f1:=pd(i+1,j);
        if (f1)and((bz1)or(a[i+1,j]<>-1)) then
        begin
                if a[i+1,j]=-1 then dg(i+1,j,k+2,c,false)
                else if c<>a[i+1,j] then dg(i+1,j,k+1,a[i+1,j],true)
                else if c=a[i+1,j] then dg(i+1,j,k,c,true);
        end;
        f2:=pd(i,j+1);
        if (f1)and((bz1)or(a[i,j+1]<>-1)) then
        begin
                if a[i,j+1]=-1 then dg(i,j+1,k+2,c,false)
                else if a[i,j]<>a[i,j+1] then dg(i,j+1,k+1,a[i,j+1],true)
                else if a[i,j]=a[i,j+1] then dg(i,j+1,k,c,true);
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(n,m);
        for i:=0 to n do
        for j:=0 to n do
        a[i,j]:=-1;
        for i:=1 to m do
        begin
                read(n1,n2);
                readln(a[n1,n2]);
        end;
        if(a[n,n]=-1)and(a[n,n-1]=-1)and(a[n-1,n]=-1)then
        begin
                writeln(-1);
                halt;
        end;
        if(a[n,n-1]=-1)and(a[n-1,n]=-1)and(a[n,n-2]=-1)and(a[n-2,n]=-1)and(a[n-1,n-1]=-1)then
        begin
                writeln(-1);
                halt;
        end;
        ans:=2147483647;
        dg(1,1,0,a[1,1],true);
        if ans=2147483647 then writeln(-1)
        else writeln(ans);
        close(input);close(output);
end.
