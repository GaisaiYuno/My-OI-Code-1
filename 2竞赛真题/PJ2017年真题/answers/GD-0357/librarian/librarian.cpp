#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int corr[1003][1003],chucun,op,ts[1005][11];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,tushu[1005],peo[1005][11],xuqiu[1005];
	int h[1005],j,sol[1005],su,min=100000001,o,p;//sizeof tushu 
	bool tf[1005]={0};
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	    scanf("%d",&tushu[i]);
	for(int i=0;i<q;i++)
	    scanf("%d %d",&xuqiu[i],&h[i]);
	for(int i=0;i<n;i++)
	{
		su=tushu[i];
	    sol[i]=0;
	    while(su!=0)
	    {  
			sol[i]++;
	    	su/=10;
	    }
	    su=tushu[i];
	    o=0;
	    while(su!=0)
	    {
	    	ts[i][sol[i]-o-1]=su%10;
	    	o++;
	    	su/=10;
	    }
	}
	for(int i=0;i<q;i++)
	{
		p=0;
		while(h[i]!=0)
		{
			peo[i][xuqiu[i]-p-1]=h[i]%10;
			p++;
			h[i]/=10;
		}
	}
	for(int j=0;j<q;j++)
	    for(int i=0;i<n;i++)
	    {
	    	op=0;
	    	chucun=sol[i]-xuqiu[j];
	    	if(chucun>=0)
	    	{
	    		for(int k=0;k<xuqiu[j];k++)
				{
				    if(ts[i][chucun+k]==peo[j][k]) op++;
	    		} 
	    		
	            if(op==xuqiu[j]) 
			    {
				    corr[j][i]=tushu[i];
				    tf[j]=true;
			    }
	    	}
	        else continue;
	    }
	for(int j=0;j<q;j++)
	{
		min=100000001;
		if(tf[j]==1)
		{
	    	for(int i=0;i<n;i++)
	        {
	    	    if(corr[j][i]<min&&corr[j][i]!=0) 
					min=corr[j][i];
	        }
	        cout<<min<<endl;
	    }
	    else if(tf[j]==0)cout<<"-1"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
