#include<cstring>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1100
using namespace std;

int n,q,x,y,i,j,p[maxn],b[maxn];

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	p[0]=1; for (i=1; i<=7; i++) p[i]=p[i-1]*10;
	for (i=1; i<=n; i++) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for (i=1; i<=q; i++)
	{
		scanf("%d%d",&x,&y);
		int flag=0;
		for (j=1; j<=n; j++)
		{
			int k=b[j]-y;
			if (k==0 || k%p[x]==0)
			{
				printf("%d\n",b[j]);
				flag=1;
				break;
			}	
		}
		if (!flag) printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
