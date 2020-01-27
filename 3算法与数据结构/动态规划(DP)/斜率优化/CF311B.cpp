#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxp 100
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,p;
int d[maxn+5];
int h[maxn+5];
int t[maxn+5];
long long a[maxn+5];//为了接到第i只猫的最早出发时间 
long long sa[maxn+5];//a的前缀和 
long long dp[maxp+5][maxn+5];//dp[i][j]前i个饲养员带走前j只猫 

//dp[i][j]=dp[i-1][k]+a[j]*(j-k)-(s[j]-s[k]) (0<k<j)
//dp[i-1][k]+s[k]=a[j]*k+dp[i][j]-a[j]*j+s[j]
//直线斜率a[j],候选点坐标(k,dp[i-1][k]+s[k]) 
int head,tail;
int q[maxn+5];
inline long long get_up(int i,int j,int k){
	return (dp[i-1][j]+sa[j])-(dp[i-1][k]+sa[k]);
}
inline long long get_down(int i,int j,int k){
	return j-k;
}
int main(){
	scanf("%d %d %d",&n,&m,&p);
	for(int i=2;i<=n;i++){
		scanf("%d",&d[i]);
		d[i]+=d[i-1];
	}	
	for(int i=1;i<=m;i++){
		scanf("%d %d",&h[i],&t[i]);
		a[i]=t[i]-d[h[i]];
	} 
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		sa[i]=sa[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		dp[0][i]=INF;
	}
	for(int i=1;i<=p;i++){
		head=tail=1;
		q[head]=0;
		for(int j=0;j<=m;j++){
			while(head<tail&&get_up(i,q[head+1],q[head])<=a[j]*get_down(i,q[head+1],q[head])) head++;
			dp[i][j]=dp[i-1][q[head]]+a[j]*(j-q[head])-(sa[j]-sa[q[head]]); 
			while(head<tail&&get_up(i,q[tail],q[tail-1])*get_down(i,j,q[tail])>=get_up(i,j,q[tail])*get_down(i,q[tail],q[tail-1])) tail--;
			q[++tail]=j;//j才是要加入的新解，不要写成i 
		}
		for(int j=0;j<=m;j++){
			q[j]=0;
		}
	}
	printf("%I64d\n",dp[p][m]);
}

