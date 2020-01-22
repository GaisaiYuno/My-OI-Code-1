//先考虑贪心，显然k个节点形成一棵树
//求出树的直径，显然直径应该只被经过1次(最长的边应该走最少次数)，其他非直径上的边被经过2次
//整体的形状应该类似一条链上接着许多子树
//考虑树形DP
//子状态：dp[x][i][j] j=0/1/2,表示以x为根的子树中选了i个点，i个点中有j个直径的端点时的长度之和
//状态转移方程:
//x为y的父亲，j为x子树去掉y子树后子树内选的点的个数,k为y子树内选的点的个数 
//dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]+len*2);
//	x,y的子树均不包含直径，边(x,y)属于子树内部的边，被算了2次
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][0]+dp[y][k][1]+len);
//	y的子树包含直径的1个端点，则直径一定经过y，边(x,y)在直径上只被算1次
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]+len*2);
//	x的子树(去掉y子树，下同)包含直径的1个端点，y的子树不包含直径的端点，通过边(x,y)与直径相连，被算2次
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][2]+dp[y][k][0]+len*2);
//	x的子树包含直径的2个端点，y的子树不包含直径的端点，通过边(x,y)与直径相连，被算2次
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][0]+dp[y][k][2]+len*2);
//	y的子树包含直径的2个端点，则直径一定不经过边(x,y)，边(x,y)被算2次
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][1]+dp[y][k][1]+len);
//	x,y的子树各包含直径的1个端点，直径一定过(x,y),边(x,y)被算1次
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3005
#define INF 0x3f3f3f3f3f3f3f3f
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
struct edge {
	int from;
	int to;
	int next;
	long long len;
	edge() {

	}
	edge(int u,int v,long long w,int hd) {
		from=u;
		to=v;
		next=hd;
		len=w;
	}
} E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v,long long w) {
	E[++ecnt]=edge(u,v,w,head[u]);
	head[u]=ecnt;
}

int sz[maxn];
long long dp[maxn][maxn][3];
void dfs(int x,int fa) {
	sz[x]=1;
	dp[x][1][0]=dp[x][1][1]=0;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		long long len=E[i].len;
		if(y!=fa) {
			dfs(y,x);
			//j类似01背包中的第二层，为防止被算多次，倒序循环 
			for(int j=min(sz[x],m); j>=0; j--) {//j为x子树去掉y子树后子树内选的点的个数 
				for(int k=min(sz[y],m-j); k>=0; k--) {//k为y子树内选的点的个数 
					dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]+len*2);
					//x,y的子树均不包含直径，边(x,y)属于子树内部的边，被算了2次
					dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][0]+dp[y][k][1]+len);
					//y的子树包含直径的1个端点，则直径一定经过y，边(x,y)在直径上只被算1次
					dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]+len*2);
					//x的子树包含直径的1个端点，y的子树不包含直径的端点，通过边(x,y)与直径相连，被算2次
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][2]+dp[y][k][0]+len*2);
					//x的子树包含直径的2个端点，y的子树不包含直径的端点，通过边(x,y)与直径相连，被算2次
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][0]+dp[y][k][2]+len*2);
					//y的子树包含直径的2个端点，则直径一定不经过边(x,y)，边(x,y)被算2次
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][1]+dp[y][k][1]+len);
					//x,y的子树各包含直径的1个端点，直径一定过(x,y),边(x,y)被算1次
				}
			}
			sz[x]+=sz[y];
		}
	}
}
int main() {
//	freopen("tree9.in","r",stdin); 
	int u,v;
	long long w;
	n=qread(); 
	m=qread();
	for(int i=1;i<n;i++){
		u=qread();
		v=qread();
		w=qread();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	long long ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][m][2]);//根据之前贪心的分析，直径一定经过这k个点中的一些点 
	}
	cout<<ans;
}
