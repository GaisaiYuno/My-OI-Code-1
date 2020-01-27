#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 3000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,t;
int a[maxn+5],b[maxn+5];
ll maxf[maxn+5];//消耗资源i得到最大效率
void ini(){
	for(int i=0;i<=maxn;i++) maxf[i]=-INF;
	maxf[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=maxn;j++){
			if(maxf[j-a[i]]>=0) maxf[j]=max(maxf[j-a[i]]+b[i],maxf[j]);
		}
	}
} 
ll dp[maxn+5][maxn+5];//dp[i][j] 时间i，资源j最大效率 

int main(){
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	if(m>=t){
		printf("0\n");
		return 0;
	}
	ini();
	for(int i=0;i<=maxn;i++){
		for(int j=0;j<=maxn;j++) dp[i][j]=-INF;
	}
	dp[0][m]=0;
	for(int i=0;i<=1000;i++){
		if(dp[i][t]>=0){
			printf("%d\n",i);
			return 0;
		}
		for(int j=0;j<=t;j++){
			if(dp[i][j]==-INF) continue;
			for(int k=0;k<=j;k++){
				if(maxf[k]==-INF) continue;
				int val=j-k+maxf[k]+dp[i][j];
				if(val>=t){
					printf("%d\n",i+1);
					return 0;
				}
				dp[i+1][val]=max(dp[i+1][val],dp[i][j]+maxf[k]);
			}
		}
	}

}
