#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 5000
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,k,m; 
int lf[maxn+5],gf[maxn+5];
//表示a[i]和a[i-1]的相对大小,cp[i]=0无特殊条件,cp[i]=-1表示a[i-1]>a[i],cp[i]=1表示a[i-1]<a[i] 
ll dp[maxn+5][maxn+5];//dp[i][j]表示前i人，第i个人的糖果数排名为j
//转移的时候插入一个数j,更新排名 
ll sum[maxn+5];//dp[i]的前缀和 
int main(){
	int x;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		x++;
		gf[x]=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		x++;
		lf[x]=1;
	}
	dp[1][1]=1;
	for(int j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[1][j])%mod;
	for(int i=2;i<=n;i++){
		if(gf[i-1]||lf[i]){//a[i]>a[i-1]
			for(int j=1;j<=i;j++) dp[i][j]=(dp[i][j]+sum[j-1])%mod;//插一个更大的，排名为j 
		}
		else if(gf[i]||lf[i-1]){//a[i]<a[i-1]
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i][j]+(sum[n]-sum[j-1])%mod+mod)%mod;//第i-1个数的排名>=j,因为a[i]<a[i-1],加入a[i]后排名>j 
			}
		}else{//无限制 
			for(int j=1;j<=i;j++) dp[i][j]=(dp[i][j]+sum[n])%mod;
		}
		sum[0]=0;
		for(int j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[i][j])%mod;
		
	}
	ll ans=sum[n];
	printf("%lld\n",ans);
}
