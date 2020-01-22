var
        a:array[0..100,0..100]of longint;
        d:array[1..10000,1..3]of longint;
        bz:array[0..400,0..400]of boolean;
        mag:array[-1..100,-1..100]of boolean;
        way:array[1..4,1..2]of longint=((-1,0),(1,0),(0,-1),(0,1));
        m,n,i,j,k,x,y,z,min,xx,yy:longint;
        b:boolean;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to n do
        begin
                readln(x,y,z);
                a[x,y]:=z+1;
        end;
        i:=0; j:=1;
        fillchar(bz,sizeof(bz),true); bz[1,1]:=false;
        d[1,1]:=1; d[1,2]:=1; d[1,3]:=0; min:=maxlongint; b:=true;
        fillchar(mag,sizeof(mag),true);
        while i<j do
        begin
                inc(i);
                for k:=1 to 4 do
                begin
                        xx:=d[i,1]+way[k,1];
                        yy:=d[i,2]+way[k,2];
                        if(xx>0)and(xx<=m)and(yy>0)and(yy<=m)then
                        begin
                                if bz[xx,yy]then
                                begin
                                        if a[xx,yy]<>0 then
                                        begin
                                                inc(j);
                                                d[j,1]:=xx; d[j,2]:=yy;
                                                if a[xx,yy]<>a[d[i,1],d[i,2]]then d[j,3]:=d[i,3]+1
                                                else d[j,3]:=d[i,3];
                                                if(d[j,1]=m)and(d[j,2]=m)then
                                                begin
                                                        if d[j,3]<min then min:=d[j,3];
                                                        b:=false;
                                                end;
                                                bz[xx,yy]:=false;
                                                mag[xx+1,yy]:=true; mag[xx-1,yy]:=true; mag[xx,yy+1]:=true; mag[xx,yy-1]:=true;
                                        end
                                        else    if(mag[xx-1,yy])and(mag[xx+1,yy])and(mag[xx,yy-1])and(mag[xx,yy+1])then
                                                begin
                                                        inc(j);
                                                        d[j,1]:=xx; d[j,2]:=yy;
                                                        d[j,3]:=d[i,3]+2;
                                                        if(d[j,1]=m)and(d[j,2]=m)then
                                                        begin
                                                                if d[j,3]<min then min:=d[j,3];
                                                                b:=false;
                                                        end;
                                                        bz[xx,yy]:=false;
                                                        mag[xx,yy]:=false;
                                                end;
                                end;
                        end;
                end;
        end;
        if b then writeln(-1)
        else writeln(min-4);
        close(input);close(output);
end.
