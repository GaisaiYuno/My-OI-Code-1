#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,d,k,x[500005],y[500005],s,p,yy,fw,j,z;
struct LU
{
	int tz;
};
LU fj;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		if(y[i]>0) fj.tz+=y[i];
	}
	if(fj.tz<k){cout<<-1;exit(0);}
	for(int i=0;i<=d;i++)
	{
		z++;
		yy=d+i;
		p=1;
		fw=0;j=0;
		fj.tz=0;
		while(p==1)
		{
			j++;
			if(yy+fw<x[j]+1)
			{
				if(yy+x[j-1]<x[j]+1)break;
				else {fj.tz+=y[j-1];fw=x[j-1];}
			}
			if(y[j]>=0) {fj.tz+=y[j];fw=x[j];}
		}
		if(fj.tz>=k) {cout<<i;exit(0);}
	}
	return 0;
}
