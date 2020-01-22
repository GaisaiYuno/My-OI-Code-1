#include<iostream>
#include<cstdio>
#include<algorithm>
int n,q,b[10001],l[10001],x[10001];
using namespace std;
int sol(int xx,int yy)
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]%yy==xx) return b[i];
	}
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=q;i++) scanf("%d%d",&l[i],&x[i]);
	sort(b+1,b+n+1);
	for(int i=1;i<=q;i++)
	{
		int t=1;
		for(int j=1;j<=l[i];j++) t=t*10;
		int tt=sol(x[i],t);
		printf("%d\n",tt);	
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
