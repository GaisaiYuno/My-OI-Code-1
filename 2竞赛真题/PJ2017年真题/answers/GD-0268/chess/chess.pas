program chess;
const
	g : array[1..4,1..2]of integer=((1,0),(-1,0),(0,1),(0,-1));
var
	m, n : longint;
	a : array[1..100, 1..100]of byte;
	f : array[1..100, 1..100]of longint;
	i, j, k, x, y, c : longint;

	procedure dfs(x, y, fx : longint; used : boolean);
	var
		i, j, k : longint;
	begin
		//writeln(x,' ',y, ' ',fx, ' ', used);
		if (x=m) and (y=m) then exit;
		if used=false then
		begin
			for i:=1 to 4 do
			begin
				//writeln(((f[x+g[i,1],y+g[i,2]])>(f[x,y]+2)),a[x+g[i,1],y+g[i,2]]);
				if i=fx then continue;
				if (x+g[i,1]<=0) or (y+g[i,2]<=0) or (y+g[i,2]>m) or (x+g[i,1]>m) then continue;
				if ((f[x+g[i,1],y+g[i,2]])>(f[x,y]+1)) and (a[x,y]<>a[x+g[i,1],y+g[i,2]]) and (a[x+g[i,1],y+g[i,2]]<>2) then begin
					f[x+g[i,1],y+g[i,2]]:=f[x,y]+1;
					//for j:=1 to m do begin for k:=1 to m do write(f[j,k]:10,' '); writeln; end;
					dfs(x+g[i,1],y+g[i,2],i,false);
				end;
				if ((f[x+g[i,1],y+g[i,2]])>(f[x,y])) and (a[x,y]=a[x+g[i,1],y+g[i,2]]) and (a[x+g[i,1],y+g[i,2]]<>2) then begin
					f[x+g[i,1],y+g[i,2]]:=f[x,y];
					//for j:=1 to m do begin for k:=1 to m do write(f[j,k]:10,' '); writeln; end;
					dfs(x+g[i,1],y+g[i,2],i,false);
				end;
				if ((f[x+g[i,1],y+g[i,2]])>(f[x,y]+2)) and (2=a[x+g[i,1],y+g[i,2]]) then begin
					f[x+g[i,1],y+g[i,2]]:=f[x,y]+2;
					a[x+g[i,1],y+g[i,2]]:=a[x,y];
					//for j:=1 to m do begin for k:=1 to m do write(f[j,k]:10,' '); writeln; end;
					dfs(x+g[i,1],y+g[i,2],i,true);
					a[x+g[i,1],y+g[i,2]]:=2;
				end;
			end;
		end
		else
		begin
			for i:=1 to 4 do
			begin
				if i=fx then continue;
				if ((f[x+g[i,1],y+g[i,2]])>(f[x,y])) and (a[x,y]=a[x+g[i,1],y+g[i,2]]) and (a[x+g[i,1],y+g[i,2]]<>2) then begin
					f[x+g[i,1],y+g[i,2]]:=f[x,y];
					//for j:=1 to m do begin for k:=1 to m do write(f[j,k]:10,' '); writeln; end;
					dfs(x+g[i,1],y+g[i,2],i,false);
				end;
				if ((f[x+g[i,1],y+g[i,2]])>(f[x,y]+1)) and (a[x,y]<>a[x+g[i,1],y+g[i,2]]) and (a[x+g[i,1],y+g[i,2]]<>2) then begin
					f[x+g[i,1],y+g[i,2]]:=f[x,y];
					//for j:=1 to m do begin for k:=1 to m do write(f[j,k]:10,' '); writeln; end;
					dfs(x+g[i,1],y+g[i,2],i,false);
				end;
			end;
		end;
	end;

begin
	read(m, n);
	fillchar(a, sizeof(a),2);
	for i:=1 to n do
	begin
		read(x, y, c);
		a[x, y]:=c;
	end;
	for i:=1 to m do
	begin
		for j:=1 to m do
		begin
			f[i,j]:=maxlongint;
			//write(a[i,j],' ');
		end;
		//writeln;
	end;
	f[1,1]:=0;
	dfs(1,1,0,false);
	if f[m,m]=maxlongint then write(-1) else write(f[m,m]);
end.
