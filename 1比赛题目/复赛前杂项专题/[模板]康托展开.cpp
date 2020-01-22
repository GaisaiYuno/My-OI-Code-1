#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
#define mod 998244353
using namespace std;
typedef long long ll;
int n; 
struct fenwick_tree{
	int c[maxn+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int x,int v){
		for(int i=x;i<=n;i+=lowbit(i)) c[i]+=v;
	} 
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
}T;

ll fact[maxn+5];
int a[maxn+5];
int main(){
	scanf("%d",&n);
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		T.update(a[i],1);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		T.update(a[i],-1);
		ans=(ans+T.query(a[i])*fact[n-i]%mod)%mod;
	}
	printf("%lld\n",ans+1);
}

