program chess;
var a,b,c:array[1..1000] of longint;
    m,n,k,j,i,o,p,q,r,s:longint; z:boolean;
begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input); rewrite(output);
  readln(n,m);
  for o:=1 to m do
      begin
      readln(p,q,r);
      a[o]:=p; b[o]:=q; c[o]:=r;
      end;
  s:=0; z:=true;
  for k:=1 to m-1 do
      for j:=k+1 to m do
       if (a[j]<a[k]) or ((a[k]=a[j]) and (b[j]<b[k]))
         then begin
              i:=a[k]; a[k]:=a[j]; a[j]:=i;
              i:=b[k]; b[k]:=b[j]; b[j]:=i;
              end;
  for o:=1 to m do
      begin
      if (a[o+1]-a[o]=0) or (b[o+1]-b[o]=0)
        then begin
            if c[o]<>c[o+1] then s:=s+1;
            if (a[o+1]-a[o]=2) and (b[o+1]-b[o]=0)
              then s:=s+2;
            if (a[o+1]-a[o]=0) and (b[o+1]-b[o]=2)
               then s:=s+2;
            if (a[o+1]-a[o]<3) and (b[o+1]-b[o]<3)
            then continue;
            end;
      if (a[o+1]-a[o]=1) and (b[o+1]-b[o]=1)
         then begin
            if c[o]<>c[o+1] then s:=s+3
               else s:=s+2;
            continue;
            end;
      if (a[o+1]-a[o]>1) or (b[o+1]-b[o]>1)
         then begin
              z:=false; break;
              end;
      end;
  if not(z) then write(-1)
     else if (a[m]<>n) or (b[m]<>n)
             then begin
                  if (n-a[m]>1) or (n-b[m]>1)
                    then write(-1)
                  else if (n-a[m]=1) and (n-b[m]=1)
                     then write(-1)
                      else write(s+2);
                  end
          else write(s);
  close(input); close(output);
end.
