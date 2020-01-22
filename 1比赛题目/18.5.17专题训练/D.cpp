#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1029
#define INF 2139062143
using namespace std;
int t,n,c1,c2;
int c[maxn];
int dp[maxn];
int status[maxn];
int used[maxn];
int is_ok(int x){
	int tot=0;
	memset(used,0,sizeof(used));
	used[0]=1;
	for(int i=0;i<n;i++){
		if(!(x&(1<<i))) continue;
		tot+=c[i+1];
		for(int j=c1;j>=c[i+1];j--){
			if(used[j-c[i+1]]) used[j]=1;//将状态x的子状态标记，可以分成两辆车运走 
		}
	} 
	if(tot>c1+c2) return 0;
	for(int i=0;i<=c1;i++){
		if(tot-i<=c2&&used[i]) return 1; 
	} 
	return 0;
}
int get_status(int *s,int n){
	int size=0;
	for(int i=1;i<(1<<n);i++){
		if(is_ok(i)) s[++size]=i;
	}
	return size;
}
int main(){
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d %d %d",&n,&c1,&c2);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		memset(dp,0x7f,sizeof(dp));
		dp[0]=0;
		int cnt=0;
	    cnt=get_status(status,n);
		for(int i=1;i<=cnt;i++){
			for(int j=(1<<n)-1;j>=0;j--){
				if(dp[j]==INF) continue;
				if(!(status[i]&j)){
					dp[j|status[i]]=min(dp[j]+1,dp[j|status[i]]);
					//状态转移方程 dp[j|status[i]]=min(dp[j]+1,dp[j|status[i]])
				}
			}
		}
		printf("Scenario #%d:\n",cas);
		printf("%d\n\n",dp[(1<<n)-1]);
	} 
	
	
} 
