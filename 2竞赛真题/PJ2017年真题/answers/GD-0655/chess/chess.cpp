#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,x,y,v,a[105][105],yollow[105][105],red[105][105];
bool t[105][105];
int main()
{
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);	 
  cin>>m>>n;
  for (int i=1;i<=n;i++)
  {
  	cin>>x>>y>>v;
  	a[x][y]=v+1;
  }
  for (int i=0;i<=m+1;i++)
   for (int j=0;j<=m+1;j++){red[i][j]=yollow[i][j]=9999999;}
   red[1][0]=yollow[1][0]=0;
  for (int i=1;i<=m;i++)
   	for (int j=1;j<=m;j++)
   	{
   	   for (int k=0;k<4;k++)
	   {
	   	 if (a[i][j]==0&&!t[i+dx[k]][j+dy[k]]){t[i][j]=true;
		 red[i][j]=min(red[i][j],min(red[i+dx[k]][j+dy[k]],yollow[i+dx[k]][j+dy[k]]+1)+2);
	     yollow[i][j]=min(yollow[i][j],min(red[i+dx[k]][j+dy[k]]+1,yollow[i+dx[k]][j+dy[k]])+2);}
	   	 if (a[i][j]==1){
		 red[i][j]=min(red[i][j],min(red[i+dx[k]][j+dy[k]],yollow[i+dx[k]][j+dy[k]]+1));
	     }
	   	 if (a[i][j]==2){
		 yollow[i][j]=min(yollow[i][j],min(red[i+dx[k]][j+dy[k]]+1,yollow[i+dx[k]][j+dy[k]]));
		 }
       }
   	}
   if (yollow[m][m]==9999999&&red[m][m]==9999999)cout<<-1;
   else 
   cout<<min(yollow[m][m],red[m][m]);	
  return 0;	
}
