var a,b,c,d,e,a1,b1,c1,min:longint;
u,o:array[1..100,1..100]of longint;
s:array[1..4,1..2]of longint=((0,1),(0,-1),(1,0),(-1,0));

procedure tao(i,j,coin,zhen:longint);
var m,n,i1,j1,yuan:longint;
begin
  if (i=a)and(j=a) then begin
    if coin<min then min:=coin
  end;
  for m:=1 to 4 do begin
    i1:=i+s[m,1];
    j1:=j+s[m,2];
    if (i1<=a)and(i1>0)and(j1<=a)and(j1>0) then begin
      if o[i1,j1]<>1 then begin

        if u[i1,j1]=u[i,j] then begin
          o[i1,j1]:=1;
          tao(i1,j1,coin,0);
          o[i1,j1]:=0;
        end;

        if (u[i1,j1]<>u[i,j])and(u[i1,j1]<>-1) then begin
          o[i,j]:=1;
          tao(i1,j1,coin+1,0);
          o[i1,j1]:=0;
        end;

        if (u[i1,j1]=-1) and(zhen<>1) then begin
          o[i1,j1]:=1;
          u[i1,j1]:=0;

          tao(i1,j1,coin+2,1);
          o[i1,j1]:=1;
          u[i1,j1]:=1;

          tao(i1,j1,coin+2,1);
          u[i1,j1]:=-1;
          o[i1,j1]:=0;
        end;
      end;
    end;
  end;

end;

begin
  assign(input,'chess.in');
  assign(output,'chess.out');
  reset(input);rewrite(output);
  readln(a,b);
  min:=999999999;
  for c:=1 to a do
    for d:=1 to a do u[c,d]:=-1;

  for c:=1 to b do begin
    readln(a1,b1,c1);
    u[a1,b1]:=c1;
  end;

  tao(1,1,0,0);
  if min=999999999 then writeln('-1')
  else writeln(min+1);
  close(input);close(output);
end.
