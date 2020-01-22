const s:array[1..4,1..2] of integer=((0,1),(0,-1),(1,0),(-1,0));
var i,j,k,h,g,n,m,o,max:longint;
    p:boolean;
    a,c1:array[0..101,0..101] of longint;
    b:array[0..101,0..101] of boolean;
procedure ss(x,y,p:longint);
var z,c,v,r,r1:longint;
begin
  if(x=m)and(y=m)then begin
    if(c1[x,y]<max)then max:=c1[x,y];
  end else
  begin
    for z:=1 to 4 do begin
      c:=x+s[z,1];
      v:=y+s[z,2];
      if(c>0)and(c<=m)and(v>0)and(v<=m)then begin
        if(not b[c,v])then begin
          if(p=0)and(a[c,v]=-1)then  else begin
            b[c,v]:=true;
            r:=c1[c,v];
            c1[c,v]:=c1[x,y];
            r1:=a[c,v];
            if(a[c,v]<>-1)and(a[c,v]<>a[x,y])then inc(c1[c,v]);
            if(a[c,v]=-1)then begin
              c1[c,v]:=c1[c,v]+2;
              a[c,v]:=a[x,y];
              dec(p);
            end;
            ss(c,v,p);
            c1[c,v]:=r;
            b[c,v]:=false;
            a[c,v]:=r1;
          end;
        end;
      end;
    end;
  end;
end;
begin
  assign(input,'chess.in');reset(input);
  assign(output,'chess.out');rewrite(output);
  readln(m,n);
  for i:=0 to 101 do for j:=0 to 101 do begin a[i,j]:=-1;b[i,j]:=true;end;
  for i:=1 to n do begin
    readln(k,h,g);
    a[k,h]:=g;
  end;
  k:=0;
  h:=0;
  g:=0;
  for i:=1 to m do for j:=1 to m do b[i,j]:=false;
  for i:=1 to m do begin
    for j:=1 to m do begin
      o:=0;
      if(a[i,j]=-1)then begin
        for k:=1 to 4 do begin
          h:=i+s[k,1];
          g:=j+s[k,2];
          if(a[h,g]<>-1)then inc(o);
        end;
        if(o<2)then b[h,g]:=true;
      end;
    end;
  end;
  if(b[m-1,m])and(b[m,m-1])then begin
    writeln(-1);
    close(input);
    close(output);
  end;
  c1[1,1]:=0;
  b[1,1]:=true;
  max:=-1;
  ss(1,1,1);
  if(max<maxlongint)then writeln(max) else writeln(-1);
  close(input);
  close(output);
end.
