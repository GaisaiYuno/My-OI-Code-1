#include<iostream>
#include<fstream>
using namespace std;
int n,d,k,ans,mind,bp=0;
int p[10001];
int j[10001];
int zs()//全走正数 
{
	int x=0;
	int y;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<=0)continue;
		for(y=i;y<=n;y++)if(p[y]>0)break;
		if(p[y]-p[y]>x)x=p[y]-p[y];
	}
	return x;
}
bool pd(int now)//判断 
{
	int zd;
	for(int xh=1;xh<=n;xh++)
	{
		if(j[xh]==now)break;	
		if(j[xh]>now)return false;
	}
	bp+=p[zd];
	if(bp>=k)return true;
	for(now=now-mind;now<=ans+d;now++)
	{
		if(pd(now))return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	int zd=0,now;
	for(int i=1;i<=n;i++)//输入 
	{
		int long_,point;
		cin>>long_>>point;
		p[i]=point;
		j[i]=long_;
	}
	for(int i=1;i<=500000;i++)
	{
		if(i>0)zd+=i;
	}
	if(zd>d)
	{
		for(ans=0;ans<=n-d;ans++)//判断 
		{
			bp=0;now=0;
			if(ans<d)mind=d-ans;
			else 
				mind=1;
			if(pd(0))
			{
				cout<<ans;
				return 0;
			}
		}	
		cout<<"-1";
	}
	if(zd==d)//刚好可以 
		cout<<zs();
	if(zd<d)//走不到 
		cout<<"-1";
	return 0;
}
