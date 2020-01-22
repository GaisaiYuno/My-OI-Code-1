#include <stdio.h>

int main(){
	FILE *scorein, *scoreout;
	int a, b, c;
	int ares, bres, cres, all;
	scorein = fopen("score.in", "r");
	scoreout = fopen("score.out", "w");
	fscanf(scorein, "%d%d%d", &a, &b, &c);
	ares = a * 20 / 100;
	bres = b * 30 / 100;
	cres = c * 50 / 100;
	all = ares + bres + cres;
	fprintf(scoreout, "%d", all);
	fclose(scorein);
	fclose(scoreout);
	return 0;
}
