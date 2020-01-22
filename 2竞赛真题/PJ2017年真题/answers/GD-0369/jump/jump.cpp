#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,d,mis,xi,si,maxx,sum=0,ans[1000000],sco[1000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>mis;
	for (int i=1;i<=n;i++) 
	{
		cin>>xi>>si;
		sco[xi]=si;
		if(i==n) maxx=xi;
		if (si>0) sum+=si;
	}
	if (sum<mis)
	{
		cout<<-1;
		return 0;
	}
	/*ans[0]=1;
	for (int j=2;j<=6;j++)
		{
		    if (j<1) continue; 
			for (int i=maxx;i>=0;i--)
	        {
	    	   if (ans[i]>0) ans[i+j]=max(ans[i+j],ans[i]+sco[i+j]);
	    	   if (ans[i+j]-1>=mis)
	    	    {
	    	    	cout<<2;
	    	    	return 0;
	    	    }
	        }  
	    }	    for (int i=1;i<=maxx;i++) cout<<i<<" "<<ans[i]-1<<endl;
	/*for (int k=2;k<=2;k++)
	{
		memset(ans,0,sizeof(0));
		ans[0]=1;
		if (k<d)
		{

	    	} 
		}

		} else
	   	  for (int j=1;j<=d+k;j++)
	   	    for (int i=maxx;i>=0;i--)
	    	    {
	    	    	if (ans[i]>0) ans[i+j]=max(ans[i+j],ans[i]+sco[i+j]);
	    	    	if (ans[i+j]-1>=mis)
	    	    	{
	    	    		cout<<k;
	    	    		return 0;
	    	    	}
	    	    } 	

	} */
	return 0;
}
