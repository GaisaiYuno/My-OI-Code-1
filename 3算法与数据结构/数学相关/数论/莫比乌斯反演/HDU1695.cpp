#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
using namespace std;
typedef long long ll;
int t;
int n,m,e;
int cnt;
int mu[maxn+5];
int prime[maxn+5];
bool vis[maxn+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			mu[i]=-1; 
		}
		for(int j=1;j<=cnt&&(ll)i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]!=0) mu[i*prime[j]]=-mu[i];
			else{
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
}
int main(){
	int a,c;
	sieve(maxn);
	scanf("%d",&t);
	for(int p=1;p<=t;p++){
		scanf("%d %d %d %d %d",&a,&n,&c,&m,&e);
		if(e==0){
			printf("Case %d: %lld\n",p,0);
			continue;
		}
		n/=e;
		m/=e;
		if(n<m) swap(n,m);
		long long ans=0;
		long long sum=0;
		for(int i=1;i<=m;i++) ans+=(ll)(n/i)*(m/i)*mu[i];
		for(int i=1;i<=m;i++) sum+=(ll)(m/i)*(m/i)*mu[i];
		printf("Case %d: %lld\n",p,ans-sum/2);
	}
} 
