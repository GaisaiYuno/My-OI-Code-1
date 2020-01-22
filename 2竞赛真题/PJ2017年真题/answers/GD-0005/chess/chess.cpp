#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int m,n,sum=-1;
bool kk=1;
int a[105][105],b[105][105];int minl=20001;
bool check(int x1,int y1)
{
      if(a[x1][y1]==-1)
	  {
	  bool gg=0;
	  if(a[x1-1][y1]<8 && a[x1-1][y1]>0 )
		return 1;
	  if(a[x1+1][y1]<8 && a[x1+1][y1]>0 )
		return 1;
	  if(a[x1][y1-1]<8 && a[x1][y1-1]>0 )
		return 1;
	  if(a[x1][y1+1]<8 && a[x1][y1+1]>0 )
		return 1;
	  return 0;
	  }
	  return 1;
}
void dfs(int x,int y)
{
	if(x==m && y==m)
	{
		minl=min(minl,sum);
		return ;
	}
	else
	{
		if(a[x-1][y]!=0 && a[x-1][y]<8 && check(x-1,y))
		{
			  int kk=sum;bool tr=1;
			  if(a[x-1][y]==-1)
			  {
			    sum+=2;
				tr=0;
				a[x-1][y]=a[x][y]-10;
			  }
			  else
			    if(a[x-1][y]!=a[x][y])
			      sum++;
			  a[x-1][y]+=10;
			  dfs(x-1,y);
			  a[x-1][y]-=10;
			  if(!tr)
			    a[x-1][y]=-1;
			  sum=kk;
		}
		if(a[x+1][y]!=0 && a[x+1][y]<8)
		{
			
			if(check(x+1,y))
			{
			  int kk=sum;bool tr=1;
			  if(a[x+1][y]==-1)
			  {
			    sum+=2;
			    tr=0;
			    a[x+1][y]=a[x][y]-10;
			  }
			  else
			    if(a[x+1][y]!=a[x][y])
			      sum++;
			  a[x+1][y]+=10;
			  dfs(x+1,y);
			  a[x+1][y]-=10;
			  sum=kk;
			  if(!tr)
			    a[x+1][y]=-1;
			}
			
		}
		if(a[x][y-1]!=0 && a[x][y-1]<8)
		{
			
			if(check(x,y-1))
			{
			  int kk=sum;bool tr=1;
			  if(a[x][y-1]==-1)
			  {
			    sum+=2;
			    tr=0;
			    a[x][y-1]=a[x][y]-10;
			  }
			  else
			    if(a[x][y-1]!=a[x][y])
			      sum++;
			  a[x][y-1]+=10;
			  dfs(x,y-1);
			  a[x][y-1]-=10;
			  if(!tr)
			    a[x][y-1]=-1;
			  sum=kk;
			}
			
		}
		if(a[x][y+1]!=0 && a[x][y+1]<8)
		{
			
			if(check(x,y+1))
			{
			  int kk=sum;bool tr=1;
			  if(a[x][y+1]==-1)
			  {
			    sum+=2;
			    tr=0;
			    a[x][y+1]=a[x][y]-10;
			  }
			  else
			    if(a[x][y+1]!=a[x][y])
			      sum++;
			  a[x][y+1]+=10;
			  dfs(x,y+1);
			  a[x][y+1]-=10;
			  sum=kk;
			  if(!tr)
			    a[x][y+1]=-1;
			}
			
		}
	}
	/*for(int i=1;i<=m;i++)
	{
	  for(int j=1;j<=m;j++)
	    cout<<a[i][j]<<' ';cout<<endl;
	  
	}cout<<"____________________"<<endl;*/
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	    a[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		a[b][c]=d+1;
	}
	a[1][1]+=10;
	dfs(1,1);
	if(minl==20001)
	  cout<<-1;
	else
	  cout<<minl+1;
	return 0;
}
