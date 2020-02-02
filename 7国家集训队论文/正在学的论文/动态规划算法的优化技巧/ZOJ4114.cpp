#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 200
#define mod 19260817
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

int C[maxn+5][maxn+5];
void ini(int n){
//	fact[0]=1; 
//	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
//	invfact[n]=inv(fact[n]);
//	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
	C[0][0]=1;
	for(int i=1; i<=n; i++) {
		C[i][0]=1;
		for(int j=1; j<=i; j++) {
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
//inline ll C(int n,int m){
//	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
//}

int n,m,k;
int a[maxn+5];
int s[maxn+5],t[maxn+5];
int dp[2][maxn+5];


int main(){
	scanf("%d %d %d",&n,&m,&k);
	ini(n);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	int tot=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		if(s[i]!=t[i]) tot++;
	}
	int now=0;
	dp[now][tot]=1;
	now^=1;
	for(int i=1;i<=k;i++){
//		for(int j=0;j<=n;j++) dp[now][j]=0;
		memset(dp[now],0,sizeof(dp[now]));
		for(int u=1;u<=m;u++){
			for(int j=0;j<=n;j++){
				for(int v=0;v<=n;v++){
					//x+y=a[u]
					//v-x+y=j
					int x=(v+a[u]-j)>>1;
					int y=a[u]-x;
					if(x<0||y<0||x>v||y>n-v||v-x+y!=j) continue;
					dp[now][j]+=1ll*dp[now^1][v]*C[v][x]%mod*C[n-v][y]%mod;
					dp[now][j]%=mod;
				}
			}
		}
		now^=1;
	}
	printf("%d\n",dp[now^1][0]);
}
