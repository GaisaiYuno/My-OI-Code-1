#include<cstdio>
#include<cstring>
using namespace std;
int f[1100000],a[1100000],s[1100000],n,d,k;
bool b[1100000];
int mymax(int x,int y){return x>y?x:y;}
bool pand(int x,int y)
{
	int ss=-999999999;
	for(int i=1;i<=n;i++)f[i]=-999999999;f[0]=0;
	memset(b,false,sizeof(b));b[0]=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((a[i]-a[j])<=y&&(a[i]-a[j])>=x&&(b[j]==true))
			{
				f[i]=mymax(f[i],f[j]+s[i]);b[i]=true;
			}
		}
		if(ss<f[i]&&b[i]==true)ss=f[i];
	}
	if(ss<k)return false;
	else return true;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	int ss=0;a[0]=0;s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&s[i]);
		if(s[i]>0)ss=ss+s[i];
	}
	if(ss<k)
	{
		printf("%d\n",-1);return 0;
	}
	long long l=0,r=mymax(a[n]-d,d);
	while(l<r)
	{
		int mid=(l+r)/2;
		int xx=mymax(1,d-mid),yy=d+mid;
		if(pand(xx,yy)==true)r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
