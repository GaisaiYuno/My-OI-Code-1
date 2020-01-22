var
        a:array[1..1001,1..1001]of longint;
        b:array[1..1001,1..1001]of boolean;
        i,j,k,n,m,x,y,c,q,ans:longint;
procedure js(i,j,k,z:longint);
        begin
                if (i=m)and(j=m)then
                        begin
                          q:=1;
                          if z<ans then ans:=z;
                          exit;
                        end;
                b[i,j]:=true;
                if (b[i,j+1]<>true)and(j+1<=m) then
                        begin
                          if a[i,j+1]<>0 then
                                begin
                                  if a[i,j+1]<>a[i,j]then
                                        begin
                                          js(i,j+1,0,z+1);
                                        end
                                  else js(i,j+1,0,z);
                                end
                          else
                                if k<>1 then
                                        begin
                                          a[i,j+1]:=a[i,j];
                                          js(i,j+1,1,z+2);
                                          a[i,j+1]:=0;
                                        end;
                        end;
                if (b[i+1,j]<>true)and(i+1<=m) then
                        begin
                          if a[i+1,j]<>0 then
                                begin
                                  if a[i+1,j]<>a[i,j]then
                                        begin
                                          js(i+1,j,0,z+1);
                                        end
                                  else js(i+1,j,0,z);
                                end
                          else
                                if k<>1 then
                                        begin
                                          a[i+1,j]:=a[i,j];
                                          js(i+1,j,1,z+2);
                                          a[i+1,j]:=0;
                                        end;
                        end;
                if (b[i,j-1]<>true)and(j-1>=1) then
                        begin
                          if a[i,j-1]<>0 then
                                begin
                                  if a[i,j-1]<>a[i,j]then
                                        begin
                                          js(i,j-1,0,z+1);
                                        end
                                  else js(i,j-1,0,z);
                                end
                          else
                                if k<>1 then
                                        begin
                                          a[i,j-1]:=a[i,j];
                                          js(i-1,j,1,z+2);
                                          a[i,j-1]:=0;
                                        end;
                        end;
                if (b[i-1,j]<>true)and(i-1>=1) then
                        begin
                          if a[i-1,j]<>0 then
                                begin
                                  if a[i-1,j]<>a[i,j]then
                                        begin
                                          js(i-1,j,0,z+1);
                                        end
                                  else js(i-1,j,0,z);
                                end
                          else
                                if k<>1 then
                                        begin
                                          a[i-1,j]:=a[i-1,j];
                                          js(i-1,j,1,z+2);
                                          a[i-1,j]:=0;
                                        end;
                        end;
                b[i,j]:=false;
        end;
begin
        assign(input,'chess.in');reset(input);
        assign(output,'chess.out');rewrite(output);
        readln(m,n);
        for i:=1 to n do
                begin
                  readln(x,y,c);
                  if c=1 then
                        a[x,y]:=1
                  else
                        a[x,y]:=-1;
                end;
        ans:=maxlongint;
        js(1,1,0,0);
        if q=1 then writeln(ans)
        else writeln(-1);
        close(input);close(output);
end.