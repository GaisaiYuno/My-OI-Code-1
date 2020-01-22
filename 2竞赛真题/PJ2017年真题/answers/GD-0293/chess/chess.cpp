#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int dx[]={1,0,0,-1};
const int dy[]={0,-1,1,0}; 
struct data
{
	int x;
	int y;
	int gold;
	int t;
};
data a[10010];
int m,n;
int stx,enx,sty,eny;
int k[105][105];
int vis[105][105];
int pd[10005];
int vis2[105][105];
int pd2=0;
bool comp(data u,data v)
{
	return u.gold<v.gold;
}
int bfs()
{
	a[1].x=1;
	a[1].y=1;
	memset(vis,0,sizeof(vis));
	vis[1][1]=1;
	int head=1,tail=1;
	while(head<=tail)
	{
		data cor=a[head++];
		if(cor.gold!=a[head-1].gold||cor.gold!=a[head-1].gold+1)
		{
			sort(a+1,a+tail+1,comp);
			cor=a[head-1];
		}
		if(vis2[cor.x][cor.y]) continue;
		int pd3=0;
		for(int i=0;i<4;i++)
		{
			int x1=cor.x+dx[i];
			int y1=cor.y+dy[i];
			int g1=cor.gold;
			if(x1<1||y1<1||x1>m||y1>m||vis[x1][y1]) 
				continue;
			++tail;
			vis[x1][y1]=1;
			if(k[x1][y1]==0)
			{
				if(pd[cor.t+1]==0)
				{
					a[tail].gold=g1+2;
					pd[cor.t+2]=1;
					pd2=k[cor.x][cor.y];
				}
				else
					continue;
			}
			else
			{
				if(k[x1][y1]!=k[cor.x][cor.y]&&pd2!=k[x1][y1])
				{
					a[tail].gold=g1+1;
					pd2=0;
				}	
				else
				{
					a[tail].gold=g1;
				}
			}
			a[tail].x=x1;
			a[tail].y=y1;
			a[tail].t=cor.t+1;
			if(x1==m&&y1==m)
			{
				pd3=1;
			}
			if(pd3==1)
			{
				sort(a+1,a+tail+1,comp);
				return a[tail].gold;
			}
		}
	}
	return -1;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	int o1,o2,o3;
	for(int i=1;i<=n;i++)
	{
		cin>>o1>>o2>>o3;
		k[o1][o2]=o3+1;
	}
	cout<<bfs()<<endl;
	return 0;
}
