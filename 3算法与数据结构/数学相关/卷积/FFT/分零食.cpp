#include<iostream>
#include<cstdio>
#include<cstring>
#include<complex>
#define maxn 300000
#include<cmath> 
using namespace std;
typedef complex<double> com;
typedef long long ll;
const int pi=acos(-1.0);

int n,m;
ll O,S,U;
ll mod;
void fft(com *x,int *rev,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	}
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=com(1,0);
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk*=wn1;
			}
		}
	}
}

struct poly{
	int len;
	ll arr[maxn+5];
	inline int size(){
		return len;
	}
	inline ll & operator [](int i){
		return arr[i];
	}
	friend void operator += (poly &p,poly &q){
		for(int i=0;i<p.len;i++){
			p.arr[i]=(p.arr[i]+q.arr[i])%mod;
		}
	} 
};

void mul(poly &a,poly &b,poly &c){
	static int rev[maxn+5]; 
	static com tmpa[maxn+5],tmpb[maxn+5],tmpc[maxn+5];
	int m=1,k=0;
	while(m<=a.len){
		k++;
		m*=2; 
	}
	for(int i=0;i<m;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
		tmpa[i]=tmpb[i]=tmpc[i]=0;
	}
	for(int i=0;i<a.len;i++){
		tmpa[i]=a[i];
		tmpb[i]=b[i];
	}
	fft(tmpa,rev,m,1);
	fft(tmpb,rev,m,1);
	for(int i=0;i<m;i++) tmpc[i]=tmpa[i]*tmpb[i];
	fft(tmpc,rev,m,-1);
	for(int i=0;i<a.len;i++) c[i]=ll(tmpc[i].real()/m+0.5);
}

poly f,g,tmp,a;
inline void fast_pow(int k){
	if(k==1){
		f.len=g.len=m;
		for(int i=0;i<m;i++) f[i]=g[i]=a[i];
		return;
	}
	fast_pow(k>>1);
	mul(f,g,tmp);
	f+=tmp;
	mul(g,g,g);
	if(k&1){
		mul(g,a,g);
		f+=g;
	}
} 


inline ll calc(ll x){
	return O*x*x%mod+S*x%mod+U%mod;
}
int main(){
	scanf("%d %lld",&m,&mod);
	scanf("%d %lld %lld %lld",&n,&O,&S,&U);
	for(int i=1;i<=m;i++) a[i]=calc(i)%mod; 
	fast_pow(n);
	printf("%lld\n",f[m]);
}

