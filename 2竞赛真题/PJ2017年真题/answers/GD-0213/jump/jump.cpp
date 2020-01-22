#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int inf=1e9;
int n,d,k,x[maxn],s[maxn],l,r,mid,maxx,f[maxn];
bool tf[maxn];
bool judge(int m)
{
	memset(f,0,sizeof f);
	memset(tf,false,sizeof tf);
	maxx=-inf;
	for(int i=1;i<=n;i++)
	{
		if(max(d-m,1)<=x[i]&&x[i]<=d+m)f[i]=s[i],tf[i]=true;
		for(int j=0;j<i;j++)if(tf[j]&&max(d-m,1)<=x[i]-x[j]&&x[i]-x[j]<=d+m)f[i]=max(f[i],f[j]+s[i]),tf[i]=true;
		if(tf[i])maxx=max(maxx,f[i]);
	}
	return maxx>=k;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	if(n>500){printf("-1\n");return 0;}
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,s+i),maxx+=max(s[i],0);
	if(maxx<k){printf("-1\n");return 0;}
	l=0;r=inf;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(judge(mid))r=mid;
		else l=mid;
	}
	if(r==inf)printf("-1\n");
	else printf("%d\n",judge(l)?l:r);
	fclose(stdin);fclose(stdout);
	return 0;
}
