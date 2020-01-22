var
        fx:array[1..4] of longint=(1,0,-1,0);
        fy:array[1..4] of longint=(0,1,0,-1);
        f:array[1..100,1..100,1..2] of longint;
        a:array[1..100,1..100] of longint;
        x,y,i,j,c,n,m,min:longint;
procedure dg(x,y,color:longint);
var
        xx,yy,i:longint;
begin
        for i:=1 to 4 do
          begin
            xx:=x+fx[i];
            yy:=y+fy[i];
            if (xx>0) and (yy>0) and (xx<=n) and (yy<=n) then
              begin
                if not((a[xx,yy]=0) and (a[x,y]=0)) then
                  begin
                        if (a[xx,yy]=0) then
                          begin
                            if a[x,y]=1 then
                              begin
                                if f[xx,yy,1]>f[x,y,1]+2 then
                                  begin
                                    f[xx,yy,1]:=f[x,y,1]+2;
                                    dg(xx,yy,1);
                                  end;
                                if f[xx,yy,2]>f[x,y,1]+3 then
                                  begin
                                    f[xx,yy,2]:=f[x,y,1]+3;
                                    dg(xx,yy,2);
                                  end;
                              end;
                            if a[x,y]=2 then
                              begin
                                if f[xx,yy,1]>f[x,y,2]+3 then
                                  begin
                                    f[xx,yy,1]:=f[x,y,2]+3;
                                    dg(xx,yy,1);
                                  end;
                                if f[xx,yy,2]>f[x,y,2]+2 then
                                  begin
                                    f[xx,yy,2]:=f[x,y,2]+2;
                                    dg(xx,yy,2);
                                  end;
                              end;
                          end
                        else
                          begin
                            if (color=a[xx,yy]) and (f[xx,yy,a[xx,yy]]>f[x,y,color]) then
                              begin
                                f[xx,yy,a[xx,yy]]:=f[x,y,color];
                                dg(xx,yy,a[xx,yy]);
                              end;
                            if (color<>a[xx,yy]) and (f[xx,yy,a[xx,yy]]>f[x,y,color]+1) then
                              begin
                                f[xx,yy,a[xx,yy]]:=f[x,y,color]+1;
                                dg(xx,yy,a[xx,yy]);
                              end;
                          end;
                  end;
              end;
          end;
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        read(n,m);
        fillchar(a,sizeof(a),0);
        for i:=1 to m do
          begin
            read(x,y,c);
            a[x,y]:=c+1;
          end;
        for i:=1 to n do
          for j:=1 to n do
            begin
              f[i,j,1]:=maxlongint div 3;
              f[i,j,2]:=maxlongint div 3;
            end;
        f[1,1,a[1,1]]:=0;
        dg(1,1,a[1,1]);
        if f[n,n,1]<f[n,n,2] then
          min:=f[n,n,1]
        else
          min:=f[n,n,2];
        if min=maxlongint div 3 then
          writeln(-1)
        else
          writeln(min);
        close(input);
        close(output);
end.
