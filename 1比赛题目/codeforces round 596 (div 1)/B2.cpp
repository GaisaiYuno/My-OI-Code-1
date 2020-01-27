#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define G 3
#define mod 206158430209ll 
#define invG 334845270
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k,ll m){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%m;
		x=x*x%m;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x,ll m){
	return fast_pow(x,m-2,m); 
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
		ll gn1=fast_pow((type==1?G:invG),(mod-1)/sz,mod);
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
		ll invn=inv(n,mod);
		for(int i=0;i<n;i++) x[i]=x[i]*invn%mod; 
	}
} 

int n,m,C,S,g;
int a[maxn+5];
int lg[maxn+5];
ll f[maxn+5],ans[maxn+5];
inline int get_root(int x){
	static ll p[maxn+5];//分解质因数
	int cnt=0; 
	ll phi=x-1;
	for(int i=2;phi!=1;i++){
		if(phi%i==0) p[++cnt]=i;
		while(phi%i==0) phi/=i;
	}
	for(int i=2;;i++){
		bool flag=1;
		for(int j=1;j<=cnt;j++){
			if(fast_pow(i,(x-1)/p[j],x)==1){//注意是模m不是模mod 
				flag=0;
				break; 
			}	 
		}
		if(flag) return i;
	}
	return -1;
}

void mul(ll *a,ll *b,ll *ans,int sz){
	static ll tmpa[maxn+5],tmpb[maxn+5];
	for(int i=0;i<m;i++){
		tmpa[i]=a[i];
		tmpb[i]=b[i];
	}
	for(int i=m;i<sz;i++) tmpa[i]=tmpb[i]=0;
	NTT(tmpa,sz,1);
	NTT(tmpb,sz,1);
	for(int i=0;i<sz;i++) ans[i]=tmpa[i]*tmpb[i]%mod;
	NTT(ans,sz,-1);
	for(int i=sz-1;i>=m-1;i--){
		ans[i%(mod-1)]+=ans[i];
		ans[i]=0;//注意指数取模m-1 
	}
}


int k; 
int main(){
	scanf("%d %d",&n,&k);
	g=3;
	for(int i=0,x=1;x<100000;i++){
		lg[x]=i;
		x=x*g%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		f[lg[a[i]]]=1;
		printf("%d\n",lg[a[i]]);
	}

}
