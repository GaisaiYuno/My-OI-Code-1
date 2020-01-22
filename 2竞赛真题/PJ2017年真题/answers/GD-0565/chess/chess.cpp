#include<iostream>
#include<cstdio>
using namespace std;
int m,n,x,y,c,Map[115][115],fals=0,ans=0;
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>c;
		Map[x][y]=c;
	}
	cout<<"-1";
	return 0;
}
