#include<bits/stdc++.h>
using namespace std;
int n,d,k,a[500010],b[500010],l,r,mid,ready=1,maxsum=0,dp[500010];

int check(int num)
{
	int i=1,get=0,limmin,limmax,locate=0;
	if (num<d) 
	{
		limmin=d-num;
		limmax=d+num;
	}
	if (num>=d)
	{
		limmin=1;
		limmax=d+num;
	}
	while (i<=n)
	{
		if (locate+limmax<a[i]||a[i]<locate+limmin) i++;
		else 
	    {
	    	if (b[i]>=0)
	    	{
	    		get+=b[i];
	    		if (get>=k) return 1;
	    		locate=a[i];
	    		i++;
	    	}
	    	else if (b[i]<0)
	    	{
	    		int j=i,bestget=b[i],bestloca=a[i];
	    		while (a[j]<=locate+limmax&&a[j]>=locate+limmin)
	    		{
	    			if (b[j]>=0)
	            	{
	    	        	bestget=b[j];
	    	        	bestloca=a[j];
	    	        	i=j;
	    	        	break;
	            	}
	            	if (b[j]<0)
	            	{
	            		if (b[j]>bestget)
	            		{
	            			bestget=b[j];
	    	            	bestloca=a[j];
	    	            	i=j;
	            		}
	            	}
	            	j++;
	    		}
	    		i++;
	    		get+=bestget;
	    		if (get>=k) return 1;
	    		locate=bestloca;
	    	}
	    }
	}
	return 0;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=n;i++) if (b[i]>0) maxsum+=b[i];
	if (maxsum<k) ready=0;
	if (ready==1)
	{
		l=1;
		r=500010;
		while (l<r)
		{
			mid=(l+r)/2;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
	}
	if (ready==0) printf("-1");
	else printf("%d",l);
	return 0;
}
