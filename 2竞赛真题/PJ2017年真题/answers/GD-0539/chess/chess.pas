var
        x,y,z,i,n,m,ans,s:longint;
        f:array[0..1000,0..1000] of longint;
        a:array[0..1000,0..1000] of longint;
procedure dg(x,y,x1,y1,total,bz,color:longint);
var
        i,j,xx,yy:longint;
begin
        if (x<=0) or (y<=0) or (y>m) or (x>m) then
                exit;
        if (f[x,y]<=total) then
                exit;
        f[x,y]:=total;
        if (x=m) and (y=m) then
        begin
                s:=1;
                if (ans>total) then
                        ans:=total;
                exit;
        end;
        xx:=x+1;
        yy:=y;
        if (xx<>x1) or (yy<>y1) then
        begin
                if (a[xx,yy]=0) and (bz=0) then
                begin
                        dg(xx,yy,x,y,total+2,1,color);
                        if (color=1) then
                                dg(xx,yy,x,y,total+3,1,2)
                        else
                                dg(xx,yy,x,y,total+3,1,1);
                end
                else
                if (a[xx,yy]<>color) and (a[xx,yy]<>0) then
                begin
                        dg(xx,yy,x,y,total+1,0,a[xx,yy]);
                end
                else
                if (a[xx,yy]<>0) then
                        dg(xx,yy,x,y,total,0,a[xx,yy]);
        end;
        xx:=x;
        yy:=y+1;
        if (xx<>x1) or (yy<>y1) then
        begin
                if (a[xx,yy]=0) and (bz=0) then
                begin
                        dg(xx,yy,x,y,total+2,1,color);
                        if (color=1) then
                                dg(xx,yy,x,y,total+3,1,2)
                        else
                                dg(xx,yy,x,y,total+3,1,1);
                end
                else
                if (a[xx,yy]<>color) and (a[xx,yy]<>0) then
                begin
                        dg(xx,yy,x,y,total+1,0,a[xx,yy]);
                end
                else
                if (a[xx,yy]<>0) then
                        dg(xx,yy,x,y,total,0,a[xx,yy]);
        end;
        xx:=x-1;
        yy:=y;
        if (xx<>x1) or (yy<>y1) then
        begin
                if (a[xx,yy]=0) and (bz=0) then
                begin
                        dg(xx,yy,x,y,total+2,1,color);
                        if (color=1) then
                                dg(xx,yy,x,y,total+3,1,2)
                        else
                                dg(xx,yy,x,y,total+3,1,1);
                end
                else
                if (a[xx,yy]<>color) and (a[xx,yy]<>0) then
                begin
                        dg(xx,yy,x,y,total+1,0,a[xx,yy]);
                end
                else
                if (a[xx,yy]<>0) then
                        dg(xx,yy,x,y,total,0,a[xx,yy]);
        end;
        xx:=x;
        yy:=y-1;
        if (xx<>x1) or (yy<>y1) then
        begin
                if (a[xx,yy]=0) and (bz=0) then
                begin
                        dg(xx,yy,x,y,total+2,1,color);
                        if (color=1) then
                                dg(xx,yy,x,y,total+3,1,2)
                        else
                                dg(xx,yy,x,y,total+3,1,1);
                end
                else
                if (a[xx,yy]<>color) and (a[xx,yy]<>0) then
                begin
                        dg(xx,yy,x,y,total+1,0,a[xx,yy]);
                end
                else
                if (a[xx,yy]<>0) then
                        dg(xx,yy,x,y,total,0,a[xx,yy]);
        end;
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        fillchar(a,sizeof(a),0);
        fillchar(f,sizeof(f),127);
        ans:=maxlongint;
        s:=0;
        readln(m,n);
        for i:=1 to n do
        begin
                readln(x,y,z);
                inc(z);
                a[x,y]:=z;
        end;
        dg(1,1,0,0,0,0,a[1,1]);
        if (s=0) then
                writeln(-1)
        else
        begin
                writeln(ans);
        end;
        close(input);
        close(output);
end.
