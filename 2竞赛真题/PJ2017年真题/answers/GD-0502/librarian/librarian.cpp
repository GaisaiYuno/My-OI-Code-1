#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

void readin()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
}

int a[1500],num[100];

int main()
{
	readin();
	num[0]=1;
	for(int i=1;i<=8;i++)
	{
		num[i]=num[i-1]*10;
	}
	int n,q,len,x;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		bool check=false;
		scanf("%d%d",&len,&x);
		for(int j=1;j<=n;j++)
		{
			int tmp=x-a[j];
			if(tmp%num[len]==0)
			{
				printf("%d\n",a[j]);
				check=true;
				break;
			}
		}
		if(!check)
			puts("-1");
	}
	return 0;
}

