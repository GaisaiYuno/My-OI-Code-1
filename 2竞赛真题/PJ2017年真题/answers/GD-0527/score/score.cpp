#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	float d=a*0.2+b*0.3+c*0.5;
	printf("%.0f",d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
