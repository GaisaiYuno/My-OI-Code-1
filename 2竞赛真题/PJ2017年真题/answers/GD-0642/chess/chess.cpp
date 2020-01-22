#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int Map[105][105],xb[105][105],money[105][105];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
struct tnode{
	int x,y;
}qu[100010];
int m;
void moubri(int x1,int y1)
{
	int head=1,tail=1;
	qu[head].x=1;
	qu[head].y=1;
	xb[1][1]=1;
	money[1][1]=0;
	while(head<=tail)
	{
		for(int i=1;i<=4;i++)
		{
			int curx=dx[i]+qu[head].x;
			int cury=dy[i]+qu[head].y;
			xb[qu[head].x][qu[head].y]=1;
			if(xb[curx][cury]!=1&&curx<=m&&curx>0&&cury<=m&&cury>0&&Map[curx][cury]==Map[qu[head].x][qu[head].y]&&Map[curx][cury]!=3)
			{
				tail++;
				qu[tail].x=curx;
				qu[tail].y=cury;
				if(money[curx][cury]>0) money[curx][cury]=min(money[qu[head].x][qu[head].y],money[curx][cury]);
				else money[curx][cury]=money[qu[head].x][qu[head].y];
				continue;
			}
			if(xb[curx][cury]!=1&&curx<=m&&curx>0&&cury<=m&&cury>0&&Map[curx][cury]!=Map[qu[head].x][qu[head].y]&&Map[curx][cury]!=3&&Map[qu[head].x][qu[head].y]!=3)
			{
				tail++;
				qu[tail].x=curx;
				qu[tail].y=cury;
				if(money[curx][cury]>0) money[curx][cury]=min(money[qu[head].x][qu[head].y]+1,money[curx][cury]);
				else money[curx][cury]=money[qu[head].x][qu[head].y]+1;
				continue;
				
			}
			if(xb[curx][cury]!=1&&curx<=m&&curx>0&&cury<=m&&cury>0&&Map[curx][cury]!=Map[qu[head].x][qu[head].y]&&Map[curx][cury]==3)
			{
				tail++;
				qu[tail].x=curx;
				qu[tail].y=cury;
				if(money[curx][cury]>0) money[curx][cury]=min(money[qu[head].x][qu[head].y]+2,money[curx][cury]);
				else money[curx][cury]=money[qu[head].x][qu[head].y]+2;
				continue;
			}
			if(xb[curx][cury]!=1&&curx<=m&&curx>0&&cury<=m&&cury>0&&Map[curx][cury]==Map[qu[head].x][qu[head].y]&&Map[curx][cury]==3)
			{
				if(money[curx][cury]>0) continue;
				else money[curx][cury]=-1;
			
			}
		}
		head++;
	}
}
int main()
{
   	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++) Map[i][j]=3;
	for(int i=1;i<=n;i++)
	{
		int a,b,aa;
		cin>>a>>b>>aa;
		Map[a][b]=aa;
	}
	moubri(1,1);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<+m;j++)
		{
			cout<<money[i][j];
		}
		cout<<endl;
	}
	if(money[m][m]==0) cout<<-1<<endl;
	else cout<<money[m][m];
	return 0;
}
