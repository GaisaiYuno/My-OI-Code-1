#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct block{
	long long di;
	int sc;
	bool f=0;
}a[500005];
int n,d,fs=0;
long long k,sum,tem,dis[500000];
bool f=1;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%lld",&n,&d,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld%d",&a[i].di,&a[i].sc);
		if(a[i].sc>0) {sum+=a[i].sc;a[i].f=1;}
		else fs=min(fs,a[i].sc);
	}
	if(sum<k){printf("-1");return 0;}
	dis[1]=a[1].di;
	for(int i=n;i>=2;i--) dis[i]=a[i].di-a[i-1].di;
    for(int i=1;i<=a[n].di-a[1].di;i++)
    {
    	tem=k;
    	f=1;
    	for(int j=1;j<=n;j++)
    	{
    		if(i<=d&&(dis[j]<d-i||dis[j]>d+i)) {f=0;break;}
       		if(i>d&&dis[j]>d+i) {f=0;break;}
    		tem-=a[j+1].sc;
    	}
    	tem+=fs;
    	if(f==1&&tem<=0) {printf("%d",i);break;}
    }
	return 0;
}
