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

int n;
char stra[maxn+5],strb[maxn+5];
ll a[maxn+5],b[maxn+5],c[maxn+5];
ll ans[maxn+5];
int rev[maxn+5];
void fft(ll *x,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	}
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		ll gn1;
		if(type==1) gn1=fast_pow(G,(mod-1)/sz);
		else gn1=fast_pow(invG,(mod-1)/sz);
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
}
int main(){
	scanf("%d",&n);
	scanf("%s",stra);
	scanf("%s",strb);
	for(int i=0;i<n;i++) a[i]=stra[n-1-i]-'0';
	for(int i=0;i<n;i++) b[i]=strb[n-1-i]-'0';	
	int sz=1;
	int k=0;
	while(sz<n*2){
		sz*=2;
		k++;
	}
	
	for(int i=0;i<sz;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	fft(a,sz,1);
	fft(b,sz,1);
	for(int i=0;i<sz;i++) c[i]=a[i]*b[i]%mod;
	fft(c,sz,-1);
	for(int i=0;i<n*2;i++){
		ll x=c[i]*inv(sz)%mod;
		ans[i]+=x;
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	int len=n*2;
	while(ans[len]==0) len--;
	for(int i=len;i>=0;i--) printf("%lld",ans[i]);
}

