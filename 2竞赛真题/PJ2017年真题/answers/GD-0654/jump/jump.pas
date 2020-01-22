var n,d,k,i,ss,ans,w,g:longint;
    x,s:array[0..1000000] of longint;
begin
  assign(input,'jump.in');
  assign(output,'jump.out'); 
  reset(input);
  rewrite(output);
  readln(n,d,k);
  for i:=1 to n do
      readln(x[i],s[i]);
  g:=-1;
  repeat
    inc(g);
    ss:=0;
    ans:=0;
    if g<d then
       begin
         for i:=1 to n do
             begin
             if (x[i]>=ss+d-g) and (x[i]<=ss+d+g) then
                ans:=ans+s[i];
             if ans>=k then w:=1;
             if w=1 then break;
             end;
         if w=1 then break;

       end;
    if g>=d then
       begin
         for i:=1 to n do
             begin
               if (x[i]>=ss+1) and (x[i]<=ss+d+g) then
                  ans:=ans+s[i];
               if ans>=k then w:=1;
               if w=1 then break;
             end;
       end;
  until w=1;
  writeln(g);

  close(input);
  close(output);
end.
