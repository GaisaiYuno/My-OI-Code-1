#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int x,y,n,s,mm=-1,ma,g,p=-1,d,c,a[1000000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&c);
	if (d==1)
	{for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		a[x]=y;
		ma=max(ma,x);
	}
	int g=0;
	while(g<=ma)
	{
		s=0;
		for (int i=1;i<=x;i=i+d+g)
		  s+=a[i];
		if (s==c) 
		{
			if (mm=-1||s<mm) {mm=s;p=g;}
		}
		g++;
	}
	if (p==-1) cout<<-1;else cout<<p;
	return 0;
	}
    cout<<-1;
	return 0; 
}
