/*
https://www.luogu.org/problemnew/show/U76980
把a从小到大排序 
枚举一个题a[i]，如果算出这个题在第x次被解决的方案数就能得到这种情况对答案的贡献，但好像不是很好直接算.于是考虑这题在前x次被解决的概率
先考虑我们的暴力做法：
枚举一个排列{3,1,2,4,5}，从1开始移动.假设k=2
x=1,区间中有{3,1,2} 去掉1
x=2，把4加入区间，{3,1,2,4} 去掉2 发现区间长度为[1,x+k-1]
所以方案数就是这个题在排列的前min(n,x+k-1)道题中是前i小的。差分一下就得到第i次被解决的概率
记m=min(n,x+k-1)，为第i次操作的时候曾出现过的数的总数

枚举m道题中有多少比当前题大的，记为j ,m-x<=j<=m
整个序列中大于a[i]的数有n-i个， 从中选出j个加入当前区间，C(n-i,j)
整个序列中小于a[i]的数有i-1个，从中选出m-1-j个加入当前区间 C(i-1,m-1-j)
总方案数C(n-i,j)*C(i-1,m-1-j)

由于序列还有排列顺序，先把m个数排列，再把剩下n-m个数排列， 所以sum=sigma(C(m-i,j)*C(i-1,m-1-j))*(m!)*(n-m)! 

再考虑一个题对时间的贡献
若他在第x次被解决，则x+1~n之后的时间都要增加a[i] ,贡献a[i]*(n+1-x) 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300
#define mod 1000000007
using namespace std;
typedef long long ll;
ll fact[maxn+5],invfact[maxn+5];
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
	return fast_pow(x,mod-2);
}
inline ll C(int n,int m){
	if(n<m) return 0;//小心特殊情况 
	if(n==m) return 1;
	if(m==0) return 1;
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

void pre_work(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<=n;i++) invfact[i]=inv(fact[i]);
}

int n,k; 
int a[maxn+5];
ll cnt[maxn+5];//前缀和 ，前x次被解决的方案数
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pre_work(n);
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		cnt[0]=0;
		for(int x=1;x<=n;x++){
			cnt[x]=0;
			int m=min(x+k-1,n);
			for(int j=m-x;j<m;j++){
				cnt[x]+=C(n-i,j)*C(i-1,m-j-1)%mod;
				cnt[x]%=mod;
			}
			cnt[x]=cnt[x]*fact[m]%mod*fact[n-m]%mod;
			ll dcnt=(cnt[x]-cnt[x-1]+mod)%mod;//差分 
			ans+=dcnt*a[i]%mod*(n-x+1)%mod;
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
} 
