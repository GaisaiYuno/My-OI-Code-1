const
  MAXN = 1000 + 100;
  MAXq = 1000 + 100;

var
  n,q:longint;
  i,j:longint;
  mark:boolean;
  book:array[-1..MAXN]of longint;
  peo,len_peo:array[-1..MAXq]of longint;

procedure qsort(s:longint;t:longint);
  var i,j,k,tem:longint;
  begin
    if s > t then exit;
    i := s;j := t;k := book[(i + j) div 2];
    repeat
      while (book[i] < k) do inc(i);
      while (book[j] > k) do dec(j);
      if i <= j then
       begin
         tem := book[i];
         book[i] := book[j];
         book[j] := tem;
         inc(i);dec(j);
       end;
    until i > j;
    qsort(i,t);
    qsort(s,j);
  end;

function check(x:longint;y:longint;num:longint):boolean;
  var p,an,c,e:longint;
  begin
    if x = y then
     begin
       exit(true);
     end
             else
     begin
       check := false;
       an := 1;
       e := 1;
       p := 0;
       for c := 1 to len_peo[num] - 1 do an := an * 10;
       while p < an do
        begin
          p := p + (y mod 10) * e;
          y := y div 10;
          e := e * 10;
        end;
       if p = x then exit(true)
                else exit(false);
     end;
  end;

begin
  assign(input,'librarian.in');
  assign(output,'librarian.out');
  reset(input);
  rewrite(output);
  readln(n,q);
  for i := 1 to n do
   begin
     readln(book[i]);
   end;
   qsort(1,n);
   for i := 1 to q do
    begin
      mark := false;
      readln(len_peo[i],peo[i]);
      for j := 1 to n do
       begin
         if (book[j] < peo[i]) then continue
                               else
         begin
           if check(peo[i],book[j],i) then
            begin
              writeln(book[j]);
              mark := true;
              break;
            end;
         end;
       end;
      if mark = false then writeln(-1);
    end;
  close(input);
  close(output);
end.
