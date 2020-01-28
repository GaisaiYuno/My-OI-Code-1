#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 10005
using namespace std;
int numb;
long long n,q,ta,tb,A,B;
long long pa[maxn],pb[maxn];
inline long long fast_pow(long long x,long long k,long long mod) {
	long long ans=1;
	while(k) {
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}
inline long long inv(int x,int mod) {
	return fast_pow(x,mod-2,mod);
}
long long f[maxn];
const int mod=998244353;
long long get_ans(int l,int r) {
	long long ebasic=0;
	for(int i=l; i<=r; i++) {
		ebasic+=pa[i]*inv(pb[i],mod);
		ebasic%=mod;
	}
	ebasic*=A;
	ebasic%=mod;
	memset(f,0,sizeof(f));
	for(int i=l; i<=r; i++) {
		f[i]=pa[i]%mod*inv(pb[i],mod)%mod*(f[i-1]+1)%mod+(pb[i]-pa[i])%mod*inv(pb[i],mod)%mod*f[i-1]*ta%mod*inv(tb,mod)%mod;
		f[i]%=mod;
	}
	long long ecombo=0;
	for(int i=l; i<=r; i++) {
		ecombo+=f[i];
		ecombo%=mod;
	}
	ecombo*=B;
	ecombo%=mod;
	return ecombo+ebasic;
}
int main() {
	int cmd,wa,wb,l,r,x;
	scanf("%d",&numb);
	scanf("%d %d %d %d %d %d",&n,&q,&ta,&tb,&A,&B);
	for(int i=1; i<=n; i++) {
		scanf("%d %d",&pa[i],&pb[i]);
	}
	for(int i=1; i<=q; i++) {
		scanf("%d",&cmd);
		if(cmd==0) {
			scanf("%d %d %d",&x,&wa,&wb);
			pa[x]=wa;
			pb[x]=wb;
		} else {
			scanf("%d %d",&l,&r);
			printf("%lld\n",get_ans(l,r)%mod);
		}
	}
}
