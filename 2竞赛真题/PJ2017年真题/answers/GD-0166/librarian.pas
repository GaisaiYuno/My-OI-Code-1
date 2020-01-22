var
    a:array [0..1001] of longint;
    num:array [1..8] of longint;
    n,q:longint;

function min(aa,bb:longint):longint;
begin
    if aa<bb then exit(aa);
    exit(bb);
end;

procedure init;
var
    i:longint;
begin
    readln(n,q);
    for i:=1 to n do
      readln(a[i]);
    num[1]:=10;
    for i:=2 to 8 do
      num[i]:=num[i-1]*10;
end;

procedure main;
var
    cmin,i,j,x,y:longint;
begin
    for i:=1 to q do
      begin
          readln(x,y);
          cmin:=maxlongint;
          for j:=1 to n do
            if a[j] mod num[x]=y
               then cmin:=min(cmin,a[j]);
          if cmin=maxlongint
             then writeln('-1')
             else writeln(cmin);
      end;
end;

begin
     assign(input,'librarian.in'); reset(input);
     assign(output,'librarian.out'); rewrite(output);
      init;
      main;
     close(input);
     close(output);
end.