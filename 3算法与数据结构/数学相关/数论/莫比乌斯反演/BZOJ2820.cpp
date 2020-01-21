//http://119.29.55.79/problem/394 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 10000000
using namespace std;
typedef long long ll;
int t,n,m;
int cnt;
int prime[maxn+5];
bool vis[maxn+5];
int mu[maxn+5];
ll g[maxn+5];
ll sumg[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i]=-1;
			prime[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j*prime[i]<=n;j++){
			g[prime[i]*j]+=mu[j];
		}
	}
	for(int i=1;i<=n;i++){
		sumg[i]=sumg[i-1]+g[i];
	}
} 

int cas;
ll calc(int n,int m){
	int nn=min(n,m);
	ll ans=0;
	for(int l=1,r;l<=nn;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sumg[r]-sumg[l-1])*(n/l)*(m/l);
	}
	return ans;
}
int main(){
	sieve(maxn);
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&n,&m);
		printf("%lld\n",calc(n,m));
	}
}

