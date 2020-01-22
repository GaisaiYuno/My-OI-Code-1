#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int n,m,sum=0,ans=1000000000,col;
int a[110][110];
int f[110][110];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
void find1(int x,int y,int v,int num,int col,int sum)
{
	if(f[x][y]==-1) return ;
	if(num==1&&a[x][y]==0) sum=sum+2+v,num++;
	else if(num==2&&a[x][y]==0) return;
	else if(a[x][y]!=0) sum+=v;
	if(x==n&&y==n) {ans=min(ans,sum);return ;}
	f[x][y]=-1;
	for(int i=0;i<4;i++)
	{
		int nx=x+fx[i];
		int ny=y+fy[i];
		if(nx<1||nx>n||ny<1||ny>n) continue;
		if(a[nx][ny]==0) 
		{
		if(col==1) 
		{
		find1(nx,ny,0,num,col,sum);
		find1(nx,ny,1,num,col+1,sum);
		}
		else if(col==2) 
		{
		find1(nx,ny,0,num,col,sum);
	    find1(nx,ny,1,num,col-1,sum);
		}
		}
		if(a[nx][ny]!=0&&a[nx][ny]==col)find1(nx,ny,0,1,col,sum);
		else if(a[nx][ny]!=0&&a[nx][ny]!=col) find1(nx,ny,1,1,a[nx][ny],sum);
	}
}
int main()
{

	 freopen("chess.in","r",stdin);
	 freopen("chess.out","w",stdout);
	 scanf("%d %d",&n,&m);
	 for(int i=1;i<=m;i++)
	 {
	 	int x,y,z;
	 	scanf("%d %d %d",&x,&y,&z);
	 	if(z==0) a[x][y]=1;
	 	else if(z==1) a[x][y]=2;
	 }
	    col=a[1][1];
	 	find1(1,1,0,1,col,sum);

	 if(ans==1000000000) cout<<-1;
	 else cout<<ans;
	 return 0;
}

