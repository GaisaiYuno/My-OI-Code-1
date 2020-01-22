#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int p(int z)
{
	if(z==0)return 1;
	else return 10*p(z-1);
}
int x[1010],b[1010],l[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,min;
	bool a=false;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for(int i=1;i<=q;i++)
	scanf("%d%d",&l[i],&x[i]);
	for(int i=1;i<=q;i++)
	{
		a=false;
		for(int j=1;j<=n;j++)
		{
			int t=p(l[i]);
			if(x[i]==b[j]%t)
			if(!a)
			{
				a=true;
				min=b[j];
			}
			else
			if(b[j]<min)min=b[j];
		}
		if(!a)printf("-1\n");
		else printf("%d\n",min);
	}
	return 0;
}
