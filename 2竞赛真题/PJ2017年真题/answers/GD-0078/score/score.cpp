#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","w",stdin);
	freopen("score.out","r",stdout);
	int A,B,C,sum=0;
	scanf("%d%d%d",&A,&B,&C);
	sum=A*20/100+B*30/100+C*50/100;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
