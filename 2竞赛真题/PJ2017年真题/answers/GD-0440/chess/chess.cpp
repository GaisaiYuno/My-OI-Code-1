#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<math.h>
#include<cmath>
using namespace std;
    int m,n;
int a[105][105]={-1},maxn=1000000;
void find(int x,int y,int k,int s)
{
	
	if(s==1&&(a[x+1][y]==-1||x+1>m)&&(a[x-1][y]==-1||x-1<1)&&(a[x][y+1]==-1||y+1>m)&&(a[x][y-1]==-1||x-1<1)){return ;}
	if(x==m&&y==m){maxn=min(maxn,k);return ;}
	if(x+1<m||x+1==m)
	{
		if(a[x+1][y]==-1&&s==0)return find(x+1,y,k+2,1);
		else
	  if(a[x][y]!=a[x+1][y]&&a[x][y]!=-1&&a[x+1][y]!=-1)return find(x+1,y,k+1,0);
	  else
	   if(a[x][y]==a[x+1][y]||s==1) return find(x+1,y,k,0);	
	}else return ;
	if(x-1>1||x-1==1)
	{
		if(a[x-1][y]==-1&&s==0)return find(x-1,y,k+2,1);
		else
	  if(a[x][y]!=a[x-1][y]&&a[x][y]!=-1&&a[x-1][y]!=-1)return find(x-1,y,k-1,0);
	  else
	   if(a[x][y]==a[x-1][y]||s==1) return find(x-1,y,k,0);	
	}else return ;
	if(y+1<m||y+1==m)
	{
		if(a[x][y+1]==-1&&s==0)return find(x,y+1,k+2,1);
		else
	  if(a[x][y]!=a[x][y+1]&&a[x][y]!=-1&&a[x][y+1]!=-1)return find(x,y+1,k+1,0);
	  else
	   if(a[x][y]==a[x][y+1]||s==1) return find(x,y+1,k,0);	
	}else return;
	if(y-1>1||y-1==1)
	{
	if(a[x][y-1]==-1&&s==0)return find(x,y-1,k+2,1);
	else
	  if(a[x][y]!=a[x][y-1]&&a[x][y]!=-1&&a[x][y-1]!=-1)return find(x,y-1,k+1,0);
	  else
	   if(a[x][y]==a[x][y-1]||s==1) return find(x,y-1,k,0);		
	}else return ;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
     for(int j=1;j<=m;j++)
      a[i][j]=-1;
      int x,y,c;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d%d",&x,&y,&c);
    	a[x][y]=c;
    }
	find(1,1,0,0);
	if(maxn==1000000)maxn=-1;
	cout<<maxn;
	return 0;
}
