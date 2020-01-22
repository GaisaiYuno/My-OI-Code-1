#include<cstdio>
#include<queue>
using namespace std;
const int INF=500;
const int Move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct xy{
	int x,y,t,c;
	bool operator > (const xy &a) const { return t<a.t; }
	bool operator < (const xy &a) const { return t>a.t; }	
};
int c[102][102];
bool Visit[102][102],Check;
int n,m,i,j,x,y,t,clr;
priority_queue <xy> q;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&m,&n);
	for (i=1;i<=m;i++)
		for (j=1;j<=m;j++) { c[i][j]=0; Visit[i][j]=false;}
	for (i=0;i<m+2;i++)
		Visit[0][i]=Visit[i][0]=Visit[m+2][i]=Visit[i][m+2]=true;
	for (i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&clr);
		c[x][y]=clr+1;
	}
	q.push((xy){1,1,0,c[1][1]});
	while (1)
	{
		if (q.empty())
		{
			printf("-1");
			fclose(stdin); fclose(stdout);	
			return 0;
		}
		x=q.top().x;
		y=q.top().y;
		t=q.top().t;
		clr=q.top().c;		
		q.pop();
		if (x==m&&y==m)
		{
			printf("%d",t);
			fclose(stdin); fclose(stdout);	
			return 0;		
		}
		if (c[x][y]&&Visit[x][y]) continue;
		Visit[x][y]=true;
		for (i=0;i<4;i++)
		{
			if (Visit[x+Move[i][0]][y+Move[i][1]]) continue;
			if (c[x][y]==0)
			{
				if (c[x+Move[i][0]][y+Move[i][1]]==clr)
					q.push((xy){x+Move[i][0],y+Move[i][1],t,clr});
				else if (c[x+Move[i][0]][y+Move[i][1]]!=0)
					q.push((xy){x+Move[i][0],y+Move[i][1],t+1,c[x+Move[i][0]][y+Move[i][1]]});
			}
			else
			{
				if (c[x+Move[i][0]][y+Move[i][1]]==clr)
					q.push((xy){x+Move[i][0],y+Move[i][1],t,clr});
				else if (c[x+Move[i][0]][y+Move[i][1]]!=0)	
					q.push((xy){x+Move[i][0],y+Move[i][1],t+1,c[x+Move[i][0]][y+Move[i][1]]});
				else
				{
					q.push((xy){x+Move[i][0],y+Move[i][1],t+2,clr});
					q.push((xy){x+Move[i][0],y+Move[i][1],t+3,3-clr});	
				}
			}
		}
		
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
