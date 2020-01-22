#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d,k,s[500001],x[500001],ans,f[500001],tot,g;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int i,j;
	memset(s,0,sizeof(s));
	memset(x,0,sizeof(x));
	memset(f,0,sizeof(f));
	scanf("%d%d%d",&n,&d,&k);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x[i],&s[i]);
	if (d==1)
	{
		tot=ans=g=0;
		while (tot<k)
		{
			int now=0,maxn=0;
			for (i=1;i<=n;i++)
				if (now+g+d<x[i])
					break;
				else
				{
					now=x[i];
					maxn+=s[i];
				}
			tot=max(tot,maxn);
			g++;
		}
		printf("%d",g-1);
		return 0;
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
