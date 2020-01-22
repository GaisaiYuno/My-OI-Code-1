var
        x,y,s:array[0..500000]of longint;
        d,n,i,j,k,g,mid,o,r,l,q:longint;
        m:qword;
        t:boolean;
begin
        assign(input,'jump.in');reset(input);
        assign(output,'jump.out');rewrite(output);
        readln(n,d,o);
        for i:=1 to n do
                begin
                  readln(x[i],s[i]);
                  r:=x[i];
                end;
        l:=1;
        r:=r-1;
        x[0]:=0;
        s[0]:=0;
        y[0]:=0;
        for i:=1 to n do
                y[i]:=-maxlongint;
        while l<r-1 do
                begin
                  mid:=(l+r)div 2;
                  if mid>=d then
                        begin
                          i:=1;
                          j:=d+mid;
                        end
                  else
                        begin
                          i:=d-mid;
                          j:=d+mid;
                        end;
                  for k:=1 to n do
                        begin
                          for g:=i-1 downto 0 do
                                begin
                                  if (x[k]>=x[g]+i)and(x[k]<=x[g]+j)then
                                        if y[k]<y[g]+s[k]then
                                                y[k]:=y[g]+s[k];
                                end;
                          if y[k]>m then m:=y[k];
                          if m>o then break;
                        end;
                  if m>=k then
                        begin
                          r:=mid;
                          q:=1;
                        end
                  else l:=mid+1;
                  for k:=1 to n do
                        y[k]:=-maxlongint;
                end;
        if q=1 then writeln(r)
        else writeln(-1);
        close(input);
        close(output);
end.