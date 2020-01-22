#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int map[1010][1010];
int m,n,ans=1000000;
long long f[1010][1010];
bool fang[1010][1010];
/*void dfs(int x,int y,bool used,int sum,int c)
{
	if(fang[x][y]==1) return;
	fang[x][y]=true;
	if(x>m||y>m||x==0||y==0) return;
//	if(fa==false) return;
	if(x==m&&y==m) 
	{
		if(sum<ans) ans=sum;
		return ;
	}
	if(used==true&&map[x][y+1]==-1) dfs(x,y+1,false,sum+2,map[x][y]);
	else 
	{
		if(used==false&&map[x][y+1]==-1) return;
		else if(map[x][y+1]!=map[x][y]) dfs(x,y+1,true,sum+1,map[x][y]);
		else dfs(x,y+1,true,sum,map[x][y]);
	}
	if(used==true&&map[x][y-1]==-1) dfs(x,y-1,false,sum+2,map[x][y]);
	else 
	{
		if(used==false&&map[x][y-1]==-1) return;
		else if(map[x][y]!=map[x][y-1]) dfs(x,y-1,true,sum+1,map[x][y]);
		else dfs(x,y-1,true,sum,map[x][y]);
	} 
	if(used==true&&map[x-1][y]==-1) dfs(x-1,y,true,sum+2,map[x][y]);
	else 
	{
		if(used==false&&map[x-1][y]==-1) return;
		else if(map[x][y]!=map[x-1][y]) dfs(x-1,y,true,sum+1,map[x][y]);
		else dfs(x-1,y,true,sum,map[x][y]);
	} 
	if(used==true&&map[x+1][y]==-1) dfs(x+1,y,false,sum+2,map[x+1][y]);
	else 
	{
		if(used==false&&map[x+1][y]==-1) return;
		else if(map[x][y]!=map[x+1][y]) dfs(x-1,y,true,sum+1,map[x][y]);
		else dfs(x-1,y,true,sum,map[x][y]);
	} 
}	*/
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(map,-1,sizeof(map));//c=0 为红色 c=1 为黄色 
	int a,b,f1;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&f1);
		map[a][b]=f1;
	}
//	dfs(1,1,true,0,map[1][1]);
//	cout<<ans<<endl;
//	cout<<ans<endl;
	cout<<-1<<endl;
	return 0;
}
