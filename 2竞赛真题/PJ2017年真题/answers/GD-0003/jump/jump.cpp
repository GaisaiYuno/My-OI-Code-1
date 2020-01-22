#include<cstdio>
#include<cstdlib>
using namespace std;
int n,d,k,x[500005],s[500005],all=0,map[502][502],sum[502],x;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&s[i]);
		sum[i]=s[i];
		if(s[i]>=0) all+=s[i];
	}
	if(all<k)
	{
		printf("-1");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
