#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200100
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
int n; 
ll h;
struct seg{
	ll l;
	ll r;
	ll len;
	ll nex;
}a[maxn];
ll sum[maxn];
ll suml[maxn];
long long work(int x){
	int pos=lower_bound(sum+1,sum+1+n,sum[x-1]+h)-sum;
	if(pos>n) pos=n;
	long long tmp=sum[pos]-sum[x-1];
	if(tmp==h){
		return suml[pos]-suml[x-1]+h;
	}else if(tmp>h){
		return suml[pos]-suml[x-1]+h;
	}
}
int main(){
	scanf("%d %I64d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%I64d %I64d",&a[i].l,&a[i].r);
		a[i].len=a[i].r-a[i].l;
	}
	for(int i=2;i<=n;i++){
		a[i-1].nex=a[i].l-a[i-1].r;
	}
	a[n].nex=INF;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].nex;
		suml[i]=suml[i-1]+a[i].len;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,work(i));
	}
	printf("%I64d\n",ans);
}
