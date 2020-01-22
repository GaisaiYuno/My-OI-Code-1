#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
struct data
{
	int sz;
	int len;
};
data a[1000+50];
int n,m,x,y,xxx,yyy,o,mi,p,z;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
	  scanf("%d",&a[i].sz);
	  x=a[i].sz;
	  int j=0;
	  while(x!=0){x/=10;j++;}
	  a[i].len=j;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&o,&z);
		mi=2147483640;
		for(int j=1;j<=n;j++)
		{
			y=a[j].sz;
			x=z;
			p=0;
			for(int k=a[j].len;k>=a[j].len-o+1;k--)
			{
				xxx=x%10;
				x/=10;
				yyy=y%10;
				y/=10;
				if(xxx!=yyy){p=1;break;}
			}
			if(p==0)mi=min(mi,a[j].sz);
		}
		if(mi!=2147483640)printf("%d\n",mi);
		else printf("%d\n",-1);
	}
	return 0;
}
