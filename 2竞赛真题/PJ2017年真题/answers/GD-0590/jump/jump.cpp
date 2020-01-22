#include<cstdio>
using namespace std;
int n,d,k,cnt=0,g=0;
struct point
{
	int p,v;
}f[500000];
bool srch(int curr,int s)
{
	if(s>=k)return true;
	int i=curr;
	while(++i<n&&f[i].p-f[curr].p<=d+g)
	{
		if(f[i].p-f[curr].p<d-g)continue;
		if(srch(i,s+f[i].v))return true;
	}
	return false;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&f[i].p,&f[i].v);
		if(f[i].v>0)cnt+=f[i].v;
	}
	if(cnt<k)printf("-1");
	else
	{
		while(1)
		{
			if(srch(-1,0))break;
			g++;
		}
		printf("%d",g);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
