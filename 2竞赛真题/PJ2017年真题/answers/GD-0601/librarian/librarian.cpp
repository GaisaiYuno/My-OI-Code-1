#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int N,P,a[1005],k,q,s,l,f[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&N,&P);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		f[i]=1;
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=P;i++)
	{
		scanf("%d%d",&k,&q);
		s=1;l=1;
		for(int i=1;i<=k;i++)
		{
			s*=10;
		}
		for(int i=1;i<=N;i++)
		{
			if(a[i]%s==q&&f[i]){printf("%d\n",a[i]);f[i]=0;l=0;break;}
		}
		if(l){printf("-1\n");}
	}
    return 0;
}


