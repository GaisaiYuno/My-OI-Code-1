Var
        nd:array[1..2,1..2]of integer;
        m,n,head,tail,i,j,min,h,l:longint;
        cs:array[1..999999]of boolean;
        f,a:array[0..110,0..110]of longint;
        x,y,ys:array[1..999999]of longint;

Begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);

        nd[1,1]:=1; nd[1,2]:=0;
        nd[2,2]:=1; nd[2,1]:=0;
        readln(m,n);
        for i:=1 to m do
                for j:=1 to m do
                        a[i,j]:=maxint;

        for i:=1 to n do
        begin
                readln(head,tail,j);
                a[head,tail]:=j;
        end;

        for i:=1 to m do
                for j:=1 to m do
                        f[i,j]:=maxlongint;
        min:=maxlongint;
        head:=0; tail:=1;
        f[1,1]:=0;
        tail:=1; cs[1]:=true;
        x[1]:=1; y[1]:=1;
        ys[1]:=a[1,1];
        repeat

                inc(head);
                if (x[head]=m) and (y[head]=m) then
                        if min>f[m,m] then
                                min:=f[m,m];
                for i:=1 to 2 do
                begin
                        h:=x[head]+nd[i,1];
                        l:=y[head]+nd[i,2];
                        if (h>=1) and (h<=m) and (l>=1) and (l<=m) then
                        begin
                                if a[h,l]<>maxint then
                                begin
                                        if a[h,l]<>ys[head] then
                                                if f[x[head],y[head]]+1<f[h,l] then
                                                begin
                                                        inc(tail);
                                                        ys[tail]:=a[h,l];
                                                        cs[tail]:=true;
                                                        x[tail]:=h;
                                                        y[tail]:=l;
                                                        f[h,l]:=f[x[head],y[head]]+1;
                                                end;
                                        if a[h,l]=ys[head] then
                                                if f[x[head],y[head]]<f[h,l] then
                                                begin
                                                        inc(tail);
                                                        ys[tail]:=a[h,l];
                                                        cs[tail]:=true;
                                                        x[tail]:=h;
                                                        y[tail]:=l;
                                                        f[h,l]:=f[x[head],y[head]];
                                                end;
                                end;

                                if (a[h,l]=maxint) and (cs[head]) then
                                        if f[x[head],y[head]]+2<f[h,l] then
                                        begin
                                                inc(tail);
                                                ys[tail]:=ys[head];
                                                cs[tail]:=false;
                                                x[tail]:=h;
                                                y[tail]:=l;
                                                f[h,l]:=f[x[head],y[head]]+2;
                                        end;
                        end;
                end;
        until head>tail;

        if min=maxlongint then
                writeln(-1)
        else
                writeln(min);
        readln;

close(input);close(output);
End.

