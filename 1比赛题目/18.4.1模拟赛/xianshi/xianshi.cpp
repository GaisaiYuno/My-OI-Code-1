#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;
char in[maxn];
int dp[maxn];
int n;
int main(){
	freopen("xianshi.in","r",stdin);
	freopen("xianshi.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",in+1);
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(in[i]!=in[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	printf("%d\n",n-dp[n]);
}
