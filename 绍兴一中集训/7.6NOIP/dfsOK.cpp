#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 4000000
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k>0){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
ll inv(ll x){
	return fast_pow(x,mod-2);
}
ll fact[maxn+5],invfact[maxn+5];
void pre_work(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--){
		invfact[i]=invfact[i+1]*(i+1)%mod;
	}
}
inline ll C(int n,int m){
	if(m>n||m<0) return 0;
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int n;
int a[maxn+5];
int main(){
#ifdef DEBUG
	freopen("dfs3.in","r",stdin);
#endif
	scanf("%d",&n);
	pre_work(n*2);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]>0){
		printf("0");
		return 0;
	}
	a[1]=0;
	a[n+1]=1;
	int last=1;
	ll ans=1;
	for(int i=2;i<=n+1;i++){
		if(a[i]!=-1){
			if(a[i]==0){
				printf("0");
				return 0;
			}
			int nn=i-last-1;
			int mm=i-last-1-a[i]+a[last]+1;
			if(mm<0){
				printf("0");
				return 0;
			}
			ans*=(C(nn+mm,mm)-C(nn+mm,mm-a[last]-1))%mod;
			ans%=mod;
			last=i;
//			printf("%lld\n",ans);
		}
	}
	while(ans<0) ans+=mod;
	ans%=mod;
	printf("%lld\n",ans);
	
}



