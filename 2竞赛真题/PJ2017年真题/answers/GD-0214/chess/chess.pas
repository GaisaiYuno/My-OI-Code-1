const   w:array[1..4,1..2]of longint=((-1,0),(0,1),(1,0),(0,-1));
var     a:array[0..101,0..101]of longint;
        d:array[1..100000,1..5]of longint;
        bz:array[0..101,0..101]of longint;
        m,n,x,y,cl,i,j,st,en,xx,yy,k,min:longint;
        bo:boolean;
begin
        assign(input,'chess.in');
        reset(input);
        assign(output,'chess.out');
        rewrite(output);
        readln(m,n);
        for i:=0 to m+1 do
                for j:=0 to m+1 do a[i,j]:=-1;
        for i:=1 to m do
                for j:=1 to m do bz[i,j]:=maxlongint;
        for i:=1 to n do
        begin
                readln(x,y,cl);
                a[x,y]:=cl;
        end;
        st:=0;
        en:=1;
        d[1,1]:=1;
        d[1,2]:=1;
        d[1,3]:=a[1,1];
        d[1,4]:=0;
        d[1,5]:=1;
        bz[1,1]:=0;
        if m=1 then
        begin
                writeln(0);
                close(input);
                close(output);
                halt;
        end;
        min:=maxlongint;
        while st<en do
        begin
                inc(st);
                for i:=1 to 4 do
                begin
                        bo:=false;
                        xx:=d[st,1]+w[i,1];
                        yy:=d[st,2]+w[i,2];
                        k:=d[st,4];
                        if (a[xx,yy]=-1)and(xx in[1..m])and(yy in[1..m]) then
                        begin
                                if (d[st,5]=1)and(d[st,3]<>-1) then
                                begin
                                        a[xx,yy]:=d[st,3];
                                        k:=k+2;
                                        bo:=true;
                                        d[st,5]:=0;
                                end
                                else continue;
                        end
                        else if a[xx,yy]<>a[d[st,1],d[st,2]]then k:=k+1;
                        if bz[xx,yy]>k then
                        begin
                                inc(en);
                                bz[xx,yy]:=k;
                                d[en,1]:=xx;
                                d[en,2]:=yy;
                                if a[xx,yy]<>-1 then d[en,3]:=a[xx,yy];
                                d[en,4]:=k;
                                d[en,5]:=d[st,5];
                                if (xx=m)and(yy=m)then
                                        if min>d[en,4]then min:=d[en,4];
                        end;
                        if bo then
                        begin
                                a[xx,yy]:=-1;
                                d[st,5]:=1;
                                d[en,5]:=1;
                        end;
                end;
        end;
        if min=maxlongint then writeln(-1)
        else writeln(min);
        close(input);
        close(output);
end.
