//http://119.29.55.79/problem/390
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000
using namespace std;
typedef long long ll;
int cnt;
bool vis[maxn+5];
int prime[maxn+5];
int mu[maxn+5];
ll sum_mu[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;i++) sum_mu[i]=sum_mu[i-1]+mu[i];
}

int t;
int a,b,c,d,e;
ll solve(int n,int m){
	n/=e;
	m/=e;
	if(n<m) swap(n,m);
	ll ans=0;
	int l,r;
	for(l=1;l<=m;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sum_mu[r]-sum_mu[l-1])*(n/l)*(m/l);
	}
	return ans;
}

int main(){
	sieve(maxn);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		ll ans=solve(b,d)-solve(a-1,d)-solve(b,c-1)+solve(a-1,c-1);
		printf("%lld\n",ans);
	}
}
