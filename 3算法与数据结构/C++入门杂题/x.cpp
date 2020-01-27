/*
Problem:CF 1097D
Source:http://codeforces.com/contest/1097/problem/D
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 205
#define maxk 10005
#define mod 1000000007
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

inline long long inverse(long long x){
	return fast_pow(x,mod-2);
}

long long n,k;
int cnt=0;
long long p[maxn];
int a[maxn];
void div(long long x){
	long long i=2;
	while(i*i<=x){
		if(x%i){
			i++;
		}else{
			p[++cnt]=i;
			while(x%i==0){
				a[cnt]++;
				x/=i;
			}
		} 
	}
	if(x!=1){
		p[++cnt]=x;
		a[cnt]=1;
	}
}

long long inv[maxn];
long long dp[maxn];
long long dp_solve(long long p,int q){
	memset(dp,0,sizeof(dp));
	dp[q]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=q;j++){
			long long tmp=0;
			for(int u=j;u<=q;u++){
				tmp=(tmp+dp[u]*inv[u+1]%mod)%mod;
			}
			dp[j]=tmp;
		}
	}
	long long ans=0;
	for(int i=0;i<=q;i++){
		ans+=fast_pow(p,i)*dp[i]%mod;
		ans%=mod;
	}
	return ans;
}

int main(){
	scanf("%I64d %d",&n,&k);
	div(n);
	long long ans=1;
	for(int i=0;i<=100;i++){
		inv[i]=inverse(i); 
	}
	for(int i=1;i<=cnt;i++){
		ans*=dp_solve(p[i],a[i]);
		ans%=mod;
	}
	
	printf("%I64d\n",ans%mod);
}
