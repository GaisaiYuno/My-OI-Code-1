#include<iostream>
#include<cstdio>
#include<cstring>
//#include<queue>
#define INF 1000000000000000007
using namespace std;
const int x1[4]={0,-1,0,1};
const int y1[4]={-1,0,1,0};
int n,m,got[105][105],mmap[105][105];//0 for none 1 for red 2 for yellow
long long ans[105][105];

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(mmap,0,sizeof(mmap));
	memset(got,0,sizeof(got));
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			ans[i][j]=-INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,col;
		scanf("%d%d%d",&x,&y,&col);
		col++;
		mmap[x][y]=col;
		ans[x][y]=INF;
		if(x-1>0)ans[x-1][y]=INF;
		if(x+1<=n)ans[x+1][y]=INF;
		if(y-1>0)ans[x][y-1]=INF;
		if(y+1<=n)ans[x][y+1]=INF;
	}
	ans[1][1]=0;
	
//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<mmap[i][j]<<' ';cout<<endl;}
//for(int i=0;i<=n+1;i++){for(int j=0;j<=n+1;j++)cout<<ans[i][j]<<' ';cout<<endl;}

	for(int f=1;f<=100;f++)
	{
		bool flag;
		flag=false;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(ans[i][j]!=-INF)
		{
			if(mmap[i][j]==0)
				for(int k=0;k<4;k++)
				{
					int lx,ly;
					lx=i+x1[k];
					ly=j+y1[k];
					if(lx<0||lx>n||ly<0||ly>n)continue;
					if(mmap[lx][ly]==0)continue;
					if(ans[lx][ly]==-INF)continue;
					if(ans[lx][ly]==INF)continue;
					if(ans[lx][ly]+2<ans[i][j])
					{
						flag=true;
						ans[i][j]=ans[lx][ly]+2;
						got[i][j]=mmap[lx][ly];
					}
					if(ans[lx][ly]+2==ans[i][j])
						if(got[i][j]!=3&&got[i][j]!=mmap[lx][ly])	got[i][j]+=mmap[lx][ly];
				}
			else
				for(int k=0;k<4;k++)
				{
					int lx,ly;
					lx=i+x1[k];
					ly=j+y1[k];
					if(lx<=0||lx>n||ly<=0||ly>n)continue;
					if(ans[lx][ly]==-INF)continue;
					if(ans[lx][ly]==INF)continue;
					if(mmap[lx][ly]==0)
					{
						if(got[lx][ly]==mmap[i][j]||got[lx][ly]==3)
						{
							if(ans[lx][ly]<ans[i][j])
							{
								ans[i][j]=ans[lx][ly];
								flag=true;
							}
						}
						else if(ans[lx][ly]+1<ans[i][j])
						{
							ans[i][j]=ans[lx][ly]+1;
							flag=true;
						}
					}
					else{
						if(mmap[lx][ly]==mmap[i][j])
						{
							if(ans[lx][ly]<ans[i][j])
							{
								ans[i][j]=ans[lx][ly];
								flag=true;
							}
						}
						else if(ans[lx][ly]+1<ans[i][j])
						{
							ans[i][j]=ans[lx][ly]+1;
							flag=true;
						}
					}
				}
		}
		if(!flag)	break;
	}
//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<ans[i][j]<<' ';cout<<endl;}
	
	if(ans[n][n]==INF||ans[n][n]==-INF)
	{
		printf("-1");
		return 0;
	}
	printf("%lld",ans[n][n]);
	return 0;
}
