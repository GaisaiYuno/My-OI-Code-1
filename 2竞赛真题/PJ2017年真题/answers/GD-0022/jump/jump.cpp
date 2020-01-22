#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int shu[500002],zou[500002],a=0,n,d,k,q,r;
bool fin(int b,int sco)
{
	if(b>=r&&sco>k)	return true;
	else
	{
		for(int i=0;i<a;i++)
		{
			if(shu[b+i]>=0)	fin(b+zou[i],sco+shu[b+i]);
		}
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(shu,0,sizeof(shu));
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&q);	scanf("%d",&shu[q]);	r=q;
	}
	for(int b=1;b<d;b++)
	{
		memset(zou,0,sizeof(zou));
		a=0;
		for(int i=max(1,d-b);i<=d+b;i++)
		{
			zou[a]=i; 
			a++;
		}
		if(fin(0,0))
		{
			printf("%d",b);
			return 0;
		}
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
