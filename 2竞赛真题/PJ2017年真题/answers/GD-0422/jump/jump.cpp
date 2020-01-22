#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
#define inf 1ll<<60
ll read()
{
	ll tmp=0; char c=getchar(),f=1;
	while(c<'0'||'9'<c){if(c=='-')f=-1; c=getchar();}
	while('0'<=c&&c<='9'){tmp=tmp*10+c-'0'; c=getchar();}
	return tmp*f;
}
ll f[500010];
ll pos[500010],w[500010];
int x[500010],s[500010];
int n,d,k;
using namespace std;
bool check(int d,int u)
{
	//printf("%d %d\n",d,u);
	int i,h=1,t=0,last=0;
	for(i=1;i<=n;i++)f[i]=-inf; f[0]=0;
	for(i=1;i<=n;i++){
		while(h<=t&&pos[h]+u<x[i])++h;
		for(;last<i&&x[last]+d<=x[i];last++)
			if(x[last]+d<=x[i]&&x[i]<=x[last]+u){
				while(h<=t&&w[t]<=f[last])--t;
				pos[++t]=x[last]; w[t]=f[last];
			}
		if(h<=t)f[i]=w[h]+s[i];
		//printf("%d %d\n",h,t);
		//for(int j=h;j<=t;j++)printf("*** %d %lld %lld\n",i,pos[j],w[j]);
	}
	ll ans=-inf;
	for(i=0;i<=n;i++)ans=max(ans,f[i]);
	//printf("%lld\n",ans);
	//for(i=1;i<=n;i++)if(f[i]>-inf)printf("%lld ",f[i]);else printf("* "); printf("\n");
	if(ans>=k)return 1;else return 0;
}
int main()
{
	freopen("jump.in","r",stdin); freopen("jump.out","w",stdout);
	int i;
	n=read(); d=read(); k=read();
	for(i=1;i<=n;i++)x[i]=read(),s[i]=read(); x[0]=0; s[0]=0;
	int l=0,r=x[n]+1;
	while(l<r){
		int mid=(l+r)>>1,flag;
		if(mid<d)flag=check(d-mid,d+mid);else flag=check(1,d+mid);
		if(flag)r=mid;else l=mid+1;
	}
	if(l<=x[n])printf("%d",l);else printf("-1");
	fclose(stdin); fclose(stdout);
}
