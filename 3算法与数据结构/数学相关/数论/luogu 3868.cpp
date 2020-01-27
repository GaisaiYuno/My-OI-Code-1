#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15
using namespace std;
int n;
typedef long long ll;
ll a[maxn],b[maxn];
ll qmul(ll x,ll k,ll mod){
	ll ans=0;
	while(k){
		if(k&1) ans=(ans+x)%mod;
		x=(x+x)%mod;
		k>>=1;
	}
	return ans;
} 
void exgcd(ll a,ll b,ll& x,ll& y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll x2=x;
	ll y2=y;
	x=y2;
	y=x2-(a/b)*y2;
}
ll solve(){
	ll x0=0;
	ll N=1;
	for(int i=1;i<=n;i++) N=N*b[i];
	ll xi,yi;
	for(int i=1;i<=n;i++){
		exgcd(b[i],N/b[i],xi,yi);
		yi=(yi%b[i]+b[i])%b[i]; 
//		x0=(x0+yi*N/b[i]*a[i])%N;
		x0=(x0+qmul(qmul(yi,N/b[i],N),a[i],N))%N;
	}
	return x0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++){
		a[i]=(a[i]%b[i]+b[i])%b[i]; 
	} 
	printf("%lld\n",solve());
} 
