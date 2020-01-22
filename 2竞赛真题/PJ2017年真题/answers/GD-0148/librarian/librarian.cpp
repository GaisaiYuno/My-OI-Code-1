#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,j[1005],q1,q2;
long long ans;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&j[i]);
	sort(j+1,j+n+1);
	for(int w=1;w<=q;w++)
	{
		ans=1;
		scanf("%d%d",&q1,&q2);
		for(int i=1;i<=q1;i++)
			ans*=10;
		for(int i=1;i<=n;i++)
		{
			if(j[i]%ans==q2)
			{
				printf("%d\n",j[i]);
				break;
			}
			if(i==n)
			{
				printf("-1\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

