var mile,scores:array[1..500000] of longint;
    score,sum,n,d,coins,i,j,miles,first:longint;
    sign,SmallSign:boolean;
begin
  assign(input,'jump.in');
  reset(input);
  assign(output,'jump.out');
  rewrite(output);
  readln(n,d,score);
  for i:=1 to n do
      readln(mile[i],scores[i]);
  sum:=0;
  for i:=1 to n do
      if scores[i]>0
          then sum:=sum+scores[i];
  if sum<score
     then write(-1)
      else begin
             coins:=0;
             sign:=false;
             while not(sign) do
                   begin
                     inc(coins);
                     sum:=0;
                     miles:=0;
                     if coins<d
                        then first:=d-coins
                         else first:=1;
                     for j:=1 to n do
                                 begin
                                   i:=first;
                                   if j=1
                                    then while (not(smallsign) and (i<=d+coins)) do
                                               begin
                                                 inc(i);
                                                 Smallsign:=(miles+i=mile[1]);
                                               end
                                     else while (not(SmallSign) and (i<=d+coins)) do
                                                begin
                                                  inc(i);
                                                  SmallSign:=(miles+i=mile[j]-mile[j-1]);
                                                end;
                                    if smallsign
                                       then begin
                                              sum:=sum+scores[j];
                                              miles:=miles+i;
                                            end;
                                 end;
                     if (sum>score)
                        then sign:=true;
                   end;
             write(coins);
           end;
  close(input);
  close(output);
end.


