#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
const int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,-1,1};
int a[105][105],ans,m,n,map[105][105];
void dfs(int x,int y,int k,int s,int c)
{
	if (x==m && y==m) 
	{
		ans=min(ans,s);
		return;
	}
	map[x][y]=1;
	for (int i=1;i<=4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i],kk=abs(k-1);
		if (xx>m ||yy>m||xx<1||yy<1|| map[xx][yy]==1) continue;
		if (a[xx][yy]==c) dfs(xx,yy,0,s,c);
		if (a[xx][yy]!=c && a[xx][yy]!=0 ) dfs(xx,yy,0,s+1,a[xx][yy]);
		if (a[xx][yy]!=c && a[xx][yy]==0 && k==0) dfs(xx,yy,1,s+2,c);
	}
	map[x][y]=0;
}
int main()
{
   freopen("chess.in","r",stdin); freopen("chess.out","w",stdout);
   cin>>m>>n;
   int p,q,x;
   for (int i=1;i<=n;i++)
   {
   	  cin>>p>>q>>x;
   	  x+=1;
   	  a[p][q]=x;
   }
   ans=9999999;
   dfs(1,1,0,0,a[1][1]);
   if (ans!=9999999) cout<<ans; else cout<<-1;
   return 0;
}
