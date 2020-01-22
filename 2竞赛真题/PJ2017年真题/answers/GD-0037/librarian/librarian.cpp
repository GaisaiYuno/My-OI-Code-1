#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int c[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int num[10001],n,p;
void sort(int x,int y)
{
	int i=x,j=y,m=num[(x+y)/2];
	while (i<=j)
	{
		while (num[i]<m) i++;
		while (num[j]>m) j--;
		if (i<=j) swap(num[i++],num[j--]);
	}
	if (i<y) sort(i,y);
	if (x<j) sort(x,j);
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) scanf("%d",&num[i]);
	sort(1,n);
	for (int i=1;i<=p;i++)
	{
		int t,a,f=0,now=0;
		scanf("%d%d",&t,&a);
		for (int j=1;j<=n;j++)
			if (num[j]%c[t]==a)
			{
				f=1;
				now=j;
				break;
			}
		if (f) printf("%d\n",num[now]);
			else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
}
