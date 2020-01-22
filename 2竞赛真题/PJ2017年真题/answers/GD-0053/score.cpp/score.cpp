#include<cstdio>
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	float d=a*0.2+b*0.3+c*0.5;
	printf("%0.0f",d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
