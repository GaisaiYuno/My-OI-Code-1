#include<iostream>
#include<cstdio>
using namespace std;
int m,n,a[105][105],x,y,c,b[105][105],pgk[105][105],de,we,jkl;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		a[x][y]=c+1;
	}
    for(int i=1;i<=m;i++)
    {
    	b[0][i]=-1;
    	b[i][0]=-1;
    }
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(i==1 && j==1)
    		  b[i][j]=0;
    		else
    		{
    			de=0;
    			we=0;
    			jkl=0;
    			if(b[i-1][j]==-1 && b[i][j-1]==-1)
    			    b[i][j]=-1;
    			if(b[i-1][j]!=-1)
    		  {
    		  	jkl++;
    		 	 if(a[i][j]==0)
    		 	 {
    		 	 	 if(pgk[i-1][j]==0)
					{
						pgk[i][j]++;
						b[i][j]=b[i-1][j]+2;
						a[i][j]=a[i-1][j];
					}
					else
					 b[i][j]=-1;
    		 	 }
    		 	 else
    		 	 {
    		 	 	if(a[i][j]!=a[i-1][j])
    		 	     b[i][j]=b[i-1][j]+1;
    		 	    if(a[i][j]==a[i-1][j])
    		 	     b[i][j]=b[i-1][j];
    		 	 }
    		  }
    		    if(b[i][j-1]!=-1)
    		  {
    		     if(a[i][j]==0)
    		     {
    		     	if(pgk[i][j-1]==0)
    		     	{
    		     		pgk[i][j]++;
    		     		de=b[i][j-1]+2;
    		     		we++;
    		     		a[i][j]=a[i][j-1];
    		     	}
    		     	else
    		     	{
    		     		de=-1;
    		     		we++;
    		     	}
    		     	  
    		     }
    		     else
    		     {
    		     	if(a[i][j]!=a[i][j-1])
    		     	{
    		     		de=b[i][j-1]+1;
    		     		we++;
    		     	}
    		     	if(a[i][j]==a[i][j-1])
    		     	{
    		     		de=b[i][j-1];
    		     		we++;
    		     	}
    		     }
    		     if(b[i][j]!=-1 && b[i][j]==0 && we!=0)
    		         b[i][j]=min(b[i][j],de);
    		     if(b[i][j]==-1 && de!=-1 && we!=0)
    		        b[i][j]=de;
    		     if(jkl==0)
    		        b[i][j]=de;
    		  }
    		}
       }
   }
//       for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=m;j++)
//		  cout<<b[i][j]<<' ';
//		cout<<endl;
//	}
    cout<<b[m][m];
    return 0;
}
