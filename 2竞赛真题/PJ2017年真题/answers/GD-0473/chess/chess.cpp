#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b,ans[105][105],che[105][105]/*棋盘颜色*/;
int x,y,cl;/*cl:1黄色0:红色2:无色*/
bool ic[105][105];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;++i)for(int j=1;j<=a;++j)
	{
		che[i][j]=2;ic[i][j]=true;ans[i][j]=0;
	}
	for(int i=1;i<=b;++i)
	{
		scanf("%d%d%d",&x,&y,&cl);
		che[x][y]=cl;
	}
	int t1,t2;
	for(int i=1;i<=a;++i)
	for(int j=1;j<=a;++j)
	{
		if(ans[i][j-1]==-1&&ans[i-1][j]==-1)
		{
			ans[i][j]==-1;continue;
		}
		if(che[i][j]==2)
		{
			if(ic[i][j-1]==false&&ic[i-1][j]==false)
		{
			ans[i][j]==-1;continue;
		}
			if(che[i][j-1]==2||j==1)
			{
				ans[i][j]=ans[i-1][j]+2;
				che[i][j]=che[i-1][j];
				ic[i][j]=false;
			}
			else
			if(che[i-1][j]==2||i==1)
			{
				ans[i][j]=ans[i][j-1]+2;
				che[i][j]=che[i][j-1];
				ic[i][j]=false;
			}
			else
			if(ans[i][j-1]<ans[i-1][j])
			{
				ans[i][j]=ans[i-1][j]+2;
				che[i][j]=che[i-1][j];
				ic[i][j]=false;
			}
			else
			{
				ans[i][j]=ans[i][j-1]+2;
				che[i][j]=che[i][j-1];
				ic[i][j]=false;
			}
			continue;
		}
		if(i==1&&j==1)ans[i][j]=0;
		else
		if(i==1)ans[i][j]=ans[i][j-1]+1;
		else 
		if(j==1)ans[i][j]=ans[i-1][j]+1;
		else
		if(ans[i-1][j]<ans[i][j-1])ans[i][j]=ans[i-1][j]+1;
		else ans[i][j]=ans[i][j-1]+1;
		//ans[i][j]=min(ans[i][j-1]+abs(che[i][j]-che[i][j-1]),
		//			  ans[i-1][j]+abs(che[i][j]-che[i-1][j]));
	}
	//for(int i=1;i<=a;++i)for(int j=1;j<=a;++j)cout<<ans[i][j]<<" ";
	cout<<ans[a][a];
	return 0;
}
