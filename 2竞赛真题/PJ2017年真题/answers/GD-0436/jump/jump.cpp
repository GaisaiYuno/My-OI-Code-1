#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int n,d,x[500001],s[500001],maxxx,minnn;
long long k,ans=0,ant;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	x[0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>s[i];
		if(s[i]>=0)
		{
			ans+=s[i];
		}
		maxxx=max(maxxx,x[i]-x[i-1]);
		minnn=min(minnn,x[i]-x[i-1]);
	}
	if(ans<k)
	{
		cout<<"-1"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else
	{
		int maxx=max(x[n]-k+1,k),minn=max(abs(k-maxxx),abs(k-minnn));
		while(maxx>minn)
		{
			int mid=maxx+minn;
			mid/=2;
			ant=0;
			bool ak=0;
			int ma=-100001,mi=0;;
			for(int i=1;i<=n;++i)
			{
				if(x[i]-x[ant]<d+mid&&max(1,d-mid)<x[i]-x[ant])
				{
					if(s[i]>=0)
					{
						ans+=s[i];
						ant=i;
					}
					else
					{
						if(x[ant]+mid+mid+d+d<x[i+1])
						{
							ma=-100001;
							mi=0;
							ans+=s[i];
						} 
						else
						{
							if(ma<=s[i])
							{
								ma=s[i];
								mi=x[i];
							}
						}
					}
				}
				if(ans>=k)
				{
					ak=1;
				}
			}
			if(ak=1)
			{
				maxx=mid-1;
			}
			else
			{
				minn=mid+1;
			}
		}
		cout<<abs(maxx-d)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
