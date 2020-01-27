#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 100000
#define mod 1000000000
using namespace std;
typedef long long ll;
int n,m;
int bin[maxn+5];
ll dp[maxn+5];
int main(){
	scanf("%d",&n);
	int m=log2(n);
	bin[0]=1;
	for(int i=1;i<=m;i++) bin[i]=bin[i-1]*2;
	dp[0]=1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(j-bin[i]>=0) {
				dp[j]+=dp[j-bin[i]];
				dp[j]%=mod;
			}
		}
	}
	printf("%I64d\n",dp[n]);
}
