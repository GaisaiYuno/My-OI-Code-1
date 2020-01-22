#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[1001],Ans[1001];
int pow(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)
		ans*=a;
	return ans;
}
int main()
{
	int p,t,j;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&p,&t);
		for(j=1;j<=n;j++)
		{
			if(a[j]%pow(10,p)==t)
			{
				Ans[i]=a[j];
				break;
			}
		}
		if(j>n)
			Ans[i]=-1;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",Ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
