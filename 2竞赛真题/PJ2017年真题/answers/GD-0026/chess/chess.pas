var
  a,b:array [0..110,0..110] of longint;
  s:array [1..4] of longint;
  i,j,n,m,t:longint;
function min(x,y:longint):longint;
begin
  if (s[x]<s[y]) then min:=x
                 else min:=y;
end;
begin
  assign(input,'chess.in');
  reset(input);
  assign(output,'chess.out');
  rewrite(output);
  readln(m,n);
  for i:=1 to n do
    begin
      read(t,j);
      readln(a[t,j]);
      if a[t,j]=0 then a[t,j]:=2;
    end;
  for i:=1 to m do
    for j:=1 to m do
      begin
        s[1]:=2147483647; s[2]:=s[1]; s[3]:=s[1]; s[4]:=s[1];
        if i-1<>0 then
          begin
            if abs(a[i-1,j])=a[i,j] then s[1]:=b[i-1,j]
                                    else s[1]:=b[i-1,j]+1;
          end;
       {if i+1<m+1 then
          begin
            if abs(a[i+1,j])=a[i,j] then s[2]:=b[i+1,j]
                                    else s[2]:=b[i+1,j]+1;
          end; }
       if j-1<>0 then
          begin
            if abs(a[i,j-1])=a[i,j] then s[3]:=b[i,j-1]
                                    else s[3]:=b[i,j-1]+1;
          end;
       {if j+1<m+1 then
          begin
            if abs(a[i,j+1])=a[i,j] then s[4]:=b[i,j+1]
                                    else s[4]:=b[i,j+1]+1;
          end;}
       if (a[i-1,j]=0) and (a[i+1,j]=0) and (a[i,j-1]=0) and (a[i,j+1]=0) then
         a[i,j]:=0
       else
         begin
           if a[i,j]=0 then
             begin
               if (a[i-1,j]>0) and (i-1<>0) then s[1]:=b[i-1,j]
                                            else s[1]:=2147483647;
               {if a[i+1,j]>0 then s[2]:=b[i+1,j];  }
               if (a[i,j-1]>0) and (j-1<>0) then s[3]:=b[i,j-1]
                                            else s[3]:=2147483647;
               {if a[i,j+1]>0 then s[4]:=b[i,j+1];}
               t:=min(min(1,2),min(3,4));
               if s[t]<>2147483647 then begin
               case t of
                   1:a[i,j]:=-a[i-1,j];
                   {2:a[i,j]:=-a[i+1,j]; }
                   3:a[i,j]:=-a[i,j-1];
                   {4:a[i,j]:=-a[i,j+1];}
                 end;
               b[i,j]:=s[t]+2;
               end
               else b[i,j]:=214748347;
             end
           else
             begin
               t:=min(min(1,2),min(3,4));
               b[i,j]:=s[t];
         end;
         b[1,1]:=0;
       end;
    end;
  if a[m,m]=0 then write(-1)
              else write(b[m,m]);
  close(input);
  close(output);
end.




