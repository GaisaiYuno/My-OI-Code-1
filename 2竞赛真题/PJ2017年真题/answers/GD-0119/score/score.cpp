#include<cstdio>
#include<cstdlib>

float _hwk,_tst,_fin;
float A,B,C,D;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%f %f %f",&_hwk,&_tst,&_fin);
	A=_hwk*0.2;B=_tst*0.3;C=_fin*0.5;
	D=A+B+C;
	printf("%.0f\n",D);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
