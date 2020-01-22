#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m1,m2,t;
int map[maxn][2];
int dp[maxn][2];
int main() {
	int x;
	scanf("%d %d %d %d",&n,&m1,&m2,&t);
	for(int i=1; i<=m1; i++) {
		scanf("%d",&x);
		map[x][1]=1;
//		printf("debug:%d\n",x);
	}
	for(int i=1; i<=m2; i++) {
		scanf("%d",&x);
		map[x][0]=1;
//		printf("debug:%d\n",x);
	}
	int turn=0;
	for(int i=1; i<=n; i++) {
		if(map[i][0]==0){
			dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
			if(map[i][1]==0){
				int m=dp[i-1][1]<t?(dp[i-1][1]+1):(t+1);
				if(dp[i][0]<m){
					dp[i][0]=m;
					turn++;
				}				
			}
			else{
				int m=dp[i-1][1]<t?(dp[i-1][1]+1):(t+1);
				m-=t;
				if(dp[i][0]<m){
					dp[i][0]=m;
					turn++;
				}
			}
		}
		if(map[i][0]==1) {
			dp[i][0]=dp[i-1][0];
			dp[i][0]-=t;
		} 
		if(map[i][1]==0){
			dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
			if(map[i][0]==0){
				int m=dp[i-1][0]<t?(dp[i-1][0]+1):(t+1);
				if(dp[i][1]<m){
					dp[i][1]=m;
					turn++;
				}				
			}
			else{
				int m=dp[i-1][0]<t?(dp[i-1][0]+1):(t+1);
				m-=t;
				if(dp[i][1]<m){
					dp[i][1]=m;
					turn++;
				}
			}
		}
		if(map[i][1]==1) {
			dp[i][1]=dp[i-1][1];
			dp[i][1]-=t;
		}
		if(dp[i][0]<0&&dp[i][1]<0){
			printf("No\n");
			return 0;
		}
	}
	printf("%d\n",max(dp[n][0],dp[n][1]));
	for(int i=1; i<=n; i++) {
		printf("%d ",dp[i][0]);
	}
	printf("\n");
	for(int i=1; i<=n; i++) {
		printf("%d ",dp[i][1]);
	}
}
