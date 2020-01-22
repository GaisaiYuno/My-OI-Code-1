#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 305
#define INF 1000000000
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fast_pow(ll x,ll k) {
	ll ans=1;
	while(k>0) {
		if(k&1) ans=ans*x%mod;
		k/=2;
		x=x*x%mod;
	}
	return ans;
}
ll inv(ll x) { //逆元
	return fast_pow(x,mod-2);
}
void pre_fact(ll *a) { //预处理
	a[0]=1;
	for(int i=1; i<maxn; i++) a[i]=a[i-1]*i%mod;
}
void pre_inv(ll *a,ll *b) {
	b[maxn-1]=inv(a[maxn-1]);
	for(int i=maxn-2; i>=0; i--) b[i]=b[i+1]*(i+1)%mod;
}
ll fact[maxn],invf[maxn];
ll C(ll n,ll m) {
	if(m>n) return 0;
	else if(m==n) return 1;
	else return fact[n]*invf[n-m]%mod*invf[m]%mod;
	//C(n,m)=n!/(n-m)!/m!
}
int is_persq(ll x) {
	ll l=1,r=INF;
	ll mid;
	while(l<=r) {
		mid=(l+r)>>1;
		if(mid*mid==x) return 1;
		else if(mid*mid<x) l=mid+1;
		else r=mid-1;
	}
	return 0;
}
int n;
ll a[maxn];
int used[maxn];
int cnt[maxn];
ll dp[maxn][maxn];
int size=0;
int main() {
	pre_fact(fact);
	pre_inv(fact,invf);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	for(int i=1; i<=n; i++) {
		if(used[i]) continue;
		size++;
		for(int j=i; j<=n; j++) {
			if(is_persq(a[i]*a[j])) { //将与第i个数两两相乘为完全平方数的数放入一组
				used[j]=1;
				cnt[size]++;
			}
		}
	}
	int sum=cnt[1]-1;
	dp[1][sum]=1;
	for (int i=2;i<=size;sum+=cnt[i],i++) {
		for (int j=0;j<=sum;j++) {
			if (dp[i-1][j]==0) continue;
			for (int k=0;k<cnt[i];k++) {//分成k+1组，有a[i]-1-k个间隙
				for (int p=0;p<=min(k+1,j);p++) { //插入p个间隙中
					ll tmp=dp[i-1][j]*C(cnt[i]-1,k)%mod*C(j,p)%mod*C(sum+2-j,k+1-p) % mod;
					dp[i][j+cnt[i]-1-k-p]+=tmp;
					dp[i][j+cnt[i]-1-k-p]%=mod;
				}
			}
		}
	}
	ll ans=dp[size][0];  
    for (int i=1;i<=size;i++) ans=ans*fact[cnt[i]]%mod;  
    printf("%I64d\n", ans);  
}
