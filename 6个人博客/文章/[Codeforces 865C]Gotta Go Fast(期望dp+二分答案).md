## [Codeforces 865C]Gotta Go Fast(期望dp+二分答案) 

### 题面

一个游戏一共有n个关卡，对于第i关，用a[i]时间通过的概率为p[i],用b[i]通过的时间为1-p[i]，每通过一关后可以选择继续下一关或者时间清0并从第一关开始，先要求通过所有关卡的时间和不能超过R才算彻底通关，问直到彻底通关位置的游戏时间的期望值为多少

### 分析

二分从头开始通关的用时期望mid

设$dp[i][j]$表示通前i关，当前时间为j的期望，倒推期望.

若超时重新开始，则$dp[i][j]=mid​$

若用方法a通过这一关，则更新j，$(dp[i+1][j+a[i]]+a[i])*p[i]$

用方法b同理

总而言之，有$$dp[i][j]=min(mid,(dp[i+1][j+a[i]]+a[i])*p[i],(dp[i+1][j+b[i]]+b[i])*(1-p[i]))$$

如果最终答案$dp[1][0]<mid$，就缩小二分范围，否则增大二分范围

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50
#define maxv 5000
#define maxrb 1e10
#define maxt 150 //二分答案迭代次数，处理精度 
using namespace std;
int n,r;
int a[maxn+5],b[maxn+5];
double p[maxn+5];
double dp[maxn+5][maxv+5];
//dp[i][j]第i关，用时j通关的期望
//二分从1关开始通完的期望mid 
bool check(double mid){
	for(int i=n;i>=1;i--){
		for(int j=r+1;j<=maxv;j++){
			dp[i+1][j]=mid;
			//通关超过时间限制，回到起点重新开始 
		}
		for(int j=0;j<=r;j++){
			double t1=(dp[i+1][j+a[i]]+a[i])*p[i];
			double t2=(dp[i+1][j+b[i]]+b[i])*(1-p[i]);
			dp[i][j]=min(mid,t1+t2);
		}
	}
	if(dp[1][0]<mid) return 1;//如果实际dp值比二分值更小，可以继续缩小二分范围 
	else return 0;
} 
int main(){
	scanf("%d %d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
		scanf("%lf",&p[i]);
		p[i]/=100;
	}
	double lb=0,rb=1e10,mid,ans=0;
	for(int i=1;i<=maxt;i++){
		mid=(lb+rb)/2;
		if(check(mid)){
			ans=mid;
			rb=mid;
		}else lb=mid;
	}
	printf("%.9lf",ans);
}

```

