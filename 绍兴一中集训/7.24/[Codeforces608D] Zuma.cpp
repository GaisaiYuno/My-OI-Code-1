#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500
using namespace std;
int n;
int a[maxn+5];
int dp[maxn+5][maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(l==r) dp[l][l]=1;
			else if(r-l+1==2){
				if(a[l]!=a[r]) dp[l][r]=2;
				else dp[l][r]=1;
			}else{
				for(int k=l+1;k<=r;k++){
				//分成两段删除 
					dp[l][r]=min(dp[l][r],dp[l][k-1]+dp[k][r]);
				}
				//如果可以构成回文 ，就和里面的一起删 
				if(a[l]==a[r]) dp[l][r]=min(dp[l][r],dp[l+1][r-1]);
			}
		}
	}
	printf("%d\n",dp[1][n]); 
}
