#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
int d[maxn];
int l[maxn];
long long dp[maxn];
void dyna_plan(int a,int b,int x0){
	for(int i=1;i<=n;i++) dp[i]=-INF;
	for(int i=a;i<=b;i++){
		dp[i]=max(min(dp[i-1]+d[i],(long long)l[i]),min((long long)x0+d[i],(long long)l[i]));
	} 
}
int main(){
	int a,b,x0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&x0);
		long long ans=x0;
		dyna_plan(a,b,x0);
		for(int j=a;j<=b;j++)ans=max(dp[j],ans);
		printf("%lld\n",ans);
	}
}
