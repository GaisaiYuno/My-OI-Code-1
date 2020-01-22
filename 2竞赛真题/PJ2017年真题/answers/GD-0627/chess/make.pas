var
	n,m,i,j,x,y,c:longint;
        b:array[1..100,1..100] of boolean;
begin
	assign(output,'chess.in');rewrite(output);
    	randomize;
        n:=random(20)+1;
        m:=random(5)+1;
        writeln(m,' ',n);
        while n>0 do
        	for i:=1 to m do
        	begin
        		for j:=1 to m do
                	begin
                		if random(1)=1 then
                        	begin
                        		writeln(i,j,random(1));
                                        n:=n-1;
                                        if n=0 then
                                        	exit;
                        	end;
                	end;
        	end;  	
        close(input);close(output);
end.
