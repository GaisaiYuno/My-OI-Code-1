#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int a[1009],c[10000000];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,a1,b1,t=1,b,s=0,j,k,cc=1,tem1,e;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	for(i=1;i<=q;i++)
	{
		cin>>a1>>b;
		b1=a1;
		for(j=1;j<=n;j++)
		{
			a1=b1;
			s=0;
			cc=1;
			t=1;
			tem1=a[j];
			for(e=1;e<=b1;e++)
			{
				c[e]=0;
			}
			while(a1>0)
			{
				c[t]=tem1%10;
				tem1=tem1/10;
				t++;
				a1--;
			}
			for(k=1;k<=b1;k++)
			{
				s=s+c[k]*cc;
				cc=cc*10;
			}	
			if(s==b)
			{
				cout<<a[j]<<endl;
				break;
			}
			if(s!=b&&j==n)
			{
				cout<<"-1"<<endl;
				break;
			}
		}
	}
	return 0;
}
