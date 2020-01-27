#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 5000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
double dp[maxn+5][maxn+5];//dp[i][j]表示前j秒辨认了i-1首的概率 
double p[maxn+5];
int t[maxn+5];
double tmp[maxn+5];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/=100;
		scanf("%d",&t[i]);
	}
	p[n+1]=0;
	t[n+1]=INF;
	dp[1][0]=1;
	for(int i=1;i<=n+1;i++){
		double p1=pow(1-p[i],t[i]);//减少计算量，卡常
		for(int j=0;j<=m;j++) tmp[j]=dp[i][j];//防止重复更新 
		for(int j=0;j<=m;j++){
			//不考虑过一段时间后会听出来 
			dp[i][j+1]+=dp[i][j]*(1-p[i]);
			dp[i+1][j+1]+=dp[i][j]*p[i]; 
			//考虑过一段时间后会听出来 
			if(j+t[i]<=m){
				dp[i+1][j+t[i]]+=tmp[j]*p1;//这里不能写dp[i][j]，因为dp[i][j]可能会在j-1的时候被更新，影响计算 
				dp[i][j+t[i]]-=tmp[j]*p1;//因为会听出来，所以减掉 
			}
		}
	}
	double ans=0;
	for(int i=1;i<=n+1;i++){
		ans+=dp[i][m]*(i-1);
	} 
	printf("%.7f\n",ans);
}
//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#define maxn 5000
//#define INF 0x3f3f3f3f
//using namespace std;
//int n,m;
//double dp[maxn+5][maxn+5];//dp[i][j]表示前j秒辨认了i-1首的概率 
//double p[maxn+5];
//int t[maxn+5];
//double tmp[maxn+5];
//int main(){
//	scanf("%d %d",&n,&m);
//	for(int i=1;i<=n;i++){
//		scanf("%lf",&p[i]);
//		p[i]/=100;
//		scanf("%d",&t[i]);
//	}
//	dp[0][0]=1;
//	for(int i=1;i<=m;i++) dp[0][i+1]+=d[0]
//	for(int i=1;i<=n;i++){
//		double p1=pow(1-p[i],t[i]);//减少计算量，卡常
//		for(int j=0;j<=m;j++) tmp[j]=dp[i][j];//防止重复更新 
//		for(int j=0;j<=m;j++){
//			//不考虑过一段时间后会听出来 
//			dp[i][j+1]+=dp[i][j]*(1-p[i]);
//			dp[i+1][j+1]+=dp[i][j]*p[i]; 
//			//考虑过一段时间后会听出来 
//			if(j+t[i+1]<=m){
//				dp[i+1][j+t[i+1]]+=tmp[j]*p1;//这里不能写dp[i][j]，因为dp[i][j]可能会在j-1的时候被更新，影响计算 
//				dp[i][j+t[i+1]]-=tmp[j]*p1;//因为会听出来，所以减掉 
//			}
//		}
//	}
//	double ans=0;
//	for(int i=0;i<=n;i++){
//		ans+=dp[i][m]*(i-1);
//	} 
//	printf("%.7f\n",ans);
//}

