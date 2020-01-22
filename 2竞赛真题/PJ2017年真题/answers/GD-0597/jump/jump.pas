var a,b,c,d,e,o,max,min:longint;p:boolean;
u,u1:array[0..500000]of longint;

procedure tao(g,i:longint);
var m:longint;
begin
  if (i>=c) then begin
    p:=true;
    exit;
  end;
  if e<b then begin
    for m:=b-e to b+e do begin
    if g+m>max then break;
    if u1[g+m]=1 then tao(g+m,i+u[g+m]);
    end;
  end else begin
    if e>=b then for m:=1 to b+e do begin
      if g+m>max then break;
      if u1[g+m]=1 then tao(g+m,i+u[g+m]);
    end;
  end;
end;

begin
  assign(input,'jump.in');
  assign(output,'jump.out');
  reset(input);rewrite(output);
  readln(a,b,c);
  for d:=1 to a do begin
    readln(e,u[e]);
    u1[e]:=1;
    if d=1 then min:=e;
  end;
  if u[min]>=c then begin
    writeln('0');
    exit;
  end;
  p:=false;
  max:=e;
  e:=-1;
  if b<min then inc(e,min-b);
  dec(e);
  while p<>true do begin
    inc(e);
    if e>max-b then begin
      writeln('-1');
      exit;
    end;
    tao(0,u[0]);
  end;
  writeln(e);
  close(input);close(output);
end.
