#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
#define maxn 22
#define maxm 100005
using namespace std;
long long a[maxn][maxm];
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
inline long long fast_pow(long long x,int k){
	long long ans=1;
	while(k){
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int n,m;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
	if(n==1){
		long long ans=a[1][1];
		for(int i=2;i<=m;i++){
			ans=gcd(ans,a[1][i]);
			if(ans==1) break;
		}
		printf("%lld\n",ans%mod);
	}else{
		long long ans=0;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)) cnt++;
			}
			ans+=fast_pow(m,cnt);
			ans%=mod;
		}
		ans=(ans*m)%mod;
		printf("%lld\n",ans);
	}
}
