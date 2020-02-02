/*
Problem:将N个数分成2组,使每组的和尽量相近
Source:常数优化论文 
Algorithm:DP
Description:
由于数最多sqrt(m)个，重复的很多，考虑多重背包
二进制拆分 
*/
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
#define maxn 10005
#define INF 0x7fffffff
using namespace std;
int n,m; 
int v[maxn],k[maxn];
int a[maxn];
bitset<maxn>dp[maxn];
void divide(){
	int newn=0;
	for(int i=1;i<=n;i++){
        for(int j=0;(1<<j)<=k[i];j++){
            a[++newn]=(1<<j)*v[i];
        }
    }
    n=newn;
} 
int main(){
	while(scanf("%d",&n)!=EOF){ 
		if(n<0) break;
		m=0; 
		for(int i=1;i<=n;i++){
			scanf("%d %d",&v[i],&k[i]);
			m+=v[i]*k[i];
		}
		for(int i=0;i<=m;i++) dp[i]=0;
		divide();
		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]|(dp[i-1]<<a[i]);
		}
		for(int j=m/2;j>=0;j--){
			if(dp[n][j]){
				printf("%d %d\n",m-j,j);
				break;
			}
		} 
	} 
}
