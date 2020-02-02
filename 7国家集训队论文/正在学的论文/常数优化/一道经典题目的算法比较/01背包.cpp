/*
Problem:将N个数分成2组,使每组的和尽量相近
Source:常数优化论文 HDU 1171
Algorithm:DP
Description:
01背包模板 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 250005
#define INF 0x7fffffff
using namespace std;
int n,m,cnt; 
int a[maxn];
int dp[maxn]; 
int main(){
	int u,v;
	while(scanf("%d",&n)!=EOF){ 
		if(n==-1) break;
		m=0;
		cnt=0;
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++){
	      	scanf("%d %d",&u,&v);
	      	while(v--){
	        	a[++cnt]=u;//将价值存入数组
	        	m+=u;
	      	}
		}
		n=cnt;
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=m/2;j>=0;j--){
				dp[j]=dp[j]|(j>=a[i]&&dp[j-a[i]]);
			}
		}
		for(int j=m/2;j>=0;j--){
			if(dp[j]){
				printf("%d %d\n",max(j,m-j),min(j,m-j));
				break;
			}
		} 
	} 
}
