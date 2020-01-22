type node=record
            x,m:longint;
          end;
     node1=record
             i,x,m,l:longint;
           end;
var i,j,k,n,e,d,h,t,x,l,r,mid,ma,mi:longint;
    a,b:array[-1..500000]of node;
    tm:array[-1..6000001]of node1;

    p:boolean;

function max(i,j:longint):longint;
begin
  if i>j then exit(i) else exit(j);
end;
function min(i,j:longint):longint;
begin
  if i<j then exit(i) else exit(j);
end;

begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(n,d,k);
  l:=0;r:=n-d-1;
  for i:=1 to n do readln(a[i].x,a[i].m);
  while l<r do
  begin
    mid:=(l+r+1)div 2;
    ma:=max(d+mid,n);
    mi:=min(1,d-mid);
    fillchar(tm,sizeof(tm),0);
    for i:=1 to n do begin
                      b[i].x:=-1;
                      b[i].m:=-maxlongint+1;
                     end;
    h:=0;t:=1;tm[1].x:=0;tm[1].m:=0;tm[1].i:=1;
    p:=false;
    repeat
      inc(h);
      if h=6000001 then h:=1;
      if tm[h].l=1 then continue;
      if tm[h].m>=k then begin
                           p:=true;
                           break;
                         end;
      x:=tm[h].x;
      for i:=tm[h].i+1 to n  do
      begin
        if (a[i].x-x)>ma then break;
        if (a[i].x-x)<mi  then continue;
        if tm[h].m+a[i].m>b[i].m then begin
                                        e:=b[i].x;
                                        tm[e].l:=1;
                                        inc(t);
                                        if t=6000001 then t:=1;
                                        tm[t].i:=i;
                                        tm[t].x:=a[i].x;
                                        tm[t].m:=tm[h].m+a[i].m;
                                        tm[t].l:=0;
                                        b[i].x:=t;
                                        b[i].m:=tm[t].m;
                                      end;
      end;
    until h=t;
    if p then r:=mid
    else l:=mid+1;
  end;
  if (p=false)and(r=n-d-1) then writeln(-1)
  else writeln(r);
  close(input);close(output);
end.
