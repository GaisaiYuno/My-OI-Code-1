#include<iostream>

#include<cstdio>

using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	int n,d,k;
	cin>>n>>d>>k;
	int a[10000],w[10000];
	int zs=0,lf=0,maxlf=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>a[i];
		if(a[i]>0)
		{
			zs+=a[i];
		}
		if(i==1)
		{
			if(a[i]<0)
			{
				lf++;
			}
		}
		else
		{
			if(w[i]-w[i-1]==1&&a[i]<0)
			{
				lf++;
			}
			else
			{
				if(lf>maxlf)
				{
					maxlf=lf;
				}
				lf=0;	
			}
		}	
	}
	if(zs<k)
	{
		cout<<"-1";
	}
	else
	{
		cout<<maxlf-1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
