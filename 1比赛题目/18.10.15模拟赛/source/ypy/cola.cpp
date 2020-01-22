#include<iostream>
#include<cstdio>
#include<cstring>
#define maxt 1000005
#define maxm 205
#define maxn 35
#define mod 2017 
using namespace std;
inline int qread(){
	register int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,m,t;
int from[maxm],to[maxm];
long long dp[maxn][2];
long long dp2[maxn][2];
int main(){
//	freopen("cola7.in","r",stdin);
//	freopen("cola.out","w",stdout);
	int u,v;
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		from[i]=qread();
		to[i]=qread();
	}
 	t=qread();
	dp[1][0]=1;
	for(register int i=1;i<=t;i++){
		for(register int j=1;j<=n;j++){
			dp2[j][0]=dp[j][0];
			dp2[j][1]=dp[j][0];
		}
		for(register int j=1;j<=m;j++){
			u=from[j];
			v=to[j];
			dp2[u][0]=(dp[v][0]+dp2[u][0]);
			dp2[v][0]=(dp[u][0]+dp2[v][0]);
		}
		for(register int j=1;j<=n;j++){
			dp[j][1]=(dp[j][0]+dp[j][1])%mod;
			dp[j][0]=dp2[j][0]%mod;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i][0];
		ans+=dp[i][1];
	}
	printf("%lld\n",ans%mod);
} 
