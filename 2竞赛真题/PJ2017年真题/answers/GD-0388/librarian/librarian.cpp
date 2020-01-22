#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,q,a[1001],b[1001],s[1001];
bool cmop(const int &aa,const int &bb)
{
	return aa<bb;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int i,j,f;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%d%d",&n,&q);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=q;i++)
		scanf("%d%d",&s[i],&b[i]);
	sort(a+1,a+n+1,cmop);
	for (i=1;i<=q;i++)
	{
		f=0;
		int genn=int(pow(10,s[i])+0.5);
		for (j=1;j<=n;j++)
			if (a[j]%genn==b[i])
			{
				printf("%d\n",a[j]);
				f=1;
				break;
			}
		if (!f)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
