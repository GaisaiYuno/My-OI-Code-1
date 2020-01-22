const
 yd:array[1..8,1..2]of integer=((1,0),(0,1),(-1,0),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1));
var
 a,ans:array[1..1000,1..1000]of longint;
 f,xt:array[0..1001,0..1001]of boolean;
 dl:array[1..1000000]of record x,y:longint;end;
 m,n,i,j,x,y,c,head,tail:longint;
 begin
assign(input,'chess.in');reset(input);
assign(output,'chess.out');rewrite(output);
 readln(m,n);
 for i:=1 to n do
  begin
  readln(x,y,c);
  a[x,y]:=c+1;
  f[x,y]:=true;
  end;
 dl[1].x:=1;dl[1].y:=1;head:=0;tail:=1;f[1,1]:=false;
 fillchar(ans,sizeof(ans),0);
 ans[m,m]:=-1;
repeat
 inc(head);
 for i:=1 to 8 do
  if f[dl[head].x+yd[i,1],dl[head].y+yd[i,2]] then
   begin
    if i in [5..8] then
     if ((a[dl[head].x+yd[i,1],dl[head].y]=0)or(a[dl[head].x,dl[head].y+yd[i,2]]=0))and not(xt[dl[head].x+yd[i,1],dl[head].y+yd[i,2]]) then
      begin
       inc(tail);
       xt[dl[head].x,dl[head].y]:=true;
       dl[tail].x:=dl[head].x+yd[i,1];
       dl[tail].y:=dl[head].y+yd[i,2];
       ans[dl[tail].x,dl[tail].y]:=ans[dl[head].x,dl[head].y]+2;
       if a[dl[head].x,dl[head].y]<>a[dl[tail].x,dl[tail].y] then inc(ans[dl[tail].x,dl[tail].y]);
       if (dl[tail].x=m)and(dl[tail].y=m) then break;
       continue;
      end;
    inc(tail);
    f[dl[head].x+yd[i,1],dl[head].y+yd[i,2]]:=false;
    dl[tail].x:=dl[head].x+yd[i,1];
    dl[tail].y:=dl[head].y+yd[i,2];
    ans[dl[tail].x,dl[tail].y]:=ans[dl[head].x,dl[head].y];
    if a[dl[head].x,dl[head].y]<>a[dl[tail].x,dl[tail].y] then inc(ans[dl[tail].x,dl[tail].y]);
    if (dl[tail].x=m)and(dl[tail].y=m) then break;
   end;
  until ((dl[tail].x=m)and(dl[tail].y=m))or(head=tail);
write(ans[m,m]);
close(input);close(output);
end.
