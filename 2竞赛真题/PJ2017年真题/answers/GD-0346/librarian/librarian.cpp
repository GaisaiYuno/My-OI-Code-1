#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
struct lpx
{
	int number;
	int ma;
	int count;
}b[3500];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,a[1200];
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		b[i].count=1;
	for(int i=0;i<q;i++)
		scanf("%d%d",&b[i].number,&b[i].ma);
	sort(a+0,a+n);
	for(int i=0;i<q;i++)
	{
		for(int k=10;k<=10000000;k=k*10)
		{
			for(int m=0;m<n;m++)
			{
				if(b[i].ma==a[m]%k)
				{
					printf("%d\n",a[m]);
					b[i].count=0;
					break;
				}
			}
			if(b[i].count==0)
				break;
		}
		if(b[i].count!=0)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
