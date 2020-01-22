#include<cstdio>
#include<algorithm>
using namespace std;
int rd()
{
	int f=1,y; char c;
	while ((c=getchar())>'9'||c<'0') if (c=='-') f=-1; y=c-'0';
	while ((c=getchar())<='9'&&c>='0') y=(y<<1)+(y<<3)+c-'0';
	return y*f;
}
int n,m;
int f[1010],tot;
int bin[10000010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	n=rd(); m=rd();
	for (int i=1;i<=n;i++) f[i]=rd();
	sort(f+1,f+n+1);
	for (int i=n;i>=1;i--)
	{
		int x=f[i]; tot=0;
		while (x)
		{
			tot++;
			x/=10;
		}
		x=10;
		for (int j=1;j<=tot;j++) bin[f[i]%x]=i,x*=10;
	}
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		if (bin[y]) printf("%d\n",f[bin[y]]);
		else puts("-1");
	}
	return 0;
}
