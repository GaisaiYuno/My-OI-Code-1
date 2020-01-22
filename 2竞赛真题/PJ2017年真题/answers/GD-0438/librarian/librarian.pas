var
        a:array[1..1000] of longint;
        long,i,j,n,m:longint;
        st:array[1..1000] of string;
        bo:boolean;
        p,q:string;
        stp:char;
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
              inc(i);
              dec(j);
            end;
        until i>j;
        if i<r then
          qsort(i,r);
        if l<j then
          qsort(l,j);
end;
begin
        assign(input,'librarian.in');
        assign(output,'librarian.out');
        reset(input);
        rewrite(output);
        read(n,m);
        for i:=1 to n do
          read(a[i]);
        qsort(1,n);
        for i:=1 to m do
          begin
            read(long,stp);
            readln(st[i]);
          end;
        for i:=1 to m do
          begin
            bo:=false;
            for j:=1 to n do
              begin
                str(a[j],p);
                delete(p,1,length(p)-length(st[i]));
                if p=st[i] then
                  begin
                    writeln(a[j]);
                    bo:=true;
                    break;
                  end;
              end;
            if bo=false then
              begin
                writeln(-1);
              end;
          end;
        close(input);
        close(output);
end.
