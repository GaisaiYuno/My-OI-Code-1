#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
#define INF 0x7fffffffffff
using namespace std;
long long n,r0,k;
long long a[maxn];
long long b[maxn];
long long d[maxn];
int check(long long mid){
	for(int i=1;i<=n;i++) b[i]=max(mid-a[i],0ll);
	memset(d,0,sizeof(d));
	long long add=0,tot=0;
	for(int i=1;i<=n;i++){
		add+=d[i];
		if(b[i]-add>0){ 
			long long need=b[i]-add;
			tot+=need;
			d[i]+=need;
			d[min(n+1,i+2*r0+1)]-=need;
			add+=need;
		} 
	}
	if(tot<=k) return 1;
	else return 0;
}

int main(){
	long long x;
	scanf("%lld %lld %lld",&n,&r0,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		a[max(1ll,i-r0)]+=x;
		a[min(n+1,i+r0+1)]-=x;
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	long long l=1,r=INF,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%lld\n",ans);
}
