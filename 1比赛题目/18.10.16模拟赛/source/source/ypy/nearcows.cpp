//luogu P3047
//树形DP，DP两次
//dp1[i][j]表示i的子树中与i距离为j的个数
//dp2[i][j]表示除i的子树外与i距离为j的个数
//dp1[x][j]=sum(dp[y][j-1]) x为y的父亲 
//dp2[y][j]=dp1[x][j-1]-dp1[y][j-2]+dp2[x][j-1] x为y的父亲 
// 		dp1[x][j-1]-dp1[y][j-2]表示x的子树中除了y的子树，距离为j-1的点的个数 (即除掉与y距离为j-2的点的个数)
// 		dp2[x][j-1]为x上方的点 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define maxk 25
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

inline void dprint(long long x){
	if(x==0) return;
	else dprint(x/10);
	putchar('0'+x%10);
} 

inline void qprint(long long x){
	if(x==0) putchar('0');
	else dprint(x);
	putchar('\n');
}

int n,k;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int sz=0;
int head[maxn];
inline void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int c[maxn];
long long dp1[maxn][maxk];
long long dp2[maxn][maxk];
void dfs1(int x,int fa){
	dp1[x][0]=c[x];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y==fa) continue;
		dfs1(y,x);
		for(int j=1;j<=k;j++){
			dp1[x][j]+=dp1[y][j-1];
		}
	}
}

void dfs2(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y==fa) continue;
		for(int j=1;j<=k;j++){
			if(j>=2) dp2[y][j]=dp1[x][j-1]-dp1[y][j-2]+dp2[x][j-1];
			else dp2[y][j]=dp1[x][j-1]+dp2[x][j-1];
		}
		dfs2(y,x);
	}
}
int main(){
//	freopen("nearcows.in","r",stdin);
//	freopen("nearcows.out","w",stdout);
	int u,v;
	n=qread();
	k=qread();
	for(int i=1;i<=n-1;i++){
		u=qread();
		v=qread();
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		c[i]=qread();
	}
	dfs1(1,0);
	dfs2(1,0);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=0;j<=k;j++){
			ans+=dp2[i][j]+dp1[i][j];
		}
		qprint(ans);
	}
}
