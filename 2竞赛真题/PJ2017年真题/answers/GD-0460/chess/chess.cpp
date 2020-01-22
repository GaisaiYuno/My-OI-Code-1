#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
struct data{
	int x,y,Time;
}q[1000001];
long long m,n,x1,y1,s,p[1001][1001],ans=10000001,S[1001][1001];
bool ff=false;
void BFS();
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
    {
    	scanf("%d%d%d",&x1,&y1,&s);
    	p[x1][y1]=s+1;
    }
    if (p[m][m-1]==0&&p[m][m-2]==0&&p[m-1][m]==0&&p[m-1][m-1]==0&&p[m-2]==0)
      printf("-1\n");
	  else 
	    {BFS();printf("%lld\n",ans);}
	return 0;
}
void BFS()
{
	int head=1,tail=1;
	q[head].x=1;q[head].y=1;
	q[head].Time=0;
	while (head<=tail)
	{
		data cur=q[head];
		for (int i=0;i<4;i++)
		{
			int X=cur.x+dx[i],Y=cur.y+dy[i];
			if (X<1 || Y<1 || X>m || Y>m || S[X][Y]==1) continue;
			S[X][Y]=1;
			if (p[X][Y]!=2&&p[X][Y]!=1)
			{
				if (p[cur.x][cur.y]==6) continue;
				int h=0;
				for (int j=0;j<4;j++)
				{
					int xl=X+dx[i],yl=Y+dy[i];
					if (p[xl][yl]==1 || p[xl][yl]==2) h=p[xl][yl];
				}
				if (p[cur.x][cur.y]!=6&&h==0) p[X][Y]=6;
				  else p[X][Y]=h;
				++tail;
				q[tail].Time+=2;
			}
			else 
			{
				++tail;
				if (p[X][Y]!=p[cur.x][cur.y]&&p[cur.x][cur.y]!=6) 
				{++q[tail].Time;p[cur.x][cur.y]=0;}
			}
			q[tail].Time+=cur.Time;
			q[tail].x=X;
			q[tail].y=Y;
			if (q[tail].x==m&&q[tail].y==m) 
			 if (q[tail].Time<ans) ans=q[tail].Time+1;
		}
		++head;
	}
}
