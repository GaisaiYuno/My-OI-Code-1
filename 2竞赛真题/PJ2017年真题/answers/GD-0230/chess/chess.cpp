#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,z[105][105],qw[5],a,b,c,k,ans;
bool x[105][105];
void work(int q,int w,bool ky,int k)
{
	if (q==n && w==n) 
	{
		ans=min(ans,k);
		return ;
    }else
    {
    	for (int i=1;i<=3;i++)
    	{
    		for (int j=1;j<=3;j++)
    		{
    			if (qw[i]==0 && qw[j]==1 || qw[i]==1 && qw[j]==0 || qw[i]==-1 && qw[j]==0 || qw[i]==0 && qw[j]==-1)
    			if (q+qw[i]>0 && w+qw[j]>0 && q+qw[i]<=n && w+qw[j]<=n)
    			if (x[q+qw[i]][w+qw[j]]!=true) 
    			{
    				if (z[q+qw[i]][w+qw[j]]==-1 && ky==true)
			    	{
					    x[q+qw[i]][w+qw[j]]=true;
                    	work(q+qw[i],w+qw[j],false,k+2);
					    x[q+qw[i]][w+qw[j]]=false;
			    	}else
			    	{
			    		if (z[q+qw[i]][w+qw[j]]!=-1)
						{
						    x[q+qw[i]][w+qw[j]]=true;
							if (z[q+qw[i]][w+qw[j]]!=z[q][w] && z[q][w]!=-1) work(q+qw[i],w+qw[j],true,k+1);else
							work(q+qw[i],w+qw[j],true,k);
			    	       //if (z[q+qw[i]][w+qw[j]]==-1 && ky==false) return ;
			    	        
			    	        //if (ky==false) 
						//else
				            //work(q+qw[i],w+qw[j],ky,k);
					        x[q+qw[i]][w+qw[j]]=false;
						}
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
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
	    z[i][j]=-1;
	qw[1]=0;qw[2]=1;qw[3]=-1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		z[a][b]=c;
	}
	k=0;
	x[1][1]=true;
	ans=100000000;
	work(1,1,true,0);
	if (ans!=100000000) printf("%d",ans);else
	 cout << -1;
	return 0;
}
