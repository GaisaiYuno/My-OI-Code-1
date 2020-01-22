#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct data
{
	int x,y,t;
};
data op[10000+5];
int mi=1000000,s,m,n,a[1000+5][1000+5],x2,y2,c;
void se(int x,int y)
{
	int head=1,tail=1;
	op[1].x=x;op[1].y=y;op[1].t=1;
	while(head<=tail)
	{
		for(int i=0;i<3;i++)
		{
			int xx=op[head].x+dx[i],yy=op[head].y+dy[i],tt=op[head].t;
			if(xx<1||yy<1||xx>m||yy>m)return;
			if(a[x][y]==a[xx][yy]&&a[x][y]==2)return;
			if(a[x][y]!=a[xx][yy])tt++;
			if(a[xx][yy]==2)tt+=2;
			if(xx==m||yy==m)mi=min(mi,tt);
			tail++;
			op[tail].x=xx;
			op[tail].y=yy;
			op[tail].t=tt;
		}
		head++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=2;
	for(int i=1;i<=n;i++)
	{
		cin>>x2>>y2>>c;
		a[x2][y2]=c;
	}
	se(1,1);
	if(mi==1000000)cout<<-1;else cout<<mi;
	return 0;
}
