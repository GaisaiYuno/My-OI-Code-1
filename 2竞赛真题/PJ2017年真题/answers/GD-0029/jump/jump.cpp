#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,tail,sum,d,k,coins,ans=217483647,_min,_max,g;
int point[500005],len[500005];
int a[550][550];
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1; i<=n; i++) scanf("%d%d",&len[i],&point[i]);
	for (int i=1; i<=n; i++)
	{
		if (point[i]<=0) continue;
		if (point[i]>0)
		{
			sum+=point[i];
		}
	}
	if (sum<=k) 
	{
	   cout<<-1;
	   return 0;
    }
    for (int i=1; i<=n; i++)
     for (int j=i+1; j<=n; j++)
     {
     	a[i][j]=len[j]-len[i];
     }
     
	for (int i=1; i<=n; i++)
	 for (int j=1; j<=n; j++)
	   {
	   	 _min=min(_min,a[i][j]);
	   	 _max=max(_max,a[i][j]);
	   }
	if (_min>d&&_max>d) g=_max-d;
	if (_min<d&&_max>d) g=min(d-_min,_max-d);
	if (_min<d&&_max<d) g=_min-d;
	cout<<g;
	return 0;
}
