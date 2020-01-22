#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(2*a+3*b+5*c)/10);
	fclose(stdin); fclose(stdout);
	return 0;
}
