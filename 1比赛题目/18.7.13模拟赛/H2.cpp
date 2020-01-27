#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m1,m2,t;
int map[maxn][2];
int dp[maxn][2];
int from[maxn][2];
int last,last0;
int ans1,ans2;
int ansx[maxn],ansy[maxn];
void out(int pos,int x){
	if(from[pos][x]!=x) ans1++;
	if(pos!=0) out(pos-1,from[pos][x]);
	if(pos==0) printf("%d\n",ans1);
	if(from[pos][x]!=x){
		printf("%d ",pos);
		last0=pos;
	}
	if(map[pos][x]){
		ans2++;
		if(from[pos][x]!=x) {
			ansx[ans2]=max(last+t,last0);
			ansy[ans2]=2-x;
		} else {
			ansx[ans2]=max(last+t,last0);
			ansy[ans2]=x+1;
		}
		last=ansx[ans2]; 
	}
	if(map[pos][from[pos][x]] && from[pos][x]!=x) {
		ans2++;
		ansx[ans2]=pos-1;
		ansy[ans2]=2-x;
		last=pos-1;
	}
}
int main() {
	int x;
	scanf("%d %d %d %d",&n,&m1,&m2,&t);
	for(int i=1; i<=m1; i++) {
		scanf("%d",&x);
		map[x][0]=1;
	}
	for(int i=1; i<=m2; i++) {
		scanf("%d",&x);
		map[x][1]=1;
	}
	int turn=0;
	if(dp[1][0]<0&&dp[1][1]<0){
		printf("No\n");
		return 0;
	}
	for(int i=1; i<=n+1; i++) {
		dp[i][0]=dp[i-1][0]+1;
		dp[i][1]=dp[i-1][1]+1;
		int to0=dp[i-1][1]+1<t?(dp[i-1][1]+1):t;
		int to1=dp[i-1][0]+1<t?(dp[i-1][0]+1):t;
		from[i][0]=0;
		from[i][1]=1;
		if(map[i][0]){
			dp[i][1]=max(dp[i][1],to1-t);
			if(dp[i][1]==to1-t) from[i][1]=0;
		}else{
			dp[i][1]=max(dp[i][1],to1);
			if(dp[i][1]==to1) from[i][1]=0;
		}
		if(map[i][1]){
			dp[i][0]=max(dp[i][0],to0-t);
			if(dp[i][0]==to0-t) from[i][0]=1;
		}else{
			dp[i][0]=max(dp[i][0],to0);
			if(dp[i][0]==to0) from[i][0]=1;
		}
		if(dp[i][0]<0&&dp[i][1]<0){
			printf("No\n");
			return 0;
		}
		if(map[i][0]==1) dp[i][0]=dp[i-1][0]-t+1;
		if(map[i][1]==1) dp[i][1]=dp[i-1][1]-t+1;
	}
	if(dp[n][0]>0) {
		puts("Yes");
		out(n,0);
		printf("\n%d\n",ans2);
		for(int i=1; i<=ans2; i++)
			printf("%d %d\n",ansx[i],ansy[i]);
	} else if(dp[n][1]>0) {
		puts("Yes");
		out(n,1);
		printf("\n%d\n",ans2);
		for(int i=1; i<=ans2; i++)
			printf("%d %d\n",ansx[i],ansy[i]);
	} else {
		puts("No");
	}
}
