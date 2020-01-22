#include<iostream>
#include<cstdio>
using namespace std;
int n,m,X,Y,C,a[101][101],ans;
int min(int x,int y)
{
	if(x<y&&x!=-1) return x;
	return y;
}
void Dfs(int x,int y,int Golds,bool pd,int last)
{
	if(pd&&!a[x][y]) return ;
	bool Check=0;
	if(!a[x][y])
	{
		Golds++;
		Check=1;
	} 
	if(a[x][y]!=last) Golds++;
	if(x==n&&y==n)
	{
		ans=min(ans,Golds);
		return ;
	}
	if(x<=0||y<=0||x>n||y>n||a[x][y]==-1) return ;
	if(!Check) last=a[x][y];
	int tmp=a[x][y];
	a[x][y]=-1;
	Dfs(x,y+1,Golds,Check,last);
	Dfs(x+1,y,Golds,Check,last);
	Dfs(x-1,y,Golds,Check,last);
	Dfs(x,y-1,Golds,Check,last);
	return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ans=-1;
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>X>>Y>>C;
		a[X][Y]=C+1;
	}
/*	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  {
	  	  cout<<a[i][j]<<" ";
	  	  if(j==n) cout<<endl;
	  }*/
	Dfs(1,1,0,0,a[1][1]);
	cout<<ans;
	return 0;
}
