#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300
#define maxb 256
using namespace std;
typedef long long ll;
int n,k;
int str[maxn+5];
int c[maxn+5],w[maxn+5];
ll dp[maxn+5][maxn+5][maxb+5];//dp[l][r][s],区间[l,r]合并成s的分数 
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%1d",&str[i]);
	for(int i=0;i<(1<<k);i++){
		scanf("%d %d",&c[i],&w[i]);
	} 
	memset(dp,0x80,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i][str[i]]=0;
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			int rest=(len-1)%(k-1);//每次合并-k个,+1个，最后少k-1个 
			if(rest==0){//正好可以合并成1个 
				for(int s=0;s<(1<<k);s++){
					for(int x=r-1;x>=l;x-=(k-1)){
						if(dp[l][x][s>>1]<0||dp[x+1][r][s&1]+w[s]<0) continue;//防止两个-INF相加溢出 
						dp[l][r][c[s]]=max(dp[l][r][c[s]],dp[l][x][s>>1]+dp[x+1][r][s&1]+w[s]); 
					}
				}
			}else{
				for(int s=0;s<(1<<k);s++){
					for(int x=r-1;x>=l;x-=(k-1)){
						if(dp[l][x][s>>1]<0||dp[x+1][r][s&1]+w[s]<0) continue;
						dp[l][r][s]=max(dp[l][r][s],dp[l][x][s>>1]+dp[x+1][r][s&1]);//合并不了，没有转移代价w[s] 
					}
				}
			}
		}
	}
	ll ans=0;
	for(int s=0;s<(1<<k);s++) ans=max(ans,dp[1][n][s]);
	printf("%lld\n",ans);
}

