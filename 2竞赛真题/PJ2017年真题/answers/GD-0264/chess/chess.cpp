#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int oo=214748364;
int m,n,f[105][105],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool vi[105][105],af[1001005];
struct T3{int x,y,col,cost;bool pow;}q[1000000];
void BFS()
{
	int l=0,r=1,ans=oo;
	q[1].x=1;q[1].y=1;q[1].cost=0;q[1].col=f[1][1];q[1].pow=true;
	vi[1][1]=true;
	while (l<=r)
	{
		l++;
		if (q[l].x==m && q[l].y==m) ans=min(ans,q[l].cost);		
		if (q[l].pow)
		{
			for (int i=0;i<4;i++)
			{
				int nx=q[l].x+dx[i],ny=q[l].y+dy[i];
				if (nx>0 && nx<=m && ny>0 && ny<=m && !vi[nx][ny] && f[nx][ny]==-1)
				{
					vi[nx][ny]=true;
					r++;
					q[r].x=nx;q[r].y=ny;
					q[r].col=1;q[r].pow=false;
					q[r].cost=q[l].cost+2;
					if (q[l].col!=q[r].col) q[r].cost++;	
					r++;
					q[r].x=nx;q[r].y=ny;
					q[r].col=0;q[r].pow=false;
					q[r].cost=q[l].cost+2;
					if (q[l].col!=q[r].col) q[r].cost++;
				}
			}			
		}
		for (int i=0;i<4;i++)
		{
			int nx=q[l].x+dx[i],ny=q[l].y+dy[i];
			if (nx>0 && nx<=m && ny>0 && ny<=m && !vi[nx][ny] && f[nx][ny]!=-1)
			{
			    vi[nx][ny]=true;
				r++;
				q[r].x=nx;q[r].y=ny;
				q[r].col=f[nx][ny];
				q[r].pow=true;
				if (q[l].col!=f[nx][ny]) q[r].cost=q[l].cost+1;
				else q[r].cost=q[l].cost;
			}
		}
	}
	if (ans!=oo) cout<<ans;
	else cout<<-1;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	memset(f,-1,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		int xi,yi,colour;
		scanf("%d%d%d",&xi,&yi,&colour);
		f[xi][yi]=colour;
	}
	memset(vi,false,sizeof(vi));
	memset(af,false,sizeof(af));
	BFS();//BFS´ó·¨ºÃ 
	return 0;
}

