#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5000000
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
inline void qread(ll &x){
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

int n;
ll p,k;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%p;
		x=x*x%p;
		k>>=1;
	}
	return ans;
}
inline ll inv(ll x){
//	return fast_pow(x,p-2);
	ll ans=1;
	ll k=p-2;
	while(k){
		if(k&1) ans=ans*x%p;
		x=x*x%p;
		k>>=1;
	}
	return ans;
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		qprint(x/10);
		putchar('0'+x%10);
	}
}

ll a[maxn+5];
ll pre[maxn+5],nex[maxn+5];
int main(){
	qread(n);
	qread(p);
	qread(k); 
	for(register int i=1;i<=n;i++) qread(a[i]);
	pre[0]=1;
	for(register int i=1;i<=n;i++)pre[i]=pre[i-1]*a[i]%p;
	nex[n+1]=inv(pre[n]);
	for(register int i=n;i>=1;i--)nex[i]=nex[i+1]*a[i]%p;
	
//	ll A=inv(pre[n]);
	ll ans=0;
	ll powk=1;
	for(register int i=1;i<=n;i++){
		powk=powk*k%p;
		ll ia=pre[i-1]%p*nex[i+1]%p;
		ans=(ans+powk*ia%p)%p;
	}
	qprint(ans);
}

