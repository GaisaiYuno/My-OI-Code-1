//Æ­10~30·Ö 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,dis,k,ans,maxn,sum,maxx,minx;

int absn(int a)
{
	return (a>0)?a:(-a);
}
void input();
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	input();
	if(sum<k) ans=-1;
	else
		ans=max(absn(maxx-dis),absn(dis-minx));
	cout<<ans<<endl;
	return 0;
}
void input()
{
	scanf("%d%d%d",&n,&dis,&k);
	maxn=-1,sum=0,maxx=-1,minx=5000005;
	int l=0;
	for(int i=0;i<n;i++)
	{
		int x,s;
		scanf("%d%d",&x,&s);
		
		if(x>maxn) maxn=x;
		if(s>0)
		{
			int dd=x-l;
			if(dd<minx)
				minx=dd;
			if(dd>maxx)
				maxx=dd;
			sum+=s;
			l=x;
		}
	}
	return;
}
