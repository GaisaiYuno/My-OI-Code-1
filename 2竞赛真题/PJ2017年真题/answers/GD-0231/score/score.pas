var a,b,c:real;
tot:real;
fin,fout:text;
begin
 assign(fin,'score.in');
 reset(fin);
 assign(fout,'score.out');
 rewrite(fout);
 read(fin,a);
 read(fin,b);
 read(fin,c);
 tot:=(a*2/10)+(b*3/10)+(c*5/10);
 write(fout,tot:0:0);
 close(fin);
 close(fout);
end.
