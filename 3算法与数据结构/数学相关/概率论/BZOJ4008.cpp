#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int t,n,m;
double p[maxn];
double dp[maxn][maxn];//dp[i][j]表示前i张牌还有j次没有打出的概率 
int d[maxn]; 
double pow[maxn][maxn];//pow[i][j]预处理(1-p[i])^j 
void ini(){
	memset(dp,0,sizeof(dp));
	memset(pow,0,sizeof(pow));
}
int main(){
	scanf("%d",&t);
	while(t--){
		ini();
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lf %d",&p[i],&d[i]);
		} 
		double ans=0;
		for(int i=1;i<=n;i++){
			pow[i][0]=1;
			for(int j=1;j<=m;j++){
				pow[i][j]=pow[i][j-1]*(1-p[i]);
			}
		}
		dp[0][m]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++){
				dp[i+1][j]+=dp[i][j]*pow[i+1][j];//不打第i张牌 
				if(j-1>=0){//打第i张牌 
					dp[i+1][j-1]+=dp[i][j]*(1-pow[i+1][j]);
					ans+=dp[i][j]*(1-pow[i+1][j])*d[i+1];
				} 
			}
		}
		printf("%.10f\n",ans);
	}
}

