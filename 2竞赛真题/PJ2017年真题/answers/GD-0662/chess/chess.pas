const fx:array[1..4] of longint=(0,1,0,-1);
      fy:array[1..4] of longint=(1,0,-1,0);

type zqq=record
 x,y,data:longint;
 end;


var

n,m,i,j,k,t,p,ans,x,y,c:longint;

flag:boolean;
a,money:array[0..200,0..200] of longint;

b,bb:array[0..200,0..200] of boolean;

f:array[0..100000] of zqq;

function min(w,e:longint):longint;
  begin
    if w>e then exit(e) else exit(w);
  end;


function judge(w,e:longint):boolean;
 var i,j,k:longint;
  begin
        judge:=false;
        if (w>=1) and (w<=n) and (e>=1) and (e<=n) then
       //  if a[w,e]<>-1 then
          if b[w,e]=true then exit(true);
  end;

function de(w,e:longint):boolean;
 begin
        if a[w,e]=-1 then exit(false)
         else exit(true);
 end;


procedure bfs(t,p:longint);
  var head,tail,k:longint;
   begin
        head:=0;
        tail:=1;
        f[1].x:=t;
        f[1].y:=p;
        //f[1].data:=0;
      //  writeln(f[head].x);

      while head<tail do
         begin
               // if head=500 then begin writeln('Ahhhh'); halt; end;
                inc(head);
                b[f[head].x,f[head].y]:=false;

          for i:=1 to 4 do
           if (judge(f[head].x+fx[i],f[head].y+fy[i])=true)  then
            begin
                 if a[f[head].x+fx[i],f[head].y+fy[i]]=-1 then
                  begin
                   inc(tail);
                   f[tail].x:=f[head].x+fx[i];
                   f[tail].y:=f[head].y+fy[i];
                   if a[f[head].x,f[head].y]<>-1 then
                   begin
                       money[f[tail].x,f[tail].y]:=min(money[f[tail].x,f[tail].y],money[f[head].x,f[head].y]+2);
                       flag:=true;
                   end;
                  // bb[f[head].x+fx[i],f[head].y+fy[i]]:=false;

                  end

                 else

                 if ((a[f[head].x+fx[i],f[head].y+fy[i]]=a[f[head].x,f[head].y]) and (de(f[head].x,f[head].y)=true)) then
                  begin
                   flag:=false;
                   inc(tail);
                   f[tail].x:=f[head].x+fx[i];
                   f[tail].y:=f[head].y+fy[i];
                   if a[f[head].x,f[head].y]<>-1 then money[f[tail].x,f[tail].y]:=min(money[f[tail].x,f[tail].y],a[f[head].x,f[head].y]);
                  end

                 else


                 if (a[f[head].x+fx[i],f[head].y+fy[i]]<>a[f[head].x,f[head].y]) then
                  if (de(f[head].x,f[head].y)=true) or (de(f[head].x+fx[i],f[head].y+fy[i])=true) then
                  begin
                   flag:=false;
                   inc(tail);
                   f[tail].x:=f[head].x+fx[i];
                   f[tail].y:=f[head].y+fy[i];
                   money[f[tail].x,f[tail].y]:=min(money[f[tail].x,f[tail].y],money[f[head].x,f[head].y]+1);
                  // bb[f[head].x+fx[i],f[head].y+fy[i]]:=false;
                  end;

            end;
         end;

   end;

begin


assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);

  flag:=false;
  fillchar(money,sizeof(money),$7f div 3);
  for i:=1 to 100 do
    for j:=1 to 100 do a[i,j]:=-1;
  fillchar(b,sizeof(b),true);

  readln(m,n);
  for i:=1 to n do
   begin
        readln(x,y,c);
        a[x,y]:=c;
   end;
  money[1,1]:=0;

  bfs(1,1);
  if money[m,m]=707406378 then writeln(-1) else writeln(money[m,m]);


 { for i:=1 to m do
   begin
     for j:=1 to m do write(money[i,j],' ');
     readln;
   end; }

 close(input);
 close(output);
end.
