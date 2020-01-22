#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20
#define maxk 12
#define maxs 1100
#define mod 998244353
using namespace std;
struct node {
	long long cnt;
	long long sum;
	node() {

	}
	node(int dp_val,int sum_val) {
		cnt=dp_val;
		sum=sum_val;
	}
};
int k;
long long pow10[maxn];
long long digit[maxn];
long long dp[maxs][maxn][maxk];
long long sum[maxs][maxn][maxk];
int count1(int x) {
	int cnt=0;
	while(x) {
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}
node dfs(int n,int s,int dif,int is_edge) {
	if(n<=0) return node(1,0);
	if(dp[s][n][dif]&&dif<=k) {
		return node(dp[s][n][dif],sum[s][n][dif]);
	}
	int num=is_edge?digit[n]:9;
	long long cnt=0;
	long long tot=0;
	for(int i=0; i<=num; i++) {
		int flag=0;
		if(i==num&&is_edge) flag=1;
		if(((1<<i)&s)==0) {
			if(dif<k) {
				node tmp=dfs(n-1,s|(1<<i),dif+1,flag);
				cnt=(cnt+tmp.cnt)%mod;
				tot=(tot+tmp.sum%mod);
				tot=(tot+tmp.cnt*pow10[n-1]%mod*i%mod)%mod;
			}
		} else {
			node tmp=dfs(n-1,s,dif,flag);
			cnt=(cnt+tmp.cnt)%mod;
			tot=(tot+tmp.sum%mod);
			tot=(tot+tmp.cnt*pow10[n-1]%mod*i%mod)%mod;
		}
	}
	if(!is_edge) {
		dp[s][n][dif]=cnt;
		sum[s][n][dif]=tot;
	}
	return node(cnt,tot);
}
node solve(long long n) {
	int len=0;
	memset(digit,0,sizeof(digit));
	memset(dp,0,sizeof(dp));
	while(n) {
		digit[++len]=n%10;
		n/=10;
	}
	node tmp=dfs(len,0,0,1);
	return tmp;
}
int main() {
	int t;
	pow10[0]=1;
	for(int i=1;i<=18;i++){
		pow10[i]=pow10[i-1]*10%mod;
	}
	long long l,r;
	scanf("%I64d %I64d %d",&l,&r,&k);
	node a=solve(r);
	node b=solve(l-1);
	printf("%I64d\n",a.sum-b.sum);
	printf("debug: %I64d %I64d %I64d %I64d\n",a.sum,b.sum,a.cnt,b.cnt);

}
