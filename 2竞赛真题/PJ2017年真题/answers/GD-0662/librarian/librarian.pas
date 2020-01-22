const mo:array[1..8] of int64=(10,100,1000,10000,100000,1000000,10000000,100000000);

var
n,m,i,j,k,tp,ans,count,sum,q,t:longint;
a:array[0..20000] of longint;
c:array[0..20000,0..2] of longint;

procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin


assign(input,'librarian.in');
assign(output,'librarian.out');
reset(input);
rewrite(output);

  readln(n,q);
  for i:=1 to n do readln(a[i]);

  sort(1,n);


  for i:=1 to q do
    begin
      read(c[i,1]); readln(c[i,2]);
    end;

  j:=0;

for i:=1 to q do
  begin
        ans:=-1;

        for j:=1 to n do
        if a[j]>=c[i,2] then
        begin
          if a[j] mod mo[c[i,1]]=c[i,2] then begin writeln(a[j]); ans:=a[j]; break; end;
        end;
       if ans=-1 then writeln(-1);
        //if ans<>-1 then begin writeln(ans); j:=0; ans:=-1; end;
  end;

close(input);
close(output);
end.

















