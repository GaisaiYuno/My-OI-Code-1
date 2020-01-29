//设dp[i][j]表示[i,j]区间的最小话费 
#include<iostream>
#include<cstdio>
#define maxn 505
using namespace std;
int n;
char s[maxn];
int dp[maxn][maxn];
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1; i<=n; i++) dp[i][i]=1;
	for(int len=2; len<=n; len++) {
		for(int i=1; i+len-1<=n; i++) {
			int j=i+len-1;
			if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+1;//直接删掉i,j 
			else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;//单独删i,或j 
			for(int k=i; k<=j; k++) {
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]-1);
				//找一个节点分成两半，对两半分别求答案再合起来，由于第k个字母被重复删了2次，答案要-1 
				//不能写成 p[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]);
				//因为这样少考虑了一种情况，如ababa,3个a可以1次删掉
				//如果单独对aba,ba考虑再求和，就变成2次了 
			}

		}
	}
	printf("%d\n",dp[1][n]);
}

