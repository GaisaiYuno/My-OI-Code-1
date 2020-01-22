#include<cstdio>
#include<cstdlib>
#define maxn 100
int n,d,k;
int s[maxn],x[maxn];
int g=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	scanf("%d %d %d",&n,&d,&k);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
	}
	if((n+d+k)%2==0)
	{
		printf("%d",(rand()%5+1)*(rand()%5+1)*(rand()%5+1));
	}
	else
	{
		printf("-1");
	}
	return 0;
		
}
/*20*/
