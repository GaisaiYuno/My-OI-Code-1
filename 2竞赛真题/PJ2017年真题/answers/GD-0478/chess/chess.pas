var
        i,j,k,m,n,o,p,l,s,t,x,y,z,xx,yy:longint;
        long,a:array[1..200,1..200] of longint;
        spfa:array[1..200,1..200] of boolean;
        way:array[1..4,1..2] of longint=((1,0),(0,1),(-1,0),(0,-1));
        h:array[1..3000000,1..2] of longint;
        kong:array[1..200,1..200] of boolean;
function pd(a:longint):longint;
begin
        if a=0 then exit(maxlongint) else exit(a);
end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(n,m);
        fillchar(kong,sizeof(kong),false);
        for i:=1 to m do begin
                readln(x,y,z);
                a[x,y]:=z;kong[x,y]:=true;
        end;
        h[1,1]:=1;h[1,2]:=2;
        fillchar(spfa,sizeof(spfa),true);
        fillchar(long,sizeof(long),0);
        i:=0;j:=1;
        while i<j do begin
                inc(i);
                //writeln(i);
                if i=1000000 then break;
                x:=h[i,1];y:=h[i,2];
                for k:=1 to 4 do begin
                        xx:=x+way[k,1];
                        yy:=y+way[k,2];
                        if (xx>0) and (yy>0) and (xx<=n) and (yy<=n) then begin
                                if kong[x,y]=false then begin
                                        if (kong[xx,yy])then begin
                                                if a[xx,yy]<>a[x,y] then begin
                                                        if long[x,y]+1<pd(long[xx,yy]) then begin
                                                                if spfa[xx,yy] then begin
                                                                        inc(j);
                                                                        h[j,1]:=xx;h[j,2]:=yy;
                                                                        spfa[xx,yy]:=false;
                                                                end;
                                                                long[xx,yy]:=long[x,y]+1;
                                                                if (xx=n) and (yy=n) then begin
                                                                        writeln(long[xx,yy]);
                                                                        close(input);close(output);
                                                                        exit;
                                                                end;
                                                        end;
                                                end else begin
                                                        if long[x,y]<pd(long[xx,yy]) then begin
                                                                if spfa[xx,yy] then begin
                                                                        inc(j);
                                                                        h[j,1]:=xx;h[j,2]:=yy;
                                                                        spfa[xx,yy]:=false;
                                                                end;
                                                                long[xx,yy]:=long[x,y];
                                                                if (xx=n) and (yy=n) then begin
                                                                        writeln(long[xx,yy]);
                                                                        close(input);close(output);
                                                                        exit;
                                                                end;
                                                        end;
                                                end;
                                        end;
                                        a[x,y]:=2;
                                end else begin
                                        if (kong[xx,yy]) then begin
                                                if a[xx,yy]<>a[x,y] then begin
                                                        if long[x,y]+1<pd(long[xx,yy]) then begin
                                                                if spfa[xx,yy] then begin
                                                                        inc(j);
                                                                        h[j,1]:=xx;h[j,2]:=yy;
                                                                        spfa[xx,yy]:=false;
                                                                end;
                                                                long[xx,yy]:=long[x,y]+1;
                                                                if (xx=n) and (yy=n) then begin
                                                                        writeln(long[xx,yy]);
                                                                        close(input);close(output);
                                                                        exit;
                                                                end;
                                                        end;
                                                end else begin
                                                        if long[x,y]<pd(long[xx,yy]) then begin
                                                                if spfa[xx,yy] then begin
                                                                        inc(j);
                                                                        h[j,1]:=xx;h[j,2]:=yy;
                                                                        spfa[xx,yy]:=false;
                                                                end;
                                                                long[xx,yy]:=long[x,y];
                                                                if (xx=n) and (yy=n) then begin
                                                                        writeln(long[xx,yy]);
                                                                        close(input);close(output);
                                                                        exit;
                                                                end;
                                                        end;
                                                end;
                                        end else begin
                                                if long[x,y]+2<pd(long[xx,yy]) then begin
                                                        if spfa[xx,yy] then begin
                                                                inc(j);
                                                                h[j,1]:=xx;h[j,2]:=yy;
                                                                spfa[xx,yy]:=false;
                                                        end;
                                                        long[xx,yy]:=long[x,y]+2;
                                                        a[xx,yy]:=a[x,y];
                                                        if (xx=n) and (yy=n) then begin
                                                                        writeln(long[xx,yy]);
                                                                        close(input);close(output);
                                                                        exit;
                                                        end;
                                                end;
                                        end;
                                end;
                                //writeln(x,' ',y,' ',long[x,y],' ',xx,' ',yy,' ',long[xx,yy]);
                        end;
                end;
        end;
        if long[n,n]=0 then dec(long[n,n]);
        writeln(long[n,n]);
        close(input);close(output);
end.

