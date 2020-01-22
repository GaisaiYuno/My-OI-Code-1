#include<iostream>
#include<cstdio>
using namespace std;
int x,x1,s;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;cin>>n>>d>>k;
	int sum=0;
	cin>>x>>s;
	int xmax=x,xmin=x;x1=x;sum+=s;
	for(int i=1;i<n;i++)
	{
		cin>>x>>s;if(s>0)sum+=s;
		if(x-x1>xmax&&sum<=k&&s>0)xmax=x-x1;
		if(x-x1<xmin&&sum<=k&&s>0)xmin=x-x1;
		x1=x;
	}
//	cout<<xmax<<" "<<xmin<<" "<<sum<<endl;
	if(sum<k)
	{
		cout<<"-1";return 0;
	}
//	cout<<xmax-d<<" "<<d-xmin<<endl;
	cout<<max(xmax-d,-(xmin-d));
	
	return 0;
}
