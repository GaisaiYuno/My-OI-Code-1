#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 400000
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

void NTT(ll *x,int n,int type){
	static int rev[maxn+5];
	int tn=1,k=0;
	while(tn<n){
		tn*=2;
		k++; 
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]); 
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
void mul(ll *a,ll *b,ll *ans,int n){
	NTT(a,n,1);
	NTT(b,n,1);
	for(int i=0;i<n;i++) ans[i]=a[i]*b[i]%mod;
	NTT(ans,n,-1);
}

void get_inv(ll *a,ll *b,int n){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	b[0]=inv(a[0]);
	int len;
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++){
			tmpa[i]=a[i];
			tmpb[i]=b[i];
		}
		NTT(tmpa,sz,1);
		NTT(tmpb,sz,1);
		for(int i=0;i<sz;i++) b[i]=tmpb[i]*(2-tmpb[i]*tmpa[i]%mod+mod)%mod;
		NTT(b,sz,-1);
		for(int i=len;i<sz;i++) b[i]=0;
	}
	for(int i=0;i<len;i++) tmpa[i]=tmpb[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

void get_sqrt(ll *a,ll *b,int n){
	static ll tmpa[maxn+5],invb[maxn+5];
	b[0]=1;
	int len;
	for(len=1;len<n*2;len*=2){
		int sz=len*2;
		for(int i=0;i<len;i++) tmpa[i]=a[i];
		get_inv(b,invb,len);
		mul(tmpa,invb,tmpa,sz);
		for(int i=0;i<len;i++) b[i]=inv2*(tmpa[i]+b[i])%mod;
		for(int i=len;i<sz;i++) b[i]=0;
	} 
	for(int i=0;i<len;i++) tmpa[i]=invb[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

int n,m;
ll c[maxn+5],tc[maxn+5],c2[maxn+5],invc[maxn+5],sqtc[maxn+5],ans[maxn+5];
int main(){
	int x; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		c[x]++;
	}
	int dn=1;
	while(dn<=m) dn*=2; 
	for(int i=1;i<dn;i++) tc[i]=((-4)*c[i]+mod)%mod;
	tc[0]++;//sqrt(1-4C)
	get_sqrt(tc,sqtc,dn);
	for(int i=0;i<dn;i++) sqtc[i]=(-sqtc[i]+mod)%mod;
	c2[0]=1; 
	for(int i=1;i<dn;i++)  c2[i]=c[i]*2%mod;
	get_inv(c2,invc,dn);
	mul(invc,sqtc,ans,dn);
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
} 

