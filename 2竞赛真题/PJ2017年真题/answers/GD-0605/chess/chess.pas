var
  i,j,k,n,m,x,y,z,ans1,ans2,asdf:longint;
  map:array[-1..101,-1..101]of longint;
  f:array[-1..101,-1..101,0..2]of longint;

function min(a,b:longint):longint;
begin
  if a<b
    then exit(a)
    else exit(b);
end;

begin
  assign(input,'chess.in'); reset(input);
  assign(output,'chess.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y,z);
      z:=z+1;
      map[x,y]:=z;
    end;
  if map[1,1]=0
    then f[1,1,1]:=2;
  for i:=1 to n do
  begin
  f[i,1,1]:=maxlongint;
  f[1,i,1]:=maxlongint;
  end;
  for i:=1 to n do
    for j:=1 to n do
      begin
        if (i<>1) and (j<>1)then
        if map[i,j]<>0 then
          begin
            ans1:=0;
            ans2:=0;
            if map[i-1,j]<>map[i,j] then ans1:=1;
            if map[i,j-1]<>map[i,j] then ans2:=1;
            f[i,j,1]:=min(f[i-1,j,1]+ans1,f[i,j-1,1]+ans2);
            f[i,j,2]:=0;

          end else
          begin
            if f[i,j,2]=0 then begin
            f[i,j,1]:=min(f[i-1,j,1],f[i,j-1,1])+2; f[i,j,2]:=1;end
            else
              begin
                f[n,n,1]:=-1;
                asdf:=-1;
                break;

              end;

          end;
      end;
  if asdf=-1 then writeln(asdf)
  else
  writeln(f[n,n,1]-1);

  close(input);
  close(output);
end.








