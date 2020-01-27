#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#define maxlogm 23
#define maxn 1000000
#define maxm 1000000
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
ll inv(ll x){
	return fast_pow(x,mod-2);
}
void ini(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod; 
} 
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
}

int n,m;
int log2m;
ll dp[maxlogm+5][maxm+5];//����Ϊi����βΪj�ı��ʲ�ͬ���и��� 
ll cnt[maxlogm+5];//����Ϊi�����и���, ��sum(dp[i][j]) (1<=j<=m) 
int main(){
	scanf("%d %d",&m,&n);
	log2m=log2(m)+1;
	ini(max(n,log2m));
	for(int i=1;i<=m;i++) dp[1][i]=1;
	for(int i=1;i<log2m;i++){//a�����ﱾ�ʲ�ͬ����ֻ��O(logm)��,��˲��ö�n����dp�� 
		for(int j=1;j<=m;j++){
			for(int k=2;j*k<=m;k++){
				dp[i+1][j*k]+=dp[i][j];
				dp[i+1][j*k]%=mod;
			}
		}
	}
	for(int i=1;i<=log2m;i++){//a�����ﱾ�ʲ�ͬ����ֻ��O(logm)��,��˲��ö�n����dp�� 
		for(int j=1;j<=m;j++){
			cnt[i]+=dp[i][j];
			cnt[i]%=mod; 
		}
	}
	ll ans=0;
	for(int i=1;i<=log2m&&i<=n;i++){
		ans+=cnt[i]*C(n-1,i-1)%mod;//��n�����ֳ�i�Σ�ÿ�ζ�Ӧ�����е�һ����,��巨 
		ans%=mod;
	} 
	printf("%lld\n",ans);
}

