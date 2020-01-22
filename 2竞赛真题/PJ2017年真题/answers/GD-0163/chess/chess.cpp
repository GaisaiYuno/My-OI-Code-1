#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
struct dat
{
	int x,y,co;
	bool p;
};
dat opens[100*100+10];
int m,n,x,y,c,a[105][105];
int f[105][105];
const int dx[5]={0,1,-1,0,0};
const int dy[5]={0,0,0,1,-1};
void bfs()
{
	int head=1,tail=1;
	f[1][1]=1;opens[1].x=1;opens[1].y=1;opens[1].co=0;opens[1].p=true;
	while (head<=tail)
	{
		for (int i=1;i<=4;i++)
		{
			int x=opens[head].x+dx[i],y=opens[head].y+dy[i],co=opens[head].co,p=opens[head].p;
			if (x<1||y<1||x>m||y>m||f[x][y]!=0) continue;
			if (a[x][y]==a[opens[head].x][opens[head].y]&&a[x][y]!=0)
			{
				if (f[opens[head].x][opens[head].y]==2) a[opens[head].x][opens[head].y]=0;
				int jl=0;
				for (int j=tail;j>=1;j--)
				  if (co>=opens[j].co) {jl=j;break;}
				tail++;
				for (int j=tail;j>=jl+2;j--)
				  opens[j]=opens[j-1];
				opens[jl+1].x=x;opens[jl+1].y=y;opens[jl+1].p=true;opens[jl+1].co=co;f[x][y]=1;
				if (x==m&&y==m) {cout<<co;exit(0);}
			}else if (a[x][y]!=a[opens[head].x][opens[head].y]&&a[x][y]!=0&&a[opens[head].x][opens[head].y]!=0)
			{
				co++;f[x][y]=1;
				if (x==m&&y==m) {cout<<co;exit(0);}
				int jl=0;
				for (int j=tail;j>=1;j--)
				  if (co>=opens[j].co) {jl=j;break;}
				tail++;
				for (int j=tail;j>=jl+2;j--)
				  opens[j]=opens[j-1];
				opens[jl+1].x=x;opens[jl+1].y=y;opens[jl+1].p=true;opens[jl+1].co=co;
			}else if (a[x][y]==0&&p==true)
			{
				p=false;co+=2;f[x][y]=2;a[x][y]=a[opens[head].x][opens[head].y];
				if (x==m&&y==m) {cout<<co;exit(0);}
				int jl=0;
				for (int j=tail;j>=1;j--)
				  if (co>=opens[j].co) {jl=j;break;}
				tail++;
				for (int j=tail;j>=jl+2;j--)
				  opens[j]=opens[j-1];
				opens[jl+1].x=x;opens[jl+1].y=y;opens[jl+1].p=false;opens[jl+1].co=co;				
			}else continue;
		}
		head++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		c++;
		a[x][y]=c;
	}
	bfs();
	cout<<-1;
	return 0;
}
