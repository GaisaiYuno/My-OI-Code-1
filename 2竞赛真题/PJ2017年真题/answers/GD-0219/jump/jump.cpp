#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d,k,x[500005],s[500005],u[500005],nx[11]={1,2,4,8,16,32,64,128,256,512,1024},a[15],minl=10000000;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
	}
	for(int i=1;i<nx[n];i++)
	{
		int sum=0,minl2=0;
		a[1]++;
		for(int j=1;j<=n;j++)
		if(a[j]>1)
		{
			a[j]=0;
			a[j+1]++;
		}
		for(int j=1;j<=n;j++)
		{
			sum+=s[j];
		}
		if(sum>=k)
		{
			for(int j=1;j<=n;j++)
			{
				minl2=max(minl2,abs(x[j]-x[j-1]-d));
			}
			minl=min(minl,minl2);
		}
	}
	if(minl==10000000)
	cout<<-1;
	else
	cout<<minl;
	return 0;
}
