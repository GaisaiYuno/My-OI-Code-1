#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=500005,oo=100000000;
int n,d,k,masc,md,ans,midis,madis;
int dis,s;
struct aa
{
	int dis,s;
}a[maxn];

bool start(int num,int now,int x,int y,int nans)
{
	if(nans>=k)	return true;
	for(int i=num;i<=n;i++)
	{
		if(a[i].dis-now>=x&&a[i].dis-now<=y) 
		{
			if(start(num+1,a[i].dis,x,y,nans+a[i].s)==true) return true;
		}
	}
	return false;
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&dis,&s);
		a[i].dis=dis;
		a[i].s=s;
		md=max(md,dis);
		if(s>=0) masc+=s;
	}
	if(masc<k) cout<<-1<<endl;
	else
	{
		for(int i=1; ;i++)
		{
			if(i<d) midis=d-i;
			else midis=1;
			madis=d+i;
			if(start(1,0,midis,madis,0)==true) 
			{
				printf("%d",i);
				break;
			}	
		}
	}
	return 0;
}
