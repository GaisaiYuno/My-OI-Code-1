var
  n,m,t,i,j,e:longint;
  a:array [1..1010] of string;
  s,min,w:string;
begin
  assign(input,'librarian.in');
  reset(input);
  assign(output,'librarian.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    readln(a[i]);
  for i:=1 to m do
    begin
      read(t);
      readln(s);
      delete(s,1,1);
      min:='';
      for j:=1 to n do
        begin
          w:=copy(a[j],ord(a[j][0])-t+1,t);
          if s=w then
            begin
              if min='' then min:=a[j];
              if ord(a[j][0])<ord(min[0]) then
                min:=a[j]
              else
                if (ord(a[j][0])=ord(min[0])) and (a[j]<min) then
                  min:=a[j];
            end;
        end;
      if min='' then writeln('-1')
                else writeln(min);
    end;
  close(input);
  close(output);
end.
