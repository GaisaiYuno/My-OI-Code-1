#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
int n,d,k,sum,ma,x,s,g,f1,a[1000005],b[1000005],f[1000005],max_,p,q,l;
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&s);
		a[x]=s;ma=x;f[x]=1;
		if(s>0){sum+=s;}
	}
	if(sum<k){printf("-1");return 0;}
    x=0;s=0;
	while(x<=ma)
	{
		x+=d;
		s+=a[x];
		if(s>=k){printf("0");return 0;}
	}
	while(1)
	{
		g++;x=0;p=0;s=0;
		if(g<d)
		{
			for(int i=d-g;i<=g+d;i++)
			{
				x++;
				b[x]=i;
			}
		}
		else
		{
			for(int i=1;i<=g+d;i++)
			{
				x++;
				b[x]=i;
			}
		}
		while(s<k)
		{
			f1=0;q=p;max_=-1000000;
			for(int i=1;i<=x;i++)
			{

				if(a[p+b[i]]>0){s+=a[p+b[i]];p+=b[i];f1=1;break;}
				if(f[p+b[i]]&&a[p+b[i]]>max_){max_=a[p+b[i]];l=p+b[i];}
			}
			if(f1==0){s+=max_;p=l;}
			if(q==p||p>=ma){break;}
			
		}
		if(s>=k){printf("%d",g);return 0;}
	}
    return 0;
}
