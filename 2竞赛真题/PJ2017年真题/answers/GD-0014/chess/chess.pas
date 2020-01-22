var chesses:array[1..100,1..100] of integer;
    m,n,x,y,c,coins,i,j,k:longint;
    sign:boolean;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  readln(m,n);
  for i:=1 to m do
      for j:=1 to m do
          chesses[i,j]:=-1;
  for i:=1 to n do
      begin
        readln(x,y,c);
        chesses[x,y]:=c;
      end;
  sign:=true;
  i:=1;
  j:=1;
  k:=0;
  coins:=0;
  while ((i<>m) or (j<>m)) and ((chesses[i,j]<>-1) or sign) do
        begin
          inc(k);
          if k mod 2=1
             then inc(j)
              else inc(i);
          if chesses[i,j]=-1
             then
                 if not(sign)
                    then coins:=-1
                     else begin
                            coins:=coins+2;
                            if k mod 2=1
                               then chesses[i,j]:=chesses[i,j-1]
                                else chesses[i,j]:=chesses[i-1,j];
                            sign:=false;
                          end
              else
                  if (k mod 2=1) and (chesses[i,j]<>chesses[i,j-1])
                  or (k mod 2=0) and (chesses[i,j]<>chesses[i-1,j])
                  then coins:=coins+1;
        end;
  writeln(coins);
  close(input);
  close(output);
end.






