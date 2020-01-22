#include <iostream>
#include <cstdio>
#define MAXN 100
#define ll long long
const ll MOD=10000007;
ll dp[MAXN][MAXN][2];
//dp[i][j][k] i位,j个1,最高位为k
inline ll ksm(ll a,ll k){
	ll ans=1ll;
	while (k){
		if (k&1ll) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		k>>=1ll;
	}
	return ans;
} 
int main(){
    ll n;
    scanf("%lld",&n);
    ll len=0ll;
    while ((1ll<<len)<=n){
        ++len;
    }
    dp[1][0][0]=dp[1][1][1]=1ll;
    for (register ll i=2;i<=len;++i){
        for (register ll j=0;j<=i;++j){
            if (j){
                dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
            }
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
        }
    }
    ll ans=1ll,cnt=0ll;
    for (register ll i=len;i;i--){
        if ((n>>(i-1))&1){
            for (ll j=1ll;j<=i;++j){
                ans*=ksm(j+cnt,dp[i][j][0]),ans%=MOD;
            }
            if (i!=len){
                ans=ans*cnt,ans%=MOD;
            }
            ++cnt;
        }
    }
    printf("%lld\n",(ans*cnt)%MOD);
}
