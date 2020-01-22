#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,q;
int num[1010];
int p[10];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	int i,j;
	for (i=1;i<=n;++i)
		scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	int x,num_re,flag;
	p[0]=1;
	for (i=1;i<=10;++i) p[i]=p[i-1]*10;
	for (i=1;i<=q;++i)
	{
		scanf("%d%d",&x,&num_re);
		flag=0;
		for (j=1;j<=n;++j)
			if(num[j]%p[x]==num_re)
			{
				printf("%d\n",num[j]);
				++flag;
				break;
			}
		if(flag==0) printf("-1\n");	
	}
}

