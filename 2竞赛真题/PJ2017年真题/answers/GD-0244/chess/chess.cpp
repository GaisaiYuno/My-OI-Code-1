#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x,y,z,m,n,a[105][105],sum,fa=1,mind=999999999,g=1,j=1,chong=1;
bool b[105][105];
void work()
{
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	  for(int j=1;j<=m;j++)
	  {
	    a[i][j]=-1;
	    b[i][j]=false;
	  }
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z;
	}
}
bool dfs(int d,int f)
{
	if(d<=0 || f<=0)
	{
		chong++;
		  return false;
	}
	if(d>m || f>m)
	{
		chong++;
	  return false;
	} 
	if(a[d][f]==a[g][j])
	{
	  b[d][f]=true;
	  fa=1;
   }
	else
	  if(a[d][f]!=a[g][j] && a[g][j]!=-1)
	  {
	    sum++;
	    a[d][f]=true;
	    fa=1;
	  }	
	if(a[d][f]==-1 && fa==1)
	{
		a[d][f]=0;
		b[d][f]=true;
		fa--;
		sum+=2;
	}
	if(a[d][f]==-1 && fa==0)
	  return false;
	if(b[m][m]=true)
	  if(sum!=0)
	  return mind;
	for(int i=chong;i<=4;i++)
	{
		g=d;j=f;
	  if(i==1)
	  { 
	    chong=1;
	    dfs(d+1,f);	
	  }
	  if(i==2)
	    { 
		  chong=1;
	      dfs(d,f+1);
       }
	  if(i==3)
	  {
	    chong=1;
	   dfs(d-1,f);
     }
	   if(i==4)
	   {
	    chong=1;
	    dfs(d,f-1);  
	  }
	}
}
int main()
{
    work();
//    dfs(1,1);
    if(b[m][m]==false)
     cout<<-1;
    else
     cout<<sum;
	return 0;
}
