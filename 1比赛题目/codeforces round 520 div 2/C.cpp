#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define maxn 100005
using namespace std;
int n,q;
int a[maxn];
int sum[maxn];
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int main(){
	int l,r,cnt0,cnt1;
	long long ans;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&l,&r);
		cnt1=sum[r]-sum[l-1];
		cnt0=(r-l+1)-cnt1;
		ans=(fast_pow(2,cnt1)-1);
		ans=(ans+mod)%mod;
		ans=ans*fast_pow(2,cnt0)%mod;
		printf("%I64d\n",ans); 
	} 
}

