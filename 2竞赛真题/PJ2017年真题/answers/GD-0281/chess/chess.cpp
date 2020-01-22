#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
struct data
{
	long long x,y,t,colour;
};
data q[10005];
bool vis[105][105];
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
int a[105][105] ,b[105][105];
int n,m,x,y,c,s;
bool f=true;
/*int dfs(int xx,int yy)
{
	for(int i=0;i<4;)
	{
		int x1=xx+dx[i];
		int y1=yy+dy[i];
		if(x1<1||y1<1||x1>n||y1>n)i++;
		if(a[x1][y1]==-1&&a[xx][yy]==-1)return -1;
		else if(a[x1][y1]==-1&&a[xx][yy]!=-1)s+=2;	
		else if(a[x1][y1]!=a[xx][yy]&&a[x1][y1]!=-1&&a[xx][yy]!=-1)s++;  
		if(x1==n&&y1==n)return s;
		dfs(x1,y1);
		i++;
	}	
}*/
int bfs(int xx,int yy)
{
	q[1].x=xx;
	q[1].y=yy;
	q[1].t=0;
	memset(vis,false,sizeof(vis));
	long long head=0;
	long long tail=1;
	while(head<tail)
	{
		int s=0;
		head++;
		for(int i=0;i<4;)
		{
			data cur=q[head];
			int x1=cur.x+dx[i];
			int y1=cur.y+dy[i];
			if(x1<1||y1<1||x1>n||y1>n||vis[x1][y1])i++;
			else 
			{
				vis[x1][y1]=true;
				tail++;
				q[tail].x=x1;
				q[tail].y=y1;
				if(a[x1][y1]==-1&&q[head].colour==1)return -1; 			
				if(a[x1][y1]==-1&&q[head].colour==0)
				{
					q[tail].t=cur.t+2;
					q[tail].colour=1;
				}
				else if(a[cur.x][cur.y]!=a[x1][y1])q[tail].t=cur.t+1;
				else q[tail].t=cur.t;
				if(x1==n&&y1==n)return q[tail].t;
				i++;
			}
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	cout<<bfs(1,1);
	return 0;
}
