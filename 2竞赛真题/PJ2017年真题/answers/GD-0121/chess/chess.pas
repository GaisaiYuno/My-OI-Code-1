var n,m,i,l,r,a,ans,j:longint;
    x:array[-10..110,-10..110]of longint;
    //y:array[1..100,1..100]of longint;
    f:array[1..100,1..100]of boolean;
function min(a:longint;b:longint):longint;
begin
        if(a<b) then
                exit(a)
        else
                exit(b);
end;

procedure ss(sum:longint;l:longint;r:longint;p:boolean);
var i,j,k:longint;
begin
        if(sum>ans) then exit;
        if(l=n) and(r=n) then begin
                ans:=min(ans,sum);
                exit;
        end;
        if(f[l,r]=false) then exit;
        f[l,r]:=false;
        if(l-1>0) then begin
                if(x[l-1,r]=x[l,r])and(x[l-1,r]<>-1) then
                        ss(sum,l-1,r,true)
                else
                if((x[l-1,r]=1) and (x[l,r]=0)) or ((x[l-1,r]=0) and (x[l,r]=1)) then
                        ss(sum+1,l-1,r,true)
                else if(p) then begin
                        i:=x[l-1,r];
                        x[l-1,r]:=x[l,r];
                        ss(sum+2,l-1,r,false);
                        x[l-1,r]:=i;
                end;
        end;
        if(l+1<=n) then begin
                if(x[l+1,r]=x[l,r])and(x[l+1,r]<>-1) then
                        ss(sum,l+1,r,true)
                else
                if((x[l+1,r]=1) and (x[l,r]=0)) or ((x[l+1,r]=0) and (x[l,r]=1)) then
                        ss(sum+1,l+1,r,true)
                else
                if(p) then begin
                        i:=x[l+1,r];
                        x[l+1,r]:=x[l,r];
                        ss(sum+2,l+1,r,false);
                        x[l+1,r]:=i;
                end;
        end;
        if(r-1>0) then begin
                if(x[l,r-1]=x[l,r])and(x[l,r-1]<>-1) then
                        ss(sum,l,r-1,true)
                else
                if((x[l,r-1]=1) and (x[l,r]=0)) or ((x[l,r-1]=0) and (x[l,r]=1)) then
                        ss(sum+1,l,r-1,true)
                else if(p) then begin
                        i:=x[l,r-1];
                        x[l,r-1]:=x[l,r];
                        ss(sum+2,l,r-1,false);
                        x[l,r-1]:=i;
                end;
        end;
        if(r+1<=n) then begin
                if(x[l,r+1]=x[l,r])and(x[l,r+1]<>-1) then
                        ss(sum,l,1+r,true)
                else
                if((x[l,r+1]=1) and (x[l,r]=0)) or ((x[l,1+r]=0) and (x[l,r]=1)) then
                        ss(sum+1,l,r+1,true)
                else
                if(p) then begin
                        i:=x[l,r+1];
                        x[l,r+1]:=x[l,r];
                        ss(sum+2,l,r+1,false);
                        x[l,r+1]:=i;
                end;
        end;
        f[l,r]:=true;
end;

begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        ans:=30000;
        fillchar(f,sizeof(f),true);
        for i:=1 to 100 do for j:=1 to 100 do begin x[i,j]:=-1;end;
        readln(n,m);
        for i:=1 to m do begin
                readln(l,r,a);
                x[l,r]:=a;
        end;
        //f[1,1]:=false;
        //y[1,1]:=0;
        if(n>m) then begin
                writeln(-1);
                close(input);
                close(output);
                exit;
        end;
        ss(0,1,1,true);
        if(ans=30000) then writeln(-1)
        else
                writeln(ans);
        close(input);
        close(output);
end.

