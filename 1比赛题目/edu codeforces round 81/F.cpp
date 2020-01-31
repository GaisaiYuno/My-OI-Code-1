#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 998244353
#define maxn 1000
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
inline ll inv(ll x){
	return fast_pow(x,mod-2); 
} 
ll fact[maxn+5],invfact[maxn+5],invx[maxn+5];
void ini_inv(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++){
		invx[i]=invfact[i]*fact[i-1]%mod;
	}
}
inline ll C(ll n,ll m){
	ll ans=1;
	for(int i=n;i>=n-m+1;i--) ans=ans*i%mod;
	for(int i=1;i<=m;i++) ans=ans*invx[i]%mod;
	return ans;
}
int n;
struct seg{
	int l;
	int r;
}a[maxn+5];
int dn=0;
int tmp[maxn+5];//离散化用 
void discrete(){
	dn=0;
	for(int i=1;i<=n;i++){
		tmp[++dn]=a[i].l;
		tmp[++dn]=a[i].r+1;//玄学边界，要转成开区间 
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(tmp+1,tmp+1+dn,a[i].l)-tmp;
		a[i].r=lower_bound(tmp+1,tmp+1+dn,a[i].r+1)-tmp;
	}
}

ll dp[maxn+5][maxn+5];//dp[i][j]表示前i个数,第i个数在j及之后区间内的方案数
					 //枚举放在第j个区间里的个数,dp[i][j]+=dp[k-1][j+1]*C 

ll sum[maxn+5];

int main(){
	ini_inv(maxn);
	scanf("%d",&n);
	ll all=1; 
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		all=all*(a[i].r-a[i].l+1)%mod;
	} 
	discrete();
	for(int j=1;j<=dn;j++) dp[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i].l;j<a[i].r;j++){
			for(int k=i;k>0;k--){
				if(j<a[k].l||j>=a[k].r) break;
				dp[i][j]+=dp[k-1][j+1]*C(i-k+tmp[j+1]-tmp[j],i-k+1)%mod;
				//插板法,把n个物品分成m份,允许有空,C(n+m-1,m)
				//也就是说把r-l+1分成i-k+1份,再加上l,就可以保证在[l,r]内 
				dp[i][j]%=mod;
			}
		}
		for(int j=dn-1;j>=1;j--){
			dp[i][j]+=dp[i][j+1];
			dp[i][j]%=mod;
		}
	}
	printf("%lld\n",dp[n][1]*inv(all)%mod);
}
