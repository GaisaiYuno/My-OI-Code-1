#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int x[500010],s[500010];
long long z[500010];
bool cc[500010];
int n,d,k,ans=0;
bool check(int t)
{
	for(int i=1;i<=n;i++)
	z[i]=s[i];
	memset(cc,false,sizeof(cc));
	int lf,rf=d+t-1;
	if(t>=d)
	lf=1;
	else
	lf=d-t;
	x[0]=0;
	z[0]=0;
	for(int i=0;i<n;i++)
	{
		if(x[i+1]-x[i]>rf)
		return false;
		for(int j=i+1;j<=n;j++)
		{ 		
			if(x[j]-x[i]>rf||x[i+1]-x[i]<lf)
			break;
			if(cc[j]==false)
			{
				z[j]=z[i]+s[j];
				cc[j]=true;
			}
			else
			z[j]=max(z[i]+s[j],z[j]);
			if(z[j]>k)
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);	
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		scanf("%d",&s[i]);
		if(s[i]>0)
		ans+=s[i];
	}
	if(ans<k)
	{
		cout<<-1<<endl;
		return 0;
	}
	long long le=0,ri=1000000001;
	while(le+1<ri)
	{
		long long mid=(le+ri)/2;
		if(check(mid))
		ri=mid;
		else
		le=mid;
	}
	cout<<le;
	return 0;	
}
