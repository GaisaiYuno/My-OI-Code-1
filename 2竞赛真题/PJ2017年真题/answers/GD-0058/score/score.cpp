#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A,B,C,cj;
	scanf("%d%d%d",&A,&B,&C);
	cj=A*20/100+B*30/100+C*50/100;
	printf("%d",cj);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
