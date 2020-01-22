var n,q,i,j,book,people,ans,c,t:longint;
    a,b:array[0..10000,1..10]of longint;
    bo,pe:array[1..10000]of longint;
function check(x,y:longint):longint;
var t,i,tot:longint;
begin
     if a[x,0]<b[y,0] then exit(-1) else
     begin
          t:=1;
          for i:=1 to b[y,0] do
          begin
               if a[x,i]<>b[y,i] then begin t:=0; exit(-1); end;
          end;
          if t=1 then
          begin
               tot:=0;
               for i:=a[x,0] downto 1 do
               begin
                    tot:=tot*10+a[x,i];
               end;
               exit(tot);
          end;
     end;
end;
begin
     assign(input,'librarian.in');reset(input);
     assign(output,'librarian.out');rewrite(output);
     read(n,q);
     for i:=1 to n do
     begin
          read(bo[i]);
          t:=bo[i];
          while t>0 do
          begin
               inc(a[i,0]);
               a[i,a[i,0]]:=t mod 10;
               t:=t div 10;
          end;
     end;
     for i:=1 to q do
     begin
          read(c,pe[i]);
          t:=pe[i];
          while t>0 do
          begin
               inc(b[i,0]);
               b[i,b[i,0]]:=t mod 10;
               t:=t div 10;
          end;
     end;
     for j:=1 to q do
     begin
          ans:=0;
          for i:=1 to n do
          begin
               if check(i,j)>0 then
               begin
                    if ans=0 then ans:=check(i,j)
                    else
                    begin
                         if ans>check(i,j) then ans:=check(i,j);
                    end;
               end;
          end;
          if ans=0 then ans:=-1;
          writeln(ans);
     end;
     {for i:=1 to n do
     begin
          for j:=1 to a[i,0] do
          write(a[i,j]:2);
          writeln;
     end;
     for i:=1 to n do
     begin
          for j:=1 to b[i,0] do
          write(b[i,j]:2);
          writeln;
     end;}
     close(input);close(output);
end.
