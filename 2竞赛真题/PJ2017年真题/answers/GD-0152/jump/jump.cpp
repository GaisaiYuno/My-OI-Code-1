#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,a[110000],b[2200],c[110000],e=0,g=0,q2=0,a3=0,a4=0;
int ss(int,int);
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]>a3)
		a3=a[i];
	}
	while(d+e<=a3)
	{
		int a1;
		if(d>e)
		a1=d-e;
		else
		a1=1;
		q2=0;
		g=0;
		if(ss(1,a1)==0)
		e++;
		else
		break;
	}
	if(a4==0)
	cout<<"-1";
	return 0;
}
int ss(int q,int a1)
{
	int j2=0;
	for(int i=a1;i<=d+e;i++)
	for(int j=1;j<=n;j++)
	if(q2+i==a[j])
	{
		q2+=i;
		g+=c[j];
		j2=c[j];
		if(g>=k)
		{	
			cout<<e;
			a4=1;
			return 1;
		}
		if(q2<a3) ss(q+1,a1);
		if(g>=k)
		return 1;
		if(g<k)
		{
			g-=j2;
			q2-=i;	
		} 
	}
	return 0;
}
