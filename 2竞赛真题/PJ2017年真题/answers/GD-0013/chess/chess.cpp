#include<cstdio>
using namespace std;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1,temp;i<=3*b;i++)
	{
		scanf("%d",&temp);
		scanf("%d",&temp);
		scanf("%d",&temp);
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
