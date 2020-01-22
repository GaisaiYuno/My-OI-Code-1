#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const long long oo=100000000;
int n,d,k,sum,minb=oo,s1,s2,maxb;
int a[500000+10],b[500000+10];
int main()
{
	
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&s1,&s2);
		if(s2<=0){i--;n--;continue;}
		a[i]=s1;b[i]=s2;
		if(a[i]>0) sum+=b[i];
		minb=min(minb,(a[i]-a[i-1]));
		maxb=max(maxb,(a[i]-a[i-1]));
	}
	if(n==0||k==0){
		cout<<0<<endl;
		return 0;
	}
	if(k>sum)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(k<=sum)
	{
		int m1=abs(d-minb);
		cout<<m1<<endl;
		return 0;
	}
	return 0;
}
