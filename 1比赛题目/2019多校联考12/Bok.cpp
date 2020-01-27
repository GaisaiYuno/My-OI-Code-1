#include<iostream>
#include<cstdio>
#include<cstring> 
#define mod 99824353
#define maxn 100000
#define maxb 8
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10); 
	}
}
int n,m;
ll fact[maxn+5],invfact[maxn+5];
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
void ini_fact(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	invfact[n]=inv(fact[n]);
	for(int i=n-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
ll C(int n,int m){
	return n<m?0:(fact[n]*invfact[n-m]%mod*invfact[m]%mod); 
}
int a[maxn+5];
int cnts[maxn+5][(1<<maxb)+5];
inline int bel(int x,int y){//x是y的子集 
	return (x|y)==y;
}
inline int bin_count(int x){
	int ans=0;
	for(int i=0;i<maxb;i++){
		if(x&(1<<i)) ans++;
	}
	return ans;
}
void ini_cnts(int n){
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<maxb);j++){
			cnts[i][j]=cnts[i-1][j]+bel(a[i],j);
		}
	}
}

ll query(int l,int r,int k,int t){
	ll ans=0;
	for(int i=0;i<(1<<maxb);i++){
		if(bel(i,t)){
			if(bin_count(i^t)%2==0) ans+=C(cnts[r][i]-cnts[l-1][i],k);
			else ans-=C(cnts[r][i]-cnts[l-1][i],k);
			ans=(ans+mod)%mod;
		}
	}
	return ans;
}
int main(){
	int sz,x;
	int l,r,k,t;
	qread(n);
	qread(m);
	ini_fact(n);
	for(int i=1;i<=n;i++){
		qread(sz);
		for(int j=1;j<=sz;j++){
			qread(x);
			a[i]|=(1<<x);
		}
	}
	ini_cnts(n);
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		qread(k);
		qread(sz);
		t=0;
		for(int j=1;j<=sz;j++){
			qread(x);
			t|=(1<<x);
		}
		qprint(query(l,r,k,t));
		putchar('\n'); 
	}
}
/*
2 2
2 1 2
1 1
1 2 2 2 1 2
*/ 
