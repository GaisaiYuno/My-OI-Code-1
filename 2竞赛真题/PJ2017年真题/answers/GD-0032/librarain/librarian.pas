var a:array[0..1001] of longint;
    b:array[0..1001,1..2] of longint;
    n,m,i,j,s:longint;
    p:boolean;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do inc(i);
           while x<a[j] do dec(j);
           if not(i>j) then begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then sort(l,j);
         if i<r then sort(i,r);
end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        readln(n,m);
        for i:=1 to n do readln(a[i]);
        for i:=1 to m do readln(b[i,1],b[i,2]);
        sort(1,n);
        for i:=1 to m do begin
                s:=1;
                p:=false;
                for j:=1 to b[i,1] do s:=s*10;
                for j:=1 to n do begin
                        if a[j] mod s=b[i,2] then begin
                                writeln(a[j]);
                                p:=true;
                                break;
                        end;
                end;
                if not(p) then writeln(-1);
        end;
        close(input);
        close(output);
end.
