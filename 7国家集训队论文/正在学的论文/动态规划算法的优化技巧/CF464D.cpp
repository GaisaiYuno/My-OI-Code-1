#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define maxb 700
using namespace std;
typedef double db;
int n;
db k;
db dp[2][maxb+5];
int main(){
	scanf("%d %lf",&n,&k);
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxb;j++){
			dp[now][j]=dp[now^1][j]*(k-1.0)/db(k)
					   +((dp[now^1][j+1]+j)/(j+1.0)
					   +(dp[now^1][j]+(j+1)/2.0)*j/(j+1.0))/db(k);
		}
		now^=1;
	}
	printf("%.10lf\n",k*dp[now^1][1]);
}
						  
