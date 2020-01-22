#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int inf=2e9;
int n,q,a[maxn],l,x,minn;
bool judge(int a,int x,int l)
{
	while(l--)
	{
		if(a==0)return false;
		if(a%10!=x%10)return false;
		a/=10;x/=10;
	}
	return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	while(q--)
	{
		scanf("%d%d",&l,&x);
		minn=inf;
		for(int i=1;i<=n;i++)if(judge(a[i],x,l))minn=min(minn,a[i]);
		if(minn==inf)printf("-1\n");
		else printf("%d\n",minn);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
