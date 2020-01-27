//https://www.cnblogs.com/littlewyy/p/10826650.html
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxb 20
#define maxv 1000000
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1; 
	}
	return ans;
} 
int count(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}
int n;
ll sum[(1<<maxb)+5];
void get_sum(){
	for(int i=0;i<maxb;i++){
		for(int j=maxv;j>=1;j--){
			//类似滚动数组
			if(j&(1<<i)) sum[j^(1<<i)]+=sum[j];
		}
	}

}
 
int a[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	get_sum();
	ll ans=0;
	for(int i=0;i<(1<<20);i++){
		ll now=fast_pow(2,sum[i])-1;
		now=(now+mod)%mod;
		ans=(ans+fast_pow(-1,count(i))*now%mod+mod)%mod;
	}
	printf("%I64d\n",ans);
}
