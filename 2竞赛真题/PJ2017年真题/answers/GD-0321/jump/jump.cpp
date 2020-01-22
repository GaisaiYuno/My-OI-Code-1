#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,k,a[500005],b[500005],z,s,e,g;
void jia(int x)
{
   int v=0;int lwj=0;
	while(z<=k&&x<=n)
	{
		bool f=true;int hg=-100005;
		int o=x;int po=0;
	    
		while(a[o]>=(lwj+s)&&a[o]<=(lwj+e))
		 {
		 	f=false;
		 	if(hg<=b[o])
		 	{ hg=b[o];v=a[o];po=o;}
         	o++;
		 }
		 cout<<z<<' '<<x<<' '<<hg<<' '<<po<<' '<<endl;
		 if(hg=-100005)break;
		 z+=hg;lwj=v;x=po;
		 x++;
	}
	return;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(b[i]>=0)z+=b[i];
	}
	if(z<k){cout<<"-1";return 0;}
	z=0;g=0;
	while(z<=k&&g<d)
	{
		g++;
	    e=d+g;
		if(g>=d) s=1;
		else s=d-g;
	   jia(1);
	   if(z>=k){break;}
	   z=0;
	}
	cout<<g;
	return 0;
}
