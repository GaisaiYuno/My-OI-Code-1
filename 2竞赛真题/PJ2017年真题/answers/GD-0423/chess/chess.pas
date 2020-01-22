program chess(input,output);
var
  c:array[0..200,0..200] of longint;
  b:array[0..200,0..200] of longint;
  m,n,x,y,i,j,t,s,k,i1,j1,k1:longint;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=1 to n do
   begin
     read(x,y,t);
     c[x,y]:=t;
     b[x,y]:=1;
   end;
  i:=1;j:=1;k:=-1;s:=0;i1:=1;j1:=1;k1:=0;
  while ((i<m) and (j<m)) and (k1<>1) do
   begin
    if b[i+1,j]=1 then
     begin
      if c[i+1,j]=c[i,j] then
       i:=i+1
      else begin s:=s+1;i:=i+1; end;
     end;
    if (b[i,j+1]=1) and (b[i+1,j]=0) then
     begin
      if c[i,j+1]=c[i,j] then
       j:=j+1
      else begin s:=s+1;j:=j+1; end;
     end;
    if (i1=i) and (j1=j) then
      begin
       if (b[i+1,j+1]=1) then begin
        s:=s+2;j:=j+1;
       end else if (i+1<m) and (j+1<m) then k1:=1;
      end;
    i1:=i;j1:=j;
   end;
  if k1<>1 then write(s)
   else write(k);
  close(input);close(output);
end.
