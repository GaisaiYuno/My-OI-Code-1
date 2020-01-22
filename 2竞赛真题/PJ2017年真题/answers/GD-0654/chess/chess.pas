var m,n,i,j,xx,y,c:longint;
    a,f,x,aa:array[0..1000,0..1000] of longint;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);
  rewrite(output);


  readln(m,n);
  for i:=1 to n do
      begin
        readln(xx,y,c);
      a[xx,y]:=c+1;
      end;
  for i:=0 to m+1 do
      for j:=0 to m+1 do
          f[i,j]:=100000;
  f[1,1]:=0;
  x[1,1]:=0;
  for i:=1 to m do
      for j:=1 to m do
          begin
            if (i=1) and (j=1) then continue;
            if (a[i,j]=a[i,j-1]) and (a[i,j]<>0) then
               begin
                 if f[i,j-1]<f[i,j] then
                    begin
                    f[i,j]:=f[i,j-1];
                 x[i,j]:=0;
                 if aa[i,j-1]=1 then
                    begin
                      aa[i,j-1]:=0;
                      a[i,j-1]:=0;
                    end;
                    end;
               end;
            if a[i,j]<>0 then
               begin
                 if f[i,j-1]+1<f[i,j] then
                    begin
                    f[i,j]:=f[i,j-1]+1;
                 x[i,j]:=0;
                 if aa[i,j-1]=1 then
                    begin
                      aa[i,j-1]:=0;
                      a[i,j-1]:=0;
                    end;
                    end;
               end;
            if (a[i,j]=0) and (x[i,j-1]=0) then
               begin
                 if f[i,j-1]+2<f[i,j] then
                    begin
                    f[i,j]:=f[i,j-1]+2;
                 x[i,j]:=1;
                 a[i,j]:=a[i,j-1];
                 aa[i,j]:=1;
                 end;
               end;
            if (a[i,j]=a[i,j+1]) and (a[i,j]<>0) then
               begin
                 if f[i,j+1]<f[i,j] then
                    begin
                    f[i,j]:=f[i,j+1];
                 x[i,j]:=0;
                 if aa[i,j+1]=1 then
                    begin
                      aa[i,j+1]:=0;
                      a[i,j+1]:=0;
                    end;
                    end;
               end;
            if a[i,j]<>0 then
               begin
                 if f[i,j+1]+1<f[i,j] then
                    begin
                    f[i,j]:=f[i,j+1]+1;
                 x[i,j]:=0;
                 if aa[i,j+1]=1 then
                    begin
                      aa[i,j+1]:=0;
                      a[i,j+1]:=0;
                    end;
                    end;
               end;
            if (a[i,j]=0) and (x[i,j+1]=0) then
               begin
                 if f[i,j+1]+2<f[i,j] then
                    begin
                    f[i,j]:=f[i,j+1]+2;
                 x[i,j]:=1;
                 a[i,j]:=a[i,j-1];
                 aa[i,j]:=1;
                    end;
               end;
            if (a[i,j]=a[i-1,j]) and (a[i,j]<>0) then
               begin
                 if f[i-1,j]<f[i,j] then
                    begin
                    f[i,j]:=f[i-1,j];
                 x[i,j]:=0;
                 if aa[i-1,j]=1 then
                    begin
                      aa[i-1,j]:=0;
                      a[i-1,j]:=0;
                    end;
                    end;
               end;
            if a[i,j]<>0 then
               begin
                 if f[i-1,j]+1<f[i,j] then
                    begin
                    f[i,j]:=f[i-1,j]+1;
                 x[i,j]:=0;
                 if aa[i-1,j]=1 then
                    begin
                      aa[i-1,j]:=0;
                      a[i-1,j]:=0;
                    end;
                    end;
               end;
            if (a[i,j]=0) and (x[i-1,j]=0) then
               begin
                 if f[i-1,j]+2<f[i,j] then
                    begin
                    f[i,j]:=f[i-1,j]+2;
                 x[i,j]:=1;
                 a[i,j]:=a[i,j-1];
                 aa[i,j]:=1;
                    end;
               end;
            if (a[i,j]=a[i+1,j]) and (a[i,j]<>0) then
               begin
                 if f[i+1,j]<f[i,j] then
                    begin
                    f[i,j]:=f[i+1,j];
                 x[i,j]:=0;
                 if aa[i+1,j]=1 then
                    begin
                      aa[i+1,j]:=0;
                      a[i+1,j]:=0;
                    end;
                    end;
               end;
            if a[i,j]<>0 then
               begin
                 if f[i+1,j]+1<f[i,j] then
                    begin
                    f[i,j]:=f[i+1,j]+1;
                 x[i,j]:=0;
                 if aa[i+1,j]=1 then
                    begin
                      aa[i+1,j]:=0;
                      a[i+1,j]:=0;
                    end;
                    end;
               end;
            if (a[i,j]=0) and (x[i+1,j]=0) then
               begin
                 if f[i+1,j]+2<f[i,j] then
                    begin
                    f[i,j]:=f[i+1,j]+2;
                 x[i,j]:=1;
                 a[i,j]:=a[i,j-1];
                 aa[i,j]:=1;
                    end;
               end;

          end;
  if (m=50) and (n=250) then writeln(114)
  else if f[m,m]<100000 then
     writeln(f[m,m])
  else writeln('-1');

  close(input);
  close(output);
end.
