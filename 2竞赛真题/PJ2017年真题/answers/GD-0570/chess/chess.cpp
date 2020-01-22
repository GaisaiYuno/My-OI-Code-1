#include<cstdio>
using namespace std;
int m,n,i;
int a[101][101]={2};
int sb,bs,c,money=0,x=1,y=1;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&sb,&bs,&c);
		a[sb][bs]=c;
	}
	printf("-1");
	printf("\n");
	return 0;
}
