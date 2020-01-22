var
        f:array[1..500001] of int64;
        a,b:array[1..500001] of longint;
        bo:boolean;
        ans:int64;
        j,l,r,left,right,left1,right1,l1,r1,left2,right2,l2,r2,mid,mid1,mid2,mid3,i,n,d,k:longint;
begin
        assign(input,'jump.in');
        assign(output,'jump.out');
        reset(input);
        rewrite(output);
        read(n,d,k);
        a[1]:=0;
        r:=0;
        for i:=2 to n+1 do
          begin
            read(a[i],b[i]);
            if b[i]>0 then
             ans:=ans+b[i];
            if r<a[i] then
              r:=a[i];
          end;
        if ans<k then
          begin
            writeln(-1);
            close(input);
            close(output);
            halt;
          end;
        inc(n);
        if n<=1000 then
          begin
            l:=1;
            ans:=0;
            while (l<=r) do
              begin
                mid:=(l+r) div 2;
                bo:=false;
                left:=d-mid;
                if left<=0 then
                  left:=1;
                right:=d+mid;
                for i:=1 to n do
                  f[i]:=-maxlongint div 3;
                f[1]:=0;
                bo:=false;
                for i:=1 to n do
                  begin
                    if f[i]=-maxlongint div 3 then
                      continue;
                    for j:=i+1 to n do
                      begin
                        if (a[j]-a[i]>=left) and (a[j]-a[i]<=right) then
                          begin
                            if f[j]<f[i]+b[j] then
                              begin
                                f[j]:=f[i]+b[j];
                                if f[j]>=k then
                                  begin
                                    bo:=true;
                                    break;
                                  end;
                              end;
                          end;
                      end;
                  if bo then
                    break;
                end;
              if bo then
                begin
                  r:=mid-1;
                  ans:=mid;
                end
              else
                begin
                  l:=mid+1;
                end;
             end;
             writeln(ans);
             close(input);
             close(output);
             halt;
          end;
        l:=1;
        ans:=0;
        while (l<=r) do
          begin
            mid:=(l+r) div 2;
            bo:=false;
            left:=d-mid;
            if left<=0 then
              left:=1;
            right:=d+mid;
            for i:=1 to n do
              f[i]:=-maxlongint div 3;
            f[1]:=0;
            bo:=false;
            for i:=1 to n do
              begin
                if f[i]=-maxlongint div 3 then
                  continue;
                left1:=a[i]+left;
                right1:=a[i]+right;
                l1:=1;
                r1:=n;
                left2:=0;
                while (l1<=r1) do
                  begin
                    mid1:=(l1+r1) div 2;
                    if a[mid1]-a[i]<left then
                      begin
                        l1:=mid1+1;
                      end
                    else
                      begin
                        r1:=mid1-1;
                        left2:=mid1;
                      end;
                  end;
                if left2=0 then
                  break;
                l2:=1;
                r2:=n;
                right2:=0;
                while (l2<=r2) do
                  begin
                    mid1:=(l2+r2) div 2;
                    if a[mid1]-a[i]<=right then
                      begin
                        right2:=mid1;
                        l2:=mid1+1;
                      end
                    else
                      begin
                        r2:=mid1-1;
                      end;
                  end;
                 {for j:=i+1 to n do
                   begin
                     if (a[j]-a[i]>=left) and (a[j]-a[i]<=right) then
                       begin
                         if f[j]<f[i]+b[j] then
                           begin
                             f[j]:=f[i]+b[j];
                             if f[j]>=k then
                               begin
                                 bo:=true;
                                 break;
                               end;
                           end;
                       end;
                   end;     }
                for j:=left2 to right2 do
                  begin
                    if f[j]<f[i]+b[j] then
                      begin
                        f[j]:=f[i]+b[j];
                        if f[j]>=k then
                          begin
                            bo:=true;
                            break;
                          end;
                      end;
                  end;
                if bo then
                  break;
              end;
            if bo then
              begin
                r:=mid-1;
                ans:=mid;
              end
            else
              begin
                l:=mid+1;
              end;
          end;
        writeln(ans);
        close(input);
        close(output);
end.
