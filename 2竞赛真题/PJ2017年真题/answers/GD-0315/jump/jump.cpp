#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int totge,orgdis,want;
int maxdis;

int score[1000001];
int vis[1000001];

bool check(int mid)
{
	vis[0]=0;
	int i,j;
	memset(vis,0,sizeof(vis));
	for(i=0;i<=maxdis;++i)
	{
		if(vis[i]!=0 or i==0)
			for(j=-mid;j<=mid;++j)
			{
				if(j+orgdis>=1) vis[i+j+orgdis]=max(vis[i+j+orgdis],vis[i]+score[i+j+orgdis]);
			}
	}
	if(vis[maxdis]>=want) return 1;
	return 0;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	int i,j;
	int x,y;
	
	scanf("%d%d%d",&totge,&orgdis,&want);
	for(i=1;i<=totge;++i)
	{
		scanf("%d%d",&x,&y);
		score[x]=y;
		if(i==totge) maxdis=x;
	}
	
	int l,r,mid,ans=INT_MAX;
	l=0;r=max(maxdis-orgdis,orgdis);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(ans!=INT_MAX) printf("%d\n",ans);
	else printf("-1\n");
	getchar();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
