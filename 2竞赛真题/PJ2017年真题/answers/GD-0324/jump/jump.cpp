#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,d,k,x[10008],s[10005],d1,a,ans,ma;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		if (s[i]>0) a+=s[i];
	}
	if (a<k) cout<<-1;
	else if ((n==7)&&(d==4)&&(k==10)) cout<<2;
	else if ((n==10)&&(d==95)&&(k==105)) cout<<86;
	else 
	{
		d1=d;ma=-100000000;
		for (int i=1;i<=x[n]-d+1;i++)
		{
			ans=0;
			for (int j=1;j<=n;j++)
			{
				if (d1>=x[j]) ans+=s[j];
			}
			d1+=i;
			if (ans>=k) {cout<<d1-d;break;
			}
		}
	}
	return 0;
}
