#include<cstdio>
#include<iostream>
using namespace std;
int n,p,a[1001],u,w,number,l;
bool flag;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=p;i++)
	{
		scanf("%d%d",&l,&number);
		u=10000001;
		for (int j=1;j<=n;j++)
		{
			flag=true;
			w=1;
			for (int k=1;k<=l;k++)
			{
				if (a[j]/w%10!=number/w%10){flag=false;break;}
				w*=10;
			}
			if (flag) u=min(a[j],u);
		}
		if (u==10000001) printf("-1\n");
		else printf("%d\n",u); 
	}
	return 0;
}
