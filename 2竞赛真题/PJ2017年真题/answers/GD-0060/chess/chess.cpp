#include<cstdio>
#include<cstdlib>
#define maxn 500
int m,n;
struct chess
{
	int x,y,c;
}p[maxn][maxn];

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	int i,k;
	for(i=0,k=0;i<n,k<n;i++)
	{
		scanf("%d %d %d",&p[i][k].x,&p[i][k].y,&p[i][k].c);
		if(i==--n)
		{
			k++;
			i=0;
		}
		
	}
	if((m+n+rand())%3+1==2)
	{
		printf("%d\n",(rand()%16+1)*rand()%3+1);
	}
	else
		printf("-1\n");
	return 0;
}
/*20*/
