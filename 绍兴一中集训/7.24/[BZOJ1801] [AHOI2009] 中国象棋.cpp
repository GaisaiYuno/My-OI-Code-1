#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define mod 9999973
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

int n,m;
ll dp[maxn+5][maxn+5][maxn+5];
//dp[i][j][k] 前i行，j列只有1个棋子，k列只有2个棋子 
//显然每列不能超过3个 
inline ll calc(ll x){
	return x*(x-1)%mod*inv(2)%mod;
//	return x*(x-1)/2; 
}
int main(){
	scanf("%d %d",&n,&m);
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m-j;k++){
				//不放棋子 
				dp[i][j][k]+=dp[i-1][j][k];
				//放1个棋子
				//放在有1个棋子的列,(j+1)->j,(k-1)->k, 这样的列有j+1个  
				if(k-1>=0) dp[i][j][k]+=dp[i-1][j+1][k-1]*(j+1);
				//放在没有棋子的列，(j-1)->j,这样的列有m-(j-1)-k列 
				if(j-1>=0) dp[i][j][k]+=dp[i-1][j-1][k]*(m-(j-1)-k);
				//放2个棋子
				//都放在有1个棋子的列 (j+2)->j (k-2)->k ,从j+2列中选两列 
				if(k-2>=0) dp[i][j][k]+=dp[i-1][j+2][k-2]*calc(j+2);
				//1个放在有1个棋子的列，1个放在没有棋子的列 (j-1+1)->j (k-1)->k
				if(k-1>=0) dp[i][j][k]+=dp[i-1][j][k-1]*j*(m-j-(k-1)); 
				//都放在没有棋子的列 (j-2)->j
				if(j-2>=0) dp[i][j][k]+=dp[i-1][j-2][k]*calc(m-(j-2)-k); 
				dp[i][j][k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=m;j++){
		for(int k=0;k<=m-j;k++){
			ans+=dp[n][j][k];
			ans%=mod;
		}
	}
	printf("%lld\n",ans);
}
