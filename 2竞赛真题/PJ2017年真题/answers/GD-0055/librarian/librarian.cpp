#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstring>
using namespace std;
struct f
{
	int line,num;
}b[1005];
int a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	long long ans;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	   scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	   scanf("%d%d",&b[i].line,&b[i].num);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		ans=pow(10,b[i].line);
		for(int j=1;j<=n;j++)
		{
			if(a[j]%ans==b[i].num)
			{
				printf("%d\n",a[j]);
				break;
			}
			if(j==n) printf("%d\n",-1);
		}
	}
	return 0;
}
