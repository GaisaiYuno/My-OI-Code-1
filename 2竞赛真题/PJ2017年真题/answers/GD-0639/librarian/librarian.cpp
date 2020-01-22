#include<cstdio>
#include<algorithm>
using namespace std;
inline int getint()
{
	int r=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
		f=c=='-'?-f:f,c=getchar();
	while (c>='0'&&c<='9')
		r=(r<<3)+(r<<1)+(c^'0'),c=getchar();
	return r*f;
}
int a[1001];
inline bool check(int x,int y,int n)
{
	for (int i=1;i<=n;++i)
	{
		if (!y||x%10!=y%10)
			return false;
		x/=10,y/=10;
	}
	return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n=getint(),q=getint(),len,x,temp;
	for (int i=1;i<=n;++i)
		a[i]=getint();
	sort(a+1,a+n+1);
	bool flag;
	for (int i=1;i<=q;++i)
	{
		len=getint(),x=getint(),flag=true;
		for (int j=1;j<=n;++j)
			if (check(x,a[j],len))
			{
				flag=false;
				printf("%d\n",a[j]);
				break;
			}
		if (flag)
			puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
