//floyd的本质是dp
//dp[k][i][j]表示经过前k个点时i到j的最短路
//dp[k][i][j]=min(dp[k-1][i][k]+dp[k-1][k][j],dp[k-1][i][j]
//k为阶段,所以最先循环
//实际算法中去掉第一维 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 505
using namespace std;
int n;
int del[maxn];
int _hash[maxn];//hash是关键字 
long long a[maxn][maxn];
long long dist[maxn][maxn];
long long ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%I64d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&del[i]);
		_hash[del[i]]=n-i+1;
		//反过来存储,因为floyd算法中的k代表经过前k个点时,是从少的点推到多的点 
		//删完n-1个点时节点最少,删完1个点时节点最多,正好与顺序相反
		//所以反过来推 
		//而最后一个删的节点hash成1,第一个删的hash成n,这样推才符合顺序 
		//k时推出的结果其实是删掉n-k+1个点后的结果 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[_hash[i]][_hash[j]]=a[i][j];
		}
	}
	long long sum=0;
	for(int k=1;k<=n;k++){
		sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				sum+=dist[i][j];
			}
		}
		ans[n-k+1]=sum;
	} 
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
} 
