#include<iostream>
#include<cstdio>
using namespace std;
long long n,d,k,q,a[500005],b[500005],s;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for (int i=1;i<=a[i];i++)
	{
        if (i>1000000) {cout<<"-1"<<endl;return 0;}
		if (i<d)
		{
            q=0;s=0;
			for (int j=1;j<=n;j++)
			{
				if (a[j]-q>=d-i&&a[j]-q<=d+i) {s+=b[j];q=a[j];}
				if (s>=k) {cout<<i<<endl;return 0;}
			}
		} 
		else 
		{
			q=0;s=0;
			for (int j=1;j<=n;j++)
			{
				if (a[j]-q<=d+i) {s+=b[j];q=a[j];}
				if (s>=k) {cout<<i<<endl;return 0;}
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
