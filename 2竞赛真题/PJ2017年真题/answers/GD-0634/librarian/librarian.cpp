#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int f[5600],len,x;
int d[10]={0,10,100,1000,10000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=q;i++)
	{
		bool bk=false;
		scanf("%d %d",&len,&x);
		for(int j=1;j<=n;j++)
		{
			if(f[j]%d[len]==x)
			{
				printf("%d\n",f[j]);
				bk=true;
				break;
			}
		}
		if(bk==false)printf("-1\n");
	}
	return 0;
}
