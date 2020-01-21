//http://119.29.55.79/problem/3161
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 500000
#define INF 0x3f3f3f3f
#define mod 1032992941
using namespace std;
typedef long long ll;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
ll dp1[maxn+5][3];
ll dp2[maxn+5][3];
//dp1[x][0] x被自己控制 最小值 
//dp1[x][1] x被儿子控制 最小值
//dp1[x][2] x被父亲控制的最小值  
//dp2为方案数

void dfs(int x,int fa){
	dp1[x][0]=1;
	dp1[x][1]=INF;
	dp1[x][2]=0;
	dp2[x][0]=dp2[x][1]=dp2[x][2]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		ll minv=0;
		ll cnt=0;
		if(y!=fa){
			dfs(y,x);
			cnt=0;
			minv=min(dp1[y][0],min(dp1[y][1],dp1[y][2]));
			if(dp1[y][0]==minv) cnt+=dp2[y][0];
			if(dp1[y][1]==minv) cnt+=dp2[y][1];
			if(dp1[y][2]==minv) cnt+=dp2[y][2];
			cnt%=mod;
			dp1[x][0]+=minv;
			dp2[x][0]=dp2[x][0]*cnt%mod;
			
			cnt=0;
			minv=min(dp1[x][2]+dp1[y][0],dp1[x][1]+min(dp1[y][0],dp1[y][1]));
			if(dp1[x][1]+dp1[y][0]==minv) cnt+=dp2[y][0];
			if(dp1[x][1]+dp1[y][1]==minv) cnt+=dp2[y][1];
			cnt%=mod;
			dp1[x][1]=minv;
			dp2[x][1]=dp2[x][1]*cnt%mod; 
			if(dp1[x][2]+dp1[y][0]==minv) dp2[x][1]=(dp2[x][1]+dp2[x][2]*dp2[y][0]%mod)%mod;
			
			cnt=dp2[y][1];
			minv=dp1[y][1];
			dp1[x][2]+=minv;
			dp2[x][2]=dp2[x][2]*cnt%mod;
		}
	}

} 
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(1,0);
	ll minv=min(dp1[1][0],dp1[1][1]);
	ll cnt=0;
	if(dp1[1][0]==minv) cnt=(cnt+dp2[1][0])%mod;
	if(dp1[1][1]==minv) cnt=(cnt+dp2[1][1])%mod;
	printf("%lld\n%lld\n",minv,cnt);
}
