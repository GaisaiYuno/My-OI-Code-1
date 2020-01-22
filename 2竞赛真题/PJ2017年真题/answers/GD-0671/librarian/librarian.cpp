#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[10000010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(f,-1,sizeof(f));
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
	{
		int num=0,t_num=-1,p=-1,sum=1;
		scanf("%d",&num);
		p=num;
		t_num=num;
		while(num!=0)
		{
			sum*=10;
			num/=10;
		}
		
		while(sum)
		{
			if (f[p]!=-1)
				f[p]=min(f[p],t_num);
			else f[p]=t_num;
			p%=sum;
			sum/=10;
		}	
	}
	for (int i=0;i<q;i++)
	{
		int len=0,t_id=0;
		scanf("%d%d",&len,&t_id);
		if (f[t_id]!=-1)
			printf("%d\n",f[t_id]);
		else printf("%d\n",-1);
	}
	return 0;
}
