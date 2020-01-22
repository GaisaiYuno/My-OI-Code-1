#include<iostream>
#include<cstdio> 
#include<cstring> 
#define maxn 205
using namespace std;
int n,m;
int dp[maxn][maxn];//dp[i][j] 以i为根节点，得到j个节点的子树最少要减掉的便数 
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2]; 
int head[maxn];
int used[maxn];
int pre[maxn];//i的子节点数目 
int cnt_son[maxn];//以i为根节点的子树子节点数目  
int size=0;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
void dfs(int root){
	cnt_son[root]=1;
	used[root]=1;
	bool is_leaf=true;
	for(int i=head[root];i;i=E[i].next){
		int son=E[i].to;
		if(used[son]) continue;
		is_leaf=false; 
		used[son]=1;
		dfs(son);
		cnt_son[root]+=cnt_son[son];
		for(int j=cnt_son[root];j>=1;j--){
			for(int k=1;k<j;k++){
				dp[root][j]=min(dp[root][j-k]+dp[son][k]-1,dp[root][j]);
			}
		}
	}
	if(is_leaf){
		dp[root][1]=0;
		cnt_son[root]=1;
		return;
	}
} 
int main(){
	int u,v;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(pre,0,sizeof(pre));
		memset(dp,0x3f,sizeof(dp));
		memset(cnt_son,0,sizeof(cnt_son));
		memset(head,0,sizeof(head)); 
		size=0;
		for(int i=1;i<=n-1;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			pre[u]++;
		}
		for(int i=1;i<=n;i++) dp[i][1]=pre[i];
		dfs(1);
        int ans=dp[1][m];
        for(int i=2;i<=n;i++) ans=min(dp[i][m]+1,ans);
        printf("%d\n",ans);
	}
}
