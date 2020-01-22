#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int x,y,c,m,n,qp[105][105],money[105][105],dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
bool visit[105][105];

void dp(int x,int y,bool pd,int c)
{
	if (x<1||x>m||y<1||y>m||visit[x][y]) return;
	visit[x][y]=true;
	for (int i=1;i<=4;++i)
	 {
	 	if (visit[x+dx[i]][y+dy[i]]) continue;
	 	if (c==qp[x+dx[i]][y+dy[i]])
		 {
		 	money[x+dx[i]][y+dy[i]]=min(money[x+dx[i]][y+dy[i]],money[x][y]);
		 	dp(x+dx[i],y+dy[i],true,qp[x+dx[i]][y+dy[i]]);
		 }
	 	 else
		  if (qp[x+dx[i]][y+dy[i]]==-1)
		   {
		   	if (pd)
		     {
		    	money[x+dx[i]][y+dy[i]]=min(money[x+dx[i]][y+dy[i]],money[x][y]+2);
		    	dp(x+dx[i],y+dy[i],false,qp[x][y]);
		     }
		     else continue;
		   }
		   else
		    {
		    	money[x+dx[i]][y+dy[i]]=min(money[x+dx[i]][y+dy[i]],money[x][y]+1);
		    	dp(x+dx[i],y+dy[i],true,qp[x+dx[i]][y+dy[i]]);
		    }
	 }
	visit[x][y]=false;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);

	cin>>m>>n;
	memset(qp,-1,sizeof(qp));
	memset(money,20000,sizeof(money));
	memset(visit,false,sizeof(visit));
	for (int i=1;i<=n;++i)
	 {
	 	cin>>x>>y>>c;
	 	qp[x][y]=c;
	 }
	money[1][1]=0;
	dp(1,1,true,qp[1][1]);
	if (money[m][m]<20000) cout<<money[m][m]<<endl;
	 else cout<<-1<<endl;
	return 0;
}
