#include<iostream>
#include<cstdio>
using namespace std;

const int maxm=105,oo=1000000000;

int m,n,xx,yy,c,ans=oo;
int x1[5]={0,1},y1[5]={1,0};
int a[maxm][maxm],f[maxm][maxm],la[maxm][maxm];//f表示走到格子i j时的最小值 

void init()
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j]=oo;
			a[i][j]=-1;
		}
	}
	f[1][1]=0;
}//初始化 

void dfs(int x,int y,int nans,int last)
{
	if(x==m&&y==m) 
	{
		ans=min(ans,nans);
		return;
	}
	
	for(int i=0;i<=1;i++)
	{
		int newx=x+x1[i],newy=y+y1[i];
		if(newx>m||newx<1||newy>m||newy<1) continue;//判断有没有越界
		
		if(a[newx][newy]==-1&&last==1) continue;//如果上一次已经用过2魔法了，那么这次不可以再用 
		if(a[newx][newy]==-1&&last==0)
		{
			a[newx][newy]=a[x][y];
			dfs(newx,newy,nans+2,1);//用魔法 
			a[newx][newy]=-1;
		}
		
		if(a[newx][newy]!=-1&&a[newx][newy]==a[x][y]) dfs(newx,newy,nans,0);//如果相同的话 
		
		if(a[newx][newy]!=-1&&a[newx][newy]!=a[x][y]) dfs(newx,newy,nans+1,0);//如果不相同 
		
	}
}

void method()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=m;j++)
		{
			if(i-1>=1)
			{
				if(la[i-1][j]==1&&a[i][j]==-1) f[i][j]=oo;
				if(a[i-1][j]==a[i][j]&&a[i][j]!=-1) f[i][j]=f[i-1][j];
				if(a[i-1][j]!=a[i][j]&&a[i][j]!=-1) f[i][j]=f[i-1][j]+1;
			}
			if(j-1>=1)
			{
				if(la[i][j-1]==1&&a[i][j]==-1) f[i][j]=min(f[i][j],oo);
				if(a[i][j-1]==a[i][j]&&a[i][j]!=-1) f[i][j]=min(f[i][j],f[i][j-1]);
				if(a[i][j-1]!=a[i][j]&&a[i][j]!=-1) f[i][j]=min(f[i][j],f[i][j-1]+1);	
			}
			int v=0;
			if(i-1>=1&&a[i-1][j]!=a[i][j]&&a[i][j]==-1) 
			{
				if(f[i][j]>f[i-1][j]+2&&la[i-1][j]!=1)
				{
					v=1;
					f[i][j]=f[i-1][j]+2;
				}
			}
			if(j-1>=1&&a[i][j-1]!=a[i][j]&&a[i][j]==-1) 
			{
				if(f[i][j]>f[i][j-1]+2&&la[i][j-1]!=1)
				{
					v=2;
					f[i][j]=f[i][j-1]+2;
				}
			}
			if(v==1) 
			{
				la[i][j]=1;
				a[i][j]=a[i-1][j];
			}
			if(v==2) 
			{
				la[i][j]=1;
				a[i][j]=a[i][j-1];			
			}	
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&xx,&yy,&c);
		a[xx][yy]=c;
	}
	
	if(m<=5) 
	{
		dfs(1,1,0,0);
		if(ans==oo) cout<<-1<<endl;
		else cout<<ans<<endl;
	}//从点1 1 开始，第三位为多少钱，最后一位记录上一次有没有用魔法。
	else
	{
		method();
		if(f[m][m]>=oo) cout<<-1<<endl;
		else cout<<f[m][m]<<endl;
	}
	return 0;
}
