var	n,m,i,j,k,l,ki,ta,tb,tc:longint;
	a:array[0..1001,1..2]of longint;
	x,xy,w:array[0..101,0..101]of longint;
	y:array[1..10000,1..3]of longint;
begin
	assign(input,'chess.in');reset(input);
	assign(output,'chess.out');rewrite(output);
        read(n,m);
	a[1,1]:=1;	a[1,2]:=0;
	a[2,1]:=0;   	a[2,2]:=1;
	a[3,1]:=0;     	a[3,2]:=-1;
	a[4,1]:=-1;     	a[4,2]:=1;
        for i:=1 to m do
	begin
		read(ki,j,l);
		x[ki,j]:=l+1;
	end;
        for i:=0 to n+1 do
                for j:=0 to n+1 do
                xy[i,j]:=maxlongint;
	i:=0;
	j:=1;
	y[1,1]:=1;
	y[1,2]:=1;
	y[1,3]:=0;
	xy[1,1]:=0;
	w[1,1]:=1;
	while j>i do
	begin
		inc(i);
		for k:=1 to 4 do
		begin
                        inc(j);
			y[j,1]:=y[i,1];
			y[j,2]:=y[i,2];
			y[j,3]:=y[i,3];
			if (y[j,1]+a[k,1]>0)and(y[j,2]+a[k,2]>0)and(y[j,1]+a[k,1]<=n)and(y[j,1]+a[k,1]<=n) then
			begin
				y[j,1]:=y[j,1]+a[k,1];
				y[j,2]:=y[j,2]+a[k,2];

				if x[y[j,1],y[j,2]]=0 then y[j,3]:=y[i,3]+2
				else if x[y[i,1],y[i,2]]=0 then
                                begin
                                        y[j,3]:=y[i,3] ;
                                        break;
                                end else if x[y[i,1],y[i,2]]<>x[y[j,1],y[j,2]]    then y[j,3]:=y[i,3]+1;
			end;
			if w[y[j,1],y[j,2]]=1 then
			begin
				if xy[y[j,1],y[j,2]]>y[j,3] then
				begin
					xy[y[j,1],y[j,2]]:=y[j,3];
				end
				else
				dec(j);
			end
			else
			begin
                                if xy[y[j,1],y[j,2]]>y[j,3] then
                                begin
				xy[y[j,1],y[j,2]]:=y[j,3];
				w[y[j,1],y[j,2]]:=1;
                                for ki:=1 to 4 do
		                begin
                                        if x[y[j,1],y[j,2]]=0 then
                                        begin
                                        ta:=y[j,1]+a[ki,1];
                                        tb:=y[j,2]+a[ki,2];
                                        tc:=3;
                                        xy[ta,tb]:=y[j,tc];

                                        break;
                                        end;
                                        if x[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]=0 then if xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]>y[j,3]+2 then xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]:=y[j,3]+2
					else if x[y[j,1],y[j,2]]=0 then
                                        begin
                                        ta:=y[j,1]+a[ki,1];
                                        tb:=y[j,2]+a[ki,2];
                                        tc:=3;
                                        xy[ta,tb]:=y[j,tc];

                                        break;
                                        end else if x[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]<>x[y[j,1],y[j,2]] then if xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]>y[j,3]+1 then xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]:=y[j,3]+1
                                        else if x[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]=x[y[j,1],y[j,2]] then if xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]>y[j,3] then xy[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]:=y[j,3];
			              	//w[y[j,1]+a[ki,1],y[j,2]+a[ki,2]]:=1;

                                end;
                                end;
			end;
		end;

	end;
	write(xy[n,n]);
        close(input);close(output);
end.
