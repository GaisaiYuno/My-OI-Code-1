//luogu P4377
//类似01分数规划
// sum(t[i])/sum(w[i])最大
//二分当前值k
//若 sum(t[i])/sum(w[i])>=k，即sum(t[i]-k*w[i])>=0时，说明k比真正的最大值小,l=mid
//但是还有一个条件 sum(w[i])>=m
//考虑01背包，w[i]为代价，t[i]-k*w[i]为价值，dp[i]表示代价为i时的最大价值 
//那么判断条件就转化为,是否存在i∈[m,+∞) ，使得dp[i]>0
//直接DP会MLE或TLE
//我们改循环的形式，从j推到j+w[i]，则只要当 j+w[i]>m时，令j+w[i]=m即可
//相当于把 (m,+∞)的最大值存到dp[m]中 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 255
#define maxv 2000005
#define INF 1e10
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,m;
int w[maxn],t[maxn];
double v[maxn];
double dp[maxv];
int check(double k){
	for(int i=1;i<=n;i++){
		v[i]=(double)t[i]-k*w[i];
	}
	for(int i=1;i<=m;i++) dp[i]=-INF;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){//从j推到j+w[i]
			int tmp=j+w[i];
			if(tmp>m) tmp=m;//把 (m,+∞)的最大值存到dp[m]中 
			dp[tmp]=max(dp[tmp],dp[j]+v[i]);
		}
	}
	if(dp[m]>0) return 1;
	else return 0;
}
double bin_ans(){
	double l=0,r=1e9;
	for(int i=1;i<=70;i++){
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	n=qread();
	m=qread();
	for(int i=1;i<=n;i++){
		w[i]=qread();
		t[i]=qread();
	}
	double t=bin_ans();
	long long x=floor(1000.0*t);
	printf("%lld\n",x);
}
/*
1 10
15 30
*/
