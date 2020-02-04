//http://119.29.55.79/problem/1500 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define G 3
#define invG 332748118
#define mod 998244353
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

int n,m,tot,L;
int rev[maxn+5];
void ntt(ll *x,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	}
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		ll gn1=fast_pow((type==1?G:invG),(mod-1)/sz);
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			ll gnk=1;
			for(int i=l;i<=r;i++){
				ll tmp=x[i+len];
				x[i+len]=(x[i]-gnk*tmp%mod+mod)%mod;
				x[i]=(x[i]+gnk*tmp%mod)%mod;
				gnk=gnk*gn1%mod;
			}
		}
	}
	if(type==-1){
		ll invn=inv(n);
		for(int i=0;i<n;i++) x[i]=x[i]*invn%mod;
	}
} 
void mul(ll *a,ll *b,ll *c){
	static ll ta[maxn+5],tb[maxn],tc[maxn+5];
	for(int i=0;i<=m;i++){
		ta[i]=a[i];
		tb[i]=b[i];
	}
	ntt(ta,tot,1);
	ntt(tb,tot,1);
	for(int i=0;i<=tot;i++) tc[i]=ta[i]*tb[i]%mod;
	ntt(tc,tot,-1);
	for(int i=m+1;i<=tot;i++) ta[i]=tb[i]=0;
	for(int i=0;i<=m;i++) c[i]=tc[i]; 
}
void poly_pow(ll *x,int k,ll *ans){
	while(k){
		if(k&1) mul(ans,x,ans);
		mul(x,x,x);
		k>>=1;
//		for(int i=0;i<=m;i++) printf("%lld ",ans[i]);
//		printf("\n");
	}
}

ll f[maxn+5],v[maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	tot=1;
	while(tot<=m*2){
		tot*=2;
		L++;
	}
	for(int i=0;i<=m;i++){
		f[i]=1;
		scanf("%lld",&v[i]);
	}
	for(int i=0;i<tot;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	poly_pow(v,n-1,f);
	ll ans=0;
	for(int i=0;i<=m;i++){
		ans=(ans+f[i])%mod;
	}
	printf("%lld\n",ans);
}

