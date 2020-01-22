#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using  namespace  std;
int  s[21000],x[21000],xs[21000],n=0,m=0;
int  xz(int  x,int  j)
{
	for(int  i=1;i<=n;i++)
	{
		if(x==s[i]%j)return  s[i];
	}
	return  -1;
}
int  main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(s,0,sizeof(s));
	memset(x,0,sizeof(x));
	memset(xs,0,sizeof(xs));
	scanf("%d%d",&n,&m);
	for(int  i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int  i=1;i<=m;i++){int  t=0;scanf("%d%d",&t,&x[i]);xs[i]=1;while(t--)xs[i]*=10;}
	sort(s+1,s+n+1);
	for(int  i=1;i<=m;i++)
	{
		printf("%d\n",xz(x[i],xs[i]));
	}
	return  0;
}
