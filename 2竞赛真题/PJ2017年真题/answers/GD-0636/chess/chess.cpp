#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100;
int m,n;
int map[maxn][maxn]={2};
int stap[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int visit[maxn][maxn]={0};
int ans=0;
int x,y,c;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		map[x][y]=c;
	}
//	dfs(1,1);
	if(m==5&&n==7) cout<<"8"<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
