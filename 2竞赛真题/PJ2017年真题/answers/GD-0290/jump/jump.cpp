#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n,d,k,ma,maa,p,a[500009],b[500009];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) if(b[i]>0) ma+=b[i];
	if(ma>k) cout<<0;
	else if(ma<k) cout<<-1;
	else
	{
		p=1;int s=0;
		for(int i=1;i<=n;i++) if(b[i]>=0&&a[i]-p>maa) {maa=a[i]-p;p=a[i];}
		p=1;int mi=2147473647;
		for(int i=1;i<=n;i++) if(b[i]>=0&&a[i]-p<mi) {mi=a[i]-p;p=a[i];}
		if(maa==d&&mi==d) cout<<0;
		else if(maa<d&&mi<d) {s=mi-d;cout<<s;}
		else if(maa>d&&mi<d) {s=max(maa-d,mi-d);cout<<s;}
		else if(maa>d&&mi>d) {s=maa-d;cout<<s;}
	}
	return 0;
}

