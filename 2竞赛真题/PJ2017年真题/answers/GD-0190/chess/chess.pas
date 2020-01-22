const
        u:array[1..4] of -1..1=(-1,0,1,0);
        v:array[1..4] of -1..1=(0,1,0,-1);
var
        n,m,i,j,k,a,b,c,lxn:longint;
        f:array[0..101,0..101] of longint;
        ans:array[0..101,0..101,1..2] of longint;
        bz1:array[0..101,0..101] of boolean;
function min(aa,bb:longint):longint;
begin
        if aa<bb then exit(aa)
        else
                exit(bb);
end;
{procedure search(x,y,s,l:longint;bz:boolean);
var
        k,xx,yy:longint;
begin
        if (x=n) and (y=n) then
        begin
                lxn:=min(lxn,s);
                exit;
        end;
        for k:=1 to 4 do
        begin
                xx:=x+u[k];
                yy:=y+v[k];
                if (xx>0) and (xx<=n) and (yy>0) and (yy<=n) and (bz1[xx,yy]=false) then
                begin
                        if f[xx,yy]=0 then
                        begin
                                if bz then
                                begin
                                        bz1[xx,yy]:=true;
                                        search(xx,yy,s+2+abs(1-l),1,false);
                                        search(xx,yy,s+2+abs(2-l),2,false);
                                        bz1[xx,yy]:=false;
                                end;
                        end
                        else
                        begin
                                bz1[xx,yy]:=true;
                                search(xx,yy,s+abs(l-f[xx,yy]),f[xx,yy],true);
                                bz1[xx,yy]:=false;
                        end;
                end;
        end;
end;   }
procedure suan;
var
        x,y:longint;
begin
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        ans[i,j,1]:=maxlongint div 3;
                        ans[i,j,2]:=maxlongint div 3;
                end;
        end;
        ans[1,1,f[1,1]]:=0;
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        for k:=1 to 4 do
                        begin
                                x:=i+u[k];
                                y:=j+v[k];
                                if (x>0) and (x<=n) and (y>0) and (y<=n) then
                                begin
                                        if f[i,j]=0 then
                                        begin
                                                if f[x,y]<>0 then
                                                begin
                                                        ans[i,j,1]:=min(ans[i,j,1],ans[x,y,f[x,y]]+2+abs(1-f[x,y]));
                                                        ans[i,j,2]:=min(ans[i,j,2],ans[x,y,f[x,y]]+2+abs(2-f[x,y]));
                                                end;
                                        end
                                        else
                                        begin
                                                if f[x,y]=0 then
                                                begin
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,1]+abs(1-f[i,j]));
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,2]+abs(2-f[i,j]));
                                                end
                                                else
                                                begin
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,f[x,y]]+abs(f[i,j]-f[x,y]));
                                                end;
                                        end;
                                end;
                        end;
                end;
        end;
        for i:=1 to n do
        begin
                for j:=1 to n do
                begin
                        for k:=1 to 4 do
                        begin
                                x:=i+u[k];
                                y:=j+v[k];
                                if (x>0) and (x<=n) and (y>0) and (y<=n) then
                                begin
                                        if f[i,j]=0 then
                                        begin
                                                if f[x,y]<>0 then
                                                begin
                                                        ans[i,j,1]:=min(ans[i,j,1],ans[x,y,f[x,y]]+2+abs(1-f[x,y]));
                                                        ans[i,j,2]:=min(ans[i,j,2],ans[x,y,f[x,y]]+2+abs(2-f[x,y]));
                                                end;
                                        end
                                        else
                                        begin
                                                if f[x,y]=0 then
                                                begin
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,1]+abs(1-f[i,j]));
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,2]+abs(2-f[i,j]));
                                                end
                                                else
                                                begin
                                                        ans[i,j,f[i,j]]:=min(ans[i,j,f[i,j]],ans[x,y,f[x,y]]+abs(f[i,j]-f[x,y]));
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
        read(n,m);
        fillchar(f,sizeof(f),0);
        for i:=1 to m do
        begin
                read(a,b,c);
                if c=0 then f[a,b]:=2
                else
                        f[a,b]:=1;
        end;
        {if n<=5 then
        begin
                lxn:=maxlongint;
                fillchar(bz1,sizeof(bz1),false);
                search(1,1,0,f[1,1],true);
        end
        else  }
        begin
                suan;
                if f[n,n]=0 then lxn:=min(ans[n,n,1],ans[n,n,2])
                else
                        lxn:=ans[n,n,f[n,n]];
        end;
        if lxn=maxlongint then lxn:=-1;
        write(lxn);
        close(input);
        close(output);
end.