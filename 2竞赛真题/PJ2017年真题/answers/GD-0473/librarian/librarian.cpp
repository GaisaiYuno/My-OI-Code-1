#include<iostream>
#include<cstdio>
using namespace std;
int pow10(int b)
{
	int a=1;
	for(int i=1;i<=b;++i)
	{
		a*=10;
	}
	return a;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int a,b,bk[1005],st[1005],ans[1005],t;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;++i)scanf("%d",&bk[i]);
	for(int j=1;j<=b;++j)
	{
		scanf("%d%d",&t,&st[j]);
		ans[j]=-1;
		for(int i=1;i<=a;++i)
		{
			if(bk[i]%pow10(t)==st[j])
			if(ans[j]==-1||ans[j]>bk[i])ans[j]=bk[i];
		}
	}
	for(int i=1;i<=a;++i)printf("%d\n",ans[i]);
	return 0;
}
