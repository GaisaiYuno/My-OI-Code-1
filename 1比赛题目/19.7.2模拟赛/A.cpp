#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 500000
#define INF 0x3f3f3f3f
#define mod 1032992941
using namespace std;
int n;
int dp1[maxn+5][3];
long long dp2[maxn+5][3];
vector<int>E[maxn+5];
//dp1[x][0] x被自己控制 最小值 
//dp1[x][1] x被儿子控制 最小值
//dp1[x][2] x被父亲控制的最小值  
//dp2为方案数

void dfs(int x,int fa){
	dp1[x][0]=1;
	dp1[x][1]=0;
	dp1[x][2]=0;
	dp2[x][0]=dp2[x][1]=dp2[x][2]=1;
	for(int y : E[x]){
		if(y!=fa){
			dfs(y,x);
			int minv=min(min(dp1[y][0],dp1[y][1]),dp1[y][2]);
			long long cnt=0;
			if(dp1[y][0]==minv) cnt=(cnt+dp2[y][0])%mod; 
			if(dp1[y][1]==minv) cnt=(cnt+dp2[y][1])%mod;
			if(dp1[y][2]==minv) cnt=(cnt+dp2[y][2])%mod;
			dp1[x][0]+=minv;
			dp2[x][0]=dp2[x][0]*cnt%mod;
			
			minv=min(dp1[x][1]+min(dp1[y][0],dp1[y][1]),dp1[x][2]+dp1[y][1]);
			cnt=0;
			if(dp1[x][1]+dp1[y][0]==minv) cnt=(cnt+dp2[y][0])%mod; 
			if(dp1[x][1]+dp1[y][1]==minv) cnt=(cnt+dp2[y][1])%mod; 
			if(dp1[x][2]+dp1[y][1]==minv) cnt=(cnt+dp2[y][1])%mod; 
			dp1[x][1]=min(dp1[x][1],minv);
			dp2[x][2]=dp2[x][2]*cnt%mod;
			
			dp1[x][2]+=dp1[y][1];
			dp2[x][2]=dp2[x][2]*dp2[y][1]%mod;
		}
	}
	if(dp1[x][1]==0) dp1[x][1]=INF;
	if(dp1[x][2]==0) dp1[x][2]=INF;
} 
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	int minv=min(dp1[x][0],dp1[x][1]);
	long long cnt=0;
	if(dp1[x][0]==minv) cnt=(cnt+dp2[x][0])%mod;
	if(dp1[x][1]==minv) cnt=(cnt+dp2[x][1])%mod;
	printf("%d\n%lld\n",minv,cnt);
}

