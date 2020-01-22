#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int code[1005],n,q,co,len,ans,mo,tem;
bool f;
int ten(int a)
{
	int b=1;
	for(int i=1;i<=a;i++) b*=10;
	return b;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&code[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&len,&co);
		mo=ten(len);
		for(int j=1;j<=n;j++)
		if((code[j]-co)%mo==0)
		{
			tem=code[j];
			if(ans==0) ans=tem;
			else ans=min(tem,ans);
			f=1;
		}
		if(f==0) printf("-1");
		else {printf("%d",ans);f=0;ans=0;}
	}
	return 0;
}
