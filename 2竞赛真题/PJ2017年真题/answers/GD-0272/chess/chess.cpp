#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,m,x,y,c,i,j,f[101][101],r[101][101];
int dfs(int a,int b,bool y)
{
	
	int i,j,sum=0,ans=100000000;
	if(a==m && b==m) return 0;
	if(f[a+1][b]==f[a][b] && a<m && r[a+1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a+1,b,true);
    }
	ans=min(sum,ans);
	if(f[a-1][b]==f[a][b] && a>1 && r[a-1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a-1,b,true);
    }
	ans=min(sum,ans);
	if(f[a][b+1]==f[a][b] && b<m && r[a][b+1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b+1,true);
    }
	ans=min(sum,ans);
	if(f[a][b-1]==f[a][b] && b>1 && r[a][b-1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b-1,true);
    }
	ans=min(sum,ans);
    if(f[a+1][b]!=f[a][b] && f[a+1][b]<10 && f[a][b]<10 && a<m && r[a+1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a+1,b,true)+1;
    }
	ans=min(sum,ans);
	if(f[a-1][b]!=f[a][b] && f[a-1][b]<10 && f[a][b]<10 && a>1 && r[a-1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a-1,b,true)+1;
    }
	ans=min(sum,ans);
	if(f[a][b+1]!=f[a][b] && f[a][b+1]<10 && f[a][b]<10 && b<m && r[a][b+1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b+1,true)+1;
    }
	ans=min(sum,ans);
	if(f[a][b-1]!=f[a][b] && f[a][b-1]<10 && f[a][b]<10 && b>1 && r[a][b-1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b-1,true)+1;
    }
	ans=min(sum,ans);
	if(f[a+1][b]!=f[a][b] && f[a+1][b]<10 && f[a][b]<10 && y==true && a<m && r[a+1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a+1,b,false)+2;
    }
	ans=min(sum,ans);
	if(f[a-1][b]!=f[a][b] && f[a-1][b]<10 && f[a][b]<10 && y==true && a>1 && r[a-1][b]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a-1,b,false)+2;
    }
	ans=min(sum,ans);
	if(f[a][b+1]!=f[a][b] && f[a][b+1]<10 && f[a][b]<10 && y==true && b<m && r[a][b+1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b+1,false)+2;
    }
	ans=min(sum,ans);
	if(f[a][b-1]!=f[a][b] && f[a][b-1]<10 && f[a][b]<10 && y==true && b>1 && r[a][b-1]==0) 
	{
	r[a][b]=1;
	sum+=dfs(a,b-1,false)+2;
    }
	ans=min(sum,ans);
	return sum;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    cin>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	f[i][j]=3;
	for(int i=1;i<=m;i++)
	{
		f[0][i]=10;
		f[m+1][i]=10;
		f[i][0]=10;
		f[i][m+1]=10;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		f[x][y]=c;
	}
     cout<<"-1";
	return 0;
}
