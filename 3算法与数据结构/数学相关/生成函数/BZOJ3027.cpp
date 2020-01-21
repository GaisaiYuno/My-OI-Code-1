#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 2004
#define maxn 10
using namespace std;
typedef long long ll;
int n,a,b;
ll sum=0; 
ll factn;
int cnt[maxn+5];
ll C(int n,int m){
	if(n<m) return 0;
	ll ans=1; 
	ll p=factn*mod;
	for(ll i=n;i>=n-m+1;i--)ans=ans*i%p;
	return (ans/factn)%mod;
}
void dfs(int deep,int k,int i,int a){//k*x^i 
	if(deep>n){
		sum+=k*C(n+a-i,n)%mod; 
		sum%=mod;
		return;
	} 
	dfs(deep+1,k,i,a);//*1
	dfs(deep+1,-k,i+cnt[deep]+1,a); //*(-x^(cnt[deep]+1)) 
}
ll calc(ll a){
	sum=0;
	dfs(1,1,0,a);
	return sum;
}


int main(){
	scanf("%d %d %d",&n,&a,&b);
	factn=1;
	for(int i=1;i<=n;i++) factn=factn*i;
	for(int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	ll ans=calc(b)-calc(a-1);
	ans=(ans+mod)%mod;
	ans=(ans+mod)%mod;
	printf("%lld\n",ans); 
}

