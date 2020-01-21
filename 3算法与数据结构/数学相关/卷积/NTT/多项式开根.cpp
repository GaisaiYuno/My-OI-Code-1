//https://www.luogu.org/problem/P5205
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define G 3
#define invG 332748118
#define inv2 499122177
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


void NTT(ll *x,int *rev,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	} 
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		ll gn1=(type==1?fast_pow(G,(mod-1)/sz):fast_pow(invG,(mod-1)/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			ll gnk=1;
			for(int i=l;i<=r;i++){
				ll tmp=x[i+len];
				x[i+len]=(x[i]-gnk*tmp+mod)%mod;
				x[i]=(x[i]+gnk*tmp%mod)%mod;
				gnk=gnk*gn1%mod;
			}
		} 
	}
}
void mul(ll *a,ll *b,ll *ans,int sz){
	static int rev[maxn+5];
	for(int i=0;i<sz;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?sz/2:0);
	NTT(a,rev,sz,1);
	NTT(b,rev,sz,1);
	for(int i=0;i<sz;i++) ans[i]=a[i]*b[i]%mod;
	NTT(ans,rev,sz,-1);
	ll invsz=inv(sz);
	for(int i=0;i<sz;i++) ans[i]=ans[i]*invsz%mod;
}

void get_inv(ll *a,ll *b,int n){
	static int rev[maxn+5];
	static ll tmpa[maxn+5];
	static ll tmpb[maxn+5];
	b[0]=inv(a[0]);
	int len;
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++){
			tmpa[i]=a[i];
			tmpb[i]=b[i];
		}
		for(int i=0;i<sz;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?len:0);
		NTT(tmpa,rev,sz,1);
		NTT(tmpb,rev,sz,1);
		for(int i=0;i<sz;i++) b[i]=(2-tmpa[i]*tmpb[i]%mod+mod)*tmpb[i]%mod;
		NTT(b,rev,sz,-1);
		ll invsz=inv(sz);
		for(int i=0;i<sz;i++) b[i]=b[i]*invsz%mod;
		for(int i=len;i<sz;i++) b[i]=0;
	}
	for(int i=0;i<len;i++) tmpa[i]=tmpb[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

void sqrt(ll *a,ll *b,int n){
	b[0]=1;
	int len=1;
	static ll tmpa[maxn+5],invb[maxn+5],tmpc[maxn+5]; 
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++) tmpa[i]=a[i];
		get_inv(b,invb,len);
		mul(tmpa,invb,tmpc,sz);
		for(int i=0;i<len;i++) b[i]=(tmpc[i]+b[i])*inv2%mod; //a[x]/(2b[x])+b[x]/2 
		for(int i=len;i<sz;i++) b[i]=0; 
	} 
	for(int i=0;i<len;i++) tmpa[i]=invb[i]=tmpc[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
} 
int n;
ll f[maxn+5],g[maxn+5];
int main(){		
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&f[i]);
	sqrt(f,g,n);
	for(int i=0;i<n;i++) printf("%lld ",(g[i]+mod)%mod);																													
}
