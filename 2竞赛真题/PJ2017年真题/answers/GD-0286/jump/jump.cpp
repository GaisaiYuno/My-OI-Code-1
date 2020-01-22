#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
int n,d,k,sum,a[500001][2],x,xx,xn,cnt,ans=1000000001;
void dfs(int now,int h,int hh)
{
	int i;
	for(i=now+1;i<=n;i++)
	{
		xx=max(abs(a[i][0]-a[now][0]-d),h);
		if(hh+a[i][1]>=k)
		{ans=min(ans,xx);return;}
		else dfs(i,xx,hh+a[i][1]);
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(a[i][1]>0)
		sum+=a[i][1],cnt++;
	}
	if(sum<k) {printf("-1\n");exit(0);}
	for(i=1;i<=n-1;i++)
	for(j=1;j<=n-i;j++)
	if(a[j][0]>a[j+1][0])
	{
		a[j][0]^=a[j+1][0]^=a[j][0]^=a[j+1][0];
		x=a[j][0];a[j][0]=a[j][1];a[j][1]=x;
	}
	dfs(0,0,0);printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
