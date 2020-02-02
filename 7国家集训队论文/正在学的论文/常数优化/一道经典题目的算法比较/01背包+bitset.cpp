/*
Problem:将N个数分成2组,使每组的和尽量相近
Source:常数优化论文 
Algorithm:DP
Description:
01背包模板+bitset优化
将dp值压入bitset 
原来的数组dp[i][j]，将dp[i]变成一个有j位的bitset
dp[i]<<x,相当于加入x之后可以组成的数的情况 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define maxn 250005
#define INF 0x7fffffff
using namespace std;
int n,m,cnt; 
int a[maxn];
bitset<maxn>dp[maxn];
int main(){
	int u,v;
	while(scanf("%d",&n)!=EOF){ 
		if(n<0) break;
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
			dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		}
		for(int j=m/2;j>=0;j--){
			if(dp[n][j]){
				printf("%d %d\n",max(j,m-j),min(j,m-j));
				break;
			}
		} 
	} 
}
