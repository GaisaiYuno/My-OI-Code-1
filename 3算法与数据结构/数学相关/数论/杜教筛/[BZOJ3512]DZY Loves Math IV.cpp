#include<iostream>
#include<cstdio>
#include<cstring>
#include<map> 
#define maxn 3000000
#define mod 1000000007
using namespace std;
typedef long long ll;
int cnt;
int prime[maxn+5];
int vis[maxn+5];
int low[maxn+5];//x的质因子各一个乘起来得到的数 
int phi[maxn+5];
ll sum_phi[maxn+5];
void sieve(int n){
	phi[1]=1;
	vis[1]=1;
	low[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
			low[i]=i;
		}
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j] ;
				low[i*prime[j]]=low[i];
				break;
			}else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
				low[i*prime[j]]=low[i]*prime[j];
			} 
		}
	}
	for(int i=1;i<=n;i++) sum_phi[i]=(sum_phi[i-1]+phi[i])%mod;
}

map<int,ll>ans[maxn+5],ans_phi;
ll dujiao_sieve(int n){
	if(n<=maxn) return sum_phi[n];
	if(ans_phi.count(n)) return ans_phi[n];
	ll res=(ll)n*(n+1)/2;
	for(int l=2,r;l<=n;l=r+1){
		r=n/(n/l);
		res=(res-(ll)(r-l+1)*dujiao_sieve(n/l)%mod+mod)%mod;
	}
	ans_phi[n]=res;
	return res;
}
ll calc(int n,int m){
	if(m==0) return 0;
	if(n==1) return dujiao_sieve(m);
	if(ans[n].count(m)) return ans[n][m];
	ll res=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			res=(res+(ll)phi[n/i]*calc(i,m/i)%mod)%mod;
			if(i!=n/i) res=(res+(ll)phi[i]*calc(n/i,m/(n/i))%mod)%mod;
		}
	}
	ans[n][m]=res;
	return res;
}

int n,m;
int main(){
	sieve(maxn);
//	n=98765;
//	m=987654321;
	scanf("%d %d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+(ll)(i/low[i])*calc(low[i],m)%mod)%mod;
	}
	printf("%lld\n",ans);
}

