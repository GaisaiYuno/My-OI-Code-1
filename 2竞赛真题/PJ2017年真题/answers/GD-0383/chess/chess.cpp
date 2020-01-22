#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int m,n,a[105][105],f[105][105],min1=10005;
void work(int q,int w,int money,int magic)
{
	if(q==m && w==m)
	{
		min1=min(min1,money);
		f[q][w]=0;
	}
	else
	{
		int x1[4]={0,0,1,-1},y1[4]={1,-1,0,0};
		for(int i=0;i<4;i++)
		{
			int s=0,mf=0;
			if(f[q+x1[i]][w+y1[i]]==0 && q+x1[i]!=0 && w+y1[i]!=0 && q+x1[i]<=m && w+y1[i]<=m)
			{
			    if(a[q+x1[i]][w+y1[i]]!=0)
			    {
			    	if(a[q+x1[i]][w+y1[i]]!=a[q][w] && a[q][w]-2!=a[q+x1[i]][w+y1[i]])
			    	  s++;
			    	if(a[q][w]>3)
			    	  magic=0;
			    	f[q+x1[i]][w+y1[i]]=1;
				    work(q+x1[i],w+y1[i],money+s,magic+mf);
			    	f[q+x1[i]][w+y1[i]]=0;
			    }
			    else
			    {
			    	if(magic==0)
			    	{
			    		a[q+x1[i]][w+y1[i]]=a[q][w]+2;
			    		s+=2;
			    		mf=1;
			    		f[q+x1[i]][w+y1[i]]=1;
				        work(q+x1[i],w+y1[i],money+s,magic+mf);
			    	    f[q+x1[i]][w+y1[i]]=0;
						a[q+x1[i]][w+y1[i]]=0;
			    	}
			    }
			}
	    }
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
	f[1][1]=1;
	work(1,1,0,0);
	if(min1==10005)
	  cout<<-1;
	else
	  cout<<min1;
	return 0;
}
