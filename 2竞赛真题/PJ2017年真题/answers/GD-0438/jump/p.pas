var
        a,b:array[1..1000000] of longint;
        n,d,k,i:longint;
procedure qsort(l,r:longint);
var
        i,j,mid,t:longint;
begin
        i:=l;
        j:=r;
        mid:=a[(i+j) div 2];
        repeat
          while (a[i]<mid) do inc(i);
          while (a[j]>mid) do dec(j);
          if i<=j then
            begin
              t:=a[i];
              a[i]:=a[j];
              a[j]:=t;
              t:=b[i];
              b[i]:=b[j];
              b[j]:=t;
              inc(i);
              dec(j);
            end;
        until i>j;
        if I<r then
          qsort(i,r);
        if l<j then
          qsort(l,j);
end;
begin
        assign(input,'jump.in');
        assign(output,'jumps.in');
        reset(input);
        rewrite(output);
        read(n,d,k);
        writeln(n,' ',d,' ',k);
        for i:=1 to n do
          read(a[i],b[i]);
        qsort(1,n);
        for i:=1 to n do
          writeln(a[i],' ',b[i]);
        close(input);
        close(output);
end.
