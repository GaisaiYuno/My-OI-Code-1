#include<cstdio>
#include<cstdlib>

long long tot=0,num=0;
long long n,d,k,ans;
long long a[500010],s[500010];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&s[i]);
		if(i!=1 && a[i]-a[i-1]>num) num=a[i]-a[i-1];
		tot+=s[i];
	}
	if(tot<k) {printf("-1");return 0;}
	if(d==1) {printf("%d",num);return 0;}
	long long l=a[1]-d;
	if(l<0) l=-l;
	printf("%d",l);
}
