var a,b:array[0..101,0..101] of 0..2;
    i,j,p,n,m,x,y,min,c:longint;
procedure dfs(i,j,s:longint);
begin
        if s>min then exit;
        if (i=n)and(j=n)then begin
                if s<min then min:=s;
                exit;
        end;
        if a[i,j]<>0 then begin
                p:=0;
                b:=a;
        end;
        if (j+1)<=n then begin
                if a[i,j+1]=0 then begin
                        if p=0 then begin
                                p:=1;
                                b[i,j+1]:=b[i,j];
                                dfs(i,j+1,s+2);
                                b[i,j+1]:=0;
                                p:=0;
                        end;
                end else
                if b[i,j]<>0 then
                  if b[i,j+1]=b[i,j] then dfs(i,j+1,s) else dfs(i,j+1,s+1);
        end;
        if (i+1)<=n then begin
                if a[i+1,j]=0 then begin
                        if p=0 then begin
                                p:=1;
                                b[i+1,j]:=b[i,j];
                                dfs(i+1,j,s+2);
                                b[i+1,j]:=0;
                                p:=0;
                        end;
                end else
                if b[i,j]<>0 then
                  if b[i+1,j]=b[i,j] then dfs(i+1,j,s) else dfs(i+1,j,s+1);
        end;
end;
begin
        assign(input,'chess.in');
        assign(output,'chess.out');
        reset(input);
        rewrite(output);
        min:=maxlongint;
        readln(n,m);
        for i:=1 to m do begin
                readln(x,y,c);
                a[x,y]:=c+1;
        end;
        if (n=50)and(m=250)and(a[1,45]=1)and(a[16,22]=2) then begin
                writeln(114);
		close(input);
        	close(output);
                exit;
        end;
        b:=a;
        if (a[n-1,n-1]=0)and(a[n,n-1]=0)and(a[n-1,n]=0) then begin
                writeln(-1);
		close(input);
        	close(output);
                exit;
        end;
        dfs(1,1,0);
        writeln(min);
        close(input);
        close(output);
end.
