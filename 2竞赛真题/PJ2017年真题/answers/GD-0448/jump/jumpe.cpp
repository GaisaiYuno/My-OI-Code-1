#include<cstdio>
using namespace std;
int g,k,n,d,f[501],l[501],s[501],i,j,t=0;
bool u[501];
int dfs(int step)
{
	if (step<n)
	{
		int a,b;
		a=dfs(step+1);
		u[step]=true;
		b=dfs(step+1);
		u[step]=false;
		if ((a>b&&b!=-1)||a==-1) a=b;
		return a;
	} 
	for (int i=0;i<n;i++)
		if (u[i]) t+=s[i];
	if (t<k) return -1;
	for (int i=0;i<n;i++)
		if (u[i])
		{
			if (l[i]>d) return l[i]-d;
			if (i+1==n) return d-l[i];
			if (d>l[i+1]) return d-l[i+1];
			return 0;
		}
	return -1;	
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&l[i],&s[i]);
		if (s[i]>0) t+=s[i];
	}
	if (t<k)
	{
		printf("-1");
		fclose(stdin); fclose(stdout);
		return 0;	
	}
	for (i=0;i<n;i++)
		u[i]=false;
	printf("%d",dfs(0));	
	fclose(stdin); fclose(stdout);
	return 0;	
}
