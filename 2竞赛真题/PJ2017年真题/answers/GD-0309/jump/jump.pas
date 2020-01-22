var a,s,d,x,y,q,f:longint;
    max,min:int64;
    g:array[1..1000000] of longint;
    p:boolean;
procedure ss(dep,w:longint);
var i,j:longint;
    e:boolean;
begin
  if w>=d then begin
    writeln(f);
    halt;
  end else if dep>q then exit
  else begin
    e:=false;
    for i:=dep+min to dep+max do if g[i]>0 then begin
      ss(i,w+g[i]);
      e:=true;
      break;
    end;
    if not e then begin
      for i:=dep+max downto dep+min do if g[i]=0 then break;
      if g[i]=0 then begin
        ss(i,w);
        for j:=dep+min to dep+max do if g[j]<>0 then ss(j,w+g[j]);
      end else for j:=dep+min to dep+max do ss(j,w+g[j]);
    end;
  end;
end;
begin
  assign(input,'jump.in');reset(input);
  assign(output,'jump.out');rewrite(output);
  readln(a,s,d);
  p:=false;
  for f:=1 to a do begin
    readln(x,y);
    g[x]:=y;
    if (y>0) and (not p) then max:=max+y;
    if max>=d then p:=true;
    if x>q then q:=x;
  end;
  if not p then begin
    writeln(-1);
    halt;
  end;
  f:=-1;
  repeat
    inc(f);
    if f>s then begin
      max:=f+s;
      min:=1;
      ss(0,0);
    end else begin
      max:=s+f;
      min:=s-f;
      ss(0,0);
    end;
  until f=q;
  close(input);
  close(output);
end.
