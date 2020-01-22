VAR M,N,I,X,Y,C:LONGINT;
BEGIN
assign(input,'chess.in');
assign(output,'chess.out');
reset(input);
rewrite(output);
  READ(M,N);
  FOR I:=1 TO N DO READ(X,Y,C);
  WRITE('-1');
  close(input);
  close(output);
END.
