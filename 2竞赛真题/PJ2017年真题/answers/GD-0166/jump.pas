var
   a:array [0..500001,1..2] of longint;
   rpd,p,q,rp,l,r,ans,mid,i,j,n,m,d:longint;
   rpr:boolean;

function max(aa,bb:longint):longint;
begin
   if aa>bb then exit(aa);
   exit(bb);
end;

begin
    assign(input,'jump.in'); reset(input);
    assign(output,'jump.out'); rewrite(output);
     readln(n,d,m);
     for i:=1 to n do
       readln(a[i,1],a[i,2]);

     l:=0; r:=max(1,a[n,1]-d);
     ans:=0;
     while l+1<r do
     begin
          mid:=(l+r) div 2;
          rp:=0;
          i:=0; j:=0;
          p:=1; q:=1;
          while (i<>n) do
          begin
              p:=0; q:=0;
              rpr:=false;
              rpd:=-maxlongint;
              for j:=i+1 to n do
              begin
                if (a[j,1]-a[i,1]>=max(1,d-mid)) and (a[j,1]-a[i,1]<=d+mid)
                   then begin
                             if a[j,2]>=0 then
                             begin
                                 if not(rpr) then
                                 begin
                                     rp:=rp+a[j,2];
                                     p:=j;
                                 end;
                                 rpr:=true;
                             end;
                             if a[j,2]>=rpd then
                             begin
                                 rpd:=a[j,2];
                                 q:=j;
                             end;
                        end;
                   if rpr then break;
              end;
              if rpr then i:=p
                 else if (rpd<>-maxlongint) then
                      begin
                           i:=q;
                           if (j<>n) then rp:=rp+a[q,2];
                      end
                 else i:=n;
          end;

          if rp>m then begin ans:=mid; r:=mid end
                  else if rp<m then l:=mid
                  else begin
                           writeln(mid);
                           close(input); close(output);
                           halt;
                       end;
     end;
     if ans=0 then writeln('-1')
              else writeln(ans);
     close(input); close(output);
end.
