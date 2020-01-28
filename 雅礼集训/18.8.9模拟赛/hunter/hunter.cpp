#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 998244353
#define maxn 100005
using namespace std;
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);	
}
inline long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;	
}
void div(long long &a,long long &b){
	int g=gcd(a,b);
	a/=g;
	b/=g;
}
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
inline long long inv(int x){
	return fast_pow(x,mod-2);
}
int n;
int w[maxn];
int used[maxn];
long long ansa,ansb;
void dfs(long long a,long long b,long long deep,long long sum,long long x){
	div(a,b);
	if(deep>n) return;
	if(x==1){
		ansa=ansa*b%mod+ansb*a%mod*deep%mod;
		ansb=ansb*b%mod;
		div(ansa,ansb);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			dfs(a*w[i],b*sum,deep+1,sum-w[i],i);
			used[i]=0;
		}
	}
}

int main(){
//	freopen("hunter.in","r",stdin);
//	freopen("hunter.out","w",stdout);
	ansa=0;
	ansb=1;
	int tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		tot+=w[i];
	}
	dfs(1,1,0,tot,0);
	printf("%lld",(ansa*inv(ansb)%mod)%mod);
}
