//Æ­10~30·Ö 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int INF=2147483647;
int m,n,d[105][105],f[105][105],ans;

void input();
void dp();
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	input();
	dp();
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
void input()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			d[i][j]=-1;
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			f[i][j]=INF;
	for(int i=0;i<n;i++)
	{
		int x,y,cl;
		scanf("%d%d%d",&x,&y,&cl);
		d[x][y]=cl;
	}
	return;
}
void dp()
{
	ans=0;
	for(int i=1;i<=m;i++)
		f[i][0]=f[0][i]=0;
	d[0][1]=d[1][0]=d[1][1];
	f[1][1]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(d[i][j]!=-1)
			{
				int f1=INF,f2=INF;
				if(d[i][j]==d[i-1][j])
					f1=f[i-1][j];
				else if(f[i-1][j]!=INF) f1=f[i-1][j]+1;
				if(d[i][j]==d[i][j-1])
					f2=f[i][j-1];
				else if(f[i][j-1]!=INF) f2=f[i][j-1]+1;
				
				f[i][j]=min(f1,f2);
			}
		}
	}
	ans=f[m][m];
	return;
}
