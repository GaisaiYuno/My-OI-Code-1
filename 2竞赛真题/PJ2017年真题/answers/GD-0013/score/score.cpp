#include<cstdio>
using namespace std;
int a,b,c,t;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	t=a/5+b*3/10+c/2;
	printf("%d",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
