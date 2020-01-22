#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

int n,m,inf=21474836,state[110][110],color[110][110],a,b,c;
int ans[110][110][3];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct arr
{
	int x,y;
}Q[400010];


void Set()
{
	for (int i=1; i<=m; i++) for (int j=1; j<=m; j++) state[i][j]=0;
	for (int i=1; i<=m; i++) for (int j=1; j<=m; j++) ans[i][j][0]=inf,ans[i][j][1]=inf;
	if (color[1][1]==0) ans[1][1][0]=0; else ans[1][1][1]=0;
}

void bfs(int a,int b)
{
	int head=1,tail=1;
	Q[head].x=a; Q[head].y=b;
    state[a][b]=1;
    
    while (head<=tail)
      {
      	int t1=Q[head].x;
      	int t2=Q[head].y;
      	int tr=ans[t1][t2][0],ty=ans[t1][t2][1];
      	for (int i=0; i<4; i++)
      	  {
      	  	int nx=t1+dx[i];
      	  	int ny=t2+dy[i];
      	  	if (color[t1][t2]==-1&&color[nx][ny]==-1) continue;
      	  	if (nx<=0||nx>m||ny<=0||ny>m) continue;
      	  	int tc=color[nx][ny];
			int temp=0;
			bool flag=false;
      	  	if (tc==1) 
			 {
			 	temp=min(tr+1,ty);
			 	if (temp<ans[nx][ny][1]) ans[nx][ny][1]=temp,flag=true;
			 }
      	  	if (tc==0) 
			 {
			 	temp=min(tr,ty+1);
				if (temp<ans[nx][ny][0]) ans[nx][ny][0]=temp,flag=true;
			 }
      	  	if (tc==-1) 
			 {
			    temp=min(tr+3,ty+2);
			 	if (temp<ans[nx][ny][1]) ans[nx][ny][1]=temp,flag=true;
				temp=min(tr+2,ty+3);
				if (temp<ans[nx][ny][0]) ans[nx][ny][0]=temp,flag=true;
			 }
      	  	if (state[nx][ny]==1||flag==false) continue;
      	  	state[nx][ny]=1;
      	  	tail++; Q[tail].x=nx; Q[tail].y=ny;      	  	
      	  }
      	state[t1][t2]=0;
      	head++;
      }
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	scanf("%d%d",&m,&n);
	
	for (int i=1; i<=m; i++) for (int j=1; j<=m; j++) color[i][j]=-1;
	
	for (int i=1; i<=n; i++)
	  {
	  	scanf("%d%d%d",&a,&b,&c);
	  	color[a][b]=c;
	  }
	
	Set();
	
	bfs(1,1);
	
	if (ans[m][m][0]>=inf&&ans[m][m][1]>=inf) {cout<<-1; return 0;	}
	cout<<min(ans[m][m][0],ans[m][m][1]);
	
	return 0;
}

