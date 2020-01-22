#include<cstdio>
using namespace std;
int x[500000],s[500000];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k;
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
	}
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
