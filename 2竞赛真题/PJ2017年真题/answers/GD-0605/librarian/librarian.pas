var

  i,j,k,n,m,x,y,d1,d2,d3,d4,d5,d6,d7,d8,d9,d0:longint;
  a:array[0..1001]of longint;
  a0,a1,a2,a3,a4,a5,a6,a7,a8,a9:array[0..1001]of longint;
  b:array[0..1001]of longint;
  f:longint;
procedure pd(x,y,z:longint);
var
  i,j:longint;
begin
  j:=1;
  for i:=1 to z do
    begin
      j:=j*10;
      if (x mod j)<>(y mod j) then
       begin
         f:=1;
         exit;
       end;
    end;
end;

begin
  assign(input,'librarian.in'); reset(input);
  assign(output,'librarian.out'); rewrite(output);
  readln(n,m);
  for i:=1 to n do
    begin
      readln(x);
      if x mod 10=0  then
        begin
          inc(d0);
          a0[d0]:=x;
        end;
      if x mod 10=1 then

        begin
          inc(d1);
          a1[d1]:=x;
        end;
      if x mod 10=2 then
        begin
          inc(d2);
          a2[d2]:=x;
        end;
      if x mod 10=3 then
        begin
          inc(d3);
          a3[d3]:=x;
        end;
      if x mod 10=4 then
        begin
          inc(d4);
          a4[d4]:=x;
        end;
      if x mod 10=5 then
        begin
          inc(d5);
          a5[d5]:=x;
        end;
      if x mod 10=6 then
        begin
          inc(d6);
          a6[d6]:=x;
        end;
      if x mod 10=7 then
        begin
          inc(d7);
          a7[d7]:=x;
        end;
      if x mod 10=8 then
        begin
          inc(d8);
          a8[d8]:=x;
        end;
      if x mod 10=9 then
        begin
          inc(d9);
          a9[d9]:=x;
        end;
    end;
  for i:=1 to d1-1 do
   for j:=i+1 to d1 do
     begin
       if a1[i]>a1[j] then
         begin
           a1[0]:=a1[i];
           a1[i]:=a1[j];
           a1[j]:=a1[0];
         end;
     end;
  for i:=1 to d2-1 do
   for j:=i+1 to d2 do
     begin
       if a2[i]>a2[j] then
         begin
           a2[0]:=a2[i];
           a2[i]:=a2[j];
           a2[j]:=a2[0];
         end;
     end;
  for i:=1 to d3-1 do
   for j:=i+1 to d3 do
     begin
       if a3[i]>a3[j] then
         begin
           a3[0]:=a3[i];
           a3[i]:=a3[j];
           a3[j]:=a3[0];
         end;
     end;
  for i:=1 to d4-1 do
   for j:=i+1 to d4 do
     begin
       if a4[i]> a4[j] then
         begin
           a4[0]:=a4[i];
           a4[i]:=a4[j];
           a4[j]:=a4[0];
         end;
     end;
  for i:=1 to d5-1 do
   for j:=i+1 to d5 do
     begin
       if a5[i]>a5[j] then
         begin
           a5[0]:=a5[i];
           a5[i]:=a5[j];
           a5[j]:=a5[0];
         end;
     end;


 for i:=1 to d6-1 do
   for j:=i+1 to d6 do
     begin
       if a6[i]>a6[j] then
         begin
           a6[0]:=a6[i];
           a6[i]:=a6[j];
           a6[j]:=a6[0];
         end;
     end;
 for i:=1 to d7-1 do
   for j:=i+1 to d7 do
     begin
       if a7[i]>a7[j] then
         begin
           a7[0]:=a7[i];
           a7[i]:=a7[j];
           a7[j]:=a7[0];
         end;
     end;
 for i:=1 to d8-1 do
   for j:=i+1 to d8 do
     begin
       if a8[i]>a8[j] then
         begin
           a8[0]:=a8[i];
           a8[i]:=a8[j];
           a8[j]:=a8[0];
         end;
     end;
 for i:=1 to d9-1 do
   for j:=i+1 to d9 do
     begin
       if a9[i]>a9[j] then
         begin
           a9[0]:=a9[i];
           a9[i]:=a9[j];
           a9[j]:=a9[0];
         end;
     end;
 for i:=1 to d0-1 do
   for j:=i+1 to d0 do
     begin
       if a0[i]>a0[j] then
         begin
           a0[0]:=a0[i];
           a0[i]:=a0[j];
           a0[j]:=a0[0];
         end;
     end;







  for i:=1 to m do
    begin
      readln(x,y);
      if y mod 10=1 then
        begin
          for j:=1 to d1 do
            begin
              f:=0;
              pd(y,a1[j],x);
              if f=0 then
                begin
                  b[i]:=a1[j];
                  break;
                end;
            end;
        end;
      if y mod 10=2 then
        begin
          for j:=1 to d2 do
            begin
              f:=0;
              pd(y,a2[j],x);
              if f=0 then
                begin
                  b[i]:=a2[j];
                  break;
                end;
            end;
        end;
      if y mod 10=3 then
        begin
          for j:=1 to d3 do
            begin
              f:=0;
              pd(y,a3[j],x);
              if f=0 then
                begin
                  b[i]:=a3[j];
                  break;
                end;
            end;
        end;
      if y mod 10=4 then
        begin
          for j:=1 to d4 do
            begin
              f:=0;
              pd(y,a4[j],x);
              if f=0 then
                begin
                  b[i]:=a4[j];
                  break;
                end;
            end;
        end;
      if y mod 10=5 then
        begin
          for j:=1 to d5 do
            begin
              f:=0;
              pd(y,a5[j],x);
              if f=0 then
                begin
                  b[i]:=a5[j];
                  break;
                end;
            end;
        end;
      if y mod 10=6 then
        begin
          for j:=1 to d6 do
            begin
              f:=0;
              pd(y,a6[j],x);
              if f=0 then
                begin
                  b[i]:=a6[j];
                  break;
                end;
            end;
        end;
      if y mod 10=7 then
        begin
          for j:=1 to d7 do
            begin
              f:=0;
              pd(y,a7[j],x);
              if f=0 then
                begin
                  b[i]:=a7[j];
                  break;
                end;
            end;
        end;
      if y mod 10=8 then
        begin
          for j:=1 to d8 do
            begin
              f:=0;
              pd(y,a8[j],x);
              if f=0 then
                begin
                  b[i]:=a8[j];
                  break;
                end;
            end;
        end;
      if y mod 10=9 then
        begin
          for j:=1 to d9 do
            begin
              f:=0;
              pd(y,a9[j],x);
              if f=0 then
                begin
                  b[i]:=a9[j];
                  break;
                end;
            end;
        end;
      if y mod 10=0 then
        begin
          for j:=1 to d0 do
            begin
              f:=0;
              pd(y,a0[j],x);
              if f=0 then
                begin
                  b[i]:=a0[j];
                  break;
                end;
            end;
        end;
    end;



  for i:=1 to n do
    if b[i]=0
      then writeln('-1')
      else writeln(b[i]);

  close(input);
  close(output);
end.






















