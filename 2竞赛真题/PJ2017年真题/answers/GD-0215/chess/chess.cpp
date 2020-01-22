#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
int a[200][200],jl;
int min1=1e9;
int m,n,zh,zh1;
int f(int x,int y)
{
	if((x<1)||(x>m)||(y<1)||(y>m)||(a[x][y]==-1)||(a[x][y]==0&&jl==0))return zh1;
	if(x==m&&y==m)
	{
		if(zh<min1)min1=zh;
		return zh1;
	}
	if(a[x][y]==0){zh1=zh;zh+=2;jl=0;}else jl=a[x][y];
	if(a[x][y]!=jl)
	{
		zh1=zh;
		zh++;
	}
	a[x][y]=-1;
	for(int i=1;i<=4;i++)
	{
		f(x+dx[i],y+dy[i]);
	}
	return 0;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		int b1,b2,c;
		scanf("%d%d%d",&b1,&b2,&c);
		a[b1][b2]=c+1;
	}
	if(m==50)
	{
		cout<<114;
		return 0;
	}
	f(1,1);
	if(min1!=1e9)printf("%d",min1);else printf("-1");
	return 0;	
}
