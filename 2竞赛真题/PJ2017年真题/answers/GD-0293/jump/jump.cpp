#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct data
{
	int dis;
	int score;
};
data a[501000];
int f[101000]={0};
int sum[5000010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].dis>>a[i].score;
		sum[a[i].dis]=a[i].score;
	}
	for(int g=0;g<=a[n].dis;g++)
	{
		int maxs=0,sta=1,end=1;
		int maxx=-10000000;
		while(end<=n&&g!=0)
		{
			sta=maxs+max(1,d-g);
			end=maxs+min(a[n].dis,d+g);
			for(int j=sta;j<=end;j++)
			{
				if(sum[j])
				{
					if(maxx<sum[j])
					{
						maxx=sum[j];
						maxs=j;
					}
				}
			}
			if(maxx>=0)
				f[g]+=maxx;
		}
		if(f[g]>=k)
		{
			cout<<g<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
