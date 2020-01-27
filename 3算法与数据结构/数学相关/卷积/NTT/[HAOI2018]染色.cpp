//https://www.luogu.org/problem/P4491 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 10000000
#define maxm 400000
#define G 3
#define mod 1004535809
#define invG 334845270
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
	static int rev[maxm+5];
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

ll fact[maxn+5],invfact[maxn+5];
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
inline ll C(int n,int m){
	return fact[n]*invfact[n-m]%mod*invfact[m]%mod;
} 

int n,m,s;
ll w[maxm+5]; 
ll a[maxm+5],b[maxm+5],sum[maxm+5];
int main(){
//	printf("%lld\n",inv(3));
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<=m;i++) scanf("%lld",&w[i]);
	ini_fact(max(n,m)); 
	int lim=min(n/s,m);
	int dn=1;
	while(dn<=(lim+1)*2) dn*=2;
	for(int i=0;i<=lim;i++){
		a[i]=C(m,i)*fact[n]%mod*inv(fast_pow(fact[s],i))%mod*invfact[n-s*i]%mod*fast_pow(m-i,n-s*i)%mod*fact[i]%mod; 
		//f(x)=C(m,i)*(n!)/((s!)^i(n-si)!)*(m-i)^(n-si) 
		//A(x)=f(x)x!
	}
	for(int i=0;i<=lim;i++){
		b[i]=(fast_pow(-1,lim-i)*invfact[lim-i]%mod+mod)%mod;
		//B(x)=(-1)^x/x!
	}
	mul(a,b,sum,dn);
	ll ans=0;
	for(int i=0;i<=lim;i++){
		ans=(ans+sum[i+lim]*invfact[i]%mod*w[i]%mod)%mod;
		//(A*B)(i+lim)=sum_{j=1}^{i+lim} A(j)B(i+lim-j)
		//j<i时i+lim-j>lim,B(i+lim-j)=0，被消去,j>lim时同理 
		//所以正好是\sum{j=i}^{lim} (-1)^{j-i}C(j,i)f(j)
	}
	printf("%lld\n",ans); 
} 
