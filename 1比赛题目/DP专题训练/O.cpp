#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	long long len;
}E[maxn<<1];
int size=0;
int head[maxn];
void add_edge(int u,int v,long long w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
} 

long long dp[maxn][maxn];//dp[x][i]以x为根的子树中染i个黑点对答案的贡献 
int sz[maxn]; 
void dfs(int x,int fa){
	sz[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
	for(int i=2;i<=sz[x];i++) dp[x][i]=-1ll;
	dp[x][0]=dp[x][1]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		long long z=E[i].len;
		if(y!=fa){
			int t1=min(m,sz[x]);
			for(int j=t1;j>=0;j--){
				int t2=min(j,sz[y]);
				for(int k=0;k<=t2;k++){
					if(dp[x][j-k]!=-1){
						dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[y][k]+(long long)k*z*(m-k)+(long long)(sz[y]-k)*z*(n-m-sz[y]+k));
						//dp[x][j]=dp[x][j-k]+dp[y][k]+边(x,y,z)的贡献
						//(x,y,z)的贡献=x一侧黑子数量*z*y一侧黑子数量+x一侧白子数量*z*y一侧白子数量 
						//(x一侧即除y的子树之外的，不是x的子树中的) 
						//总共黑子m个，白子n-m个 
						//y的子树中黑子k个，白子sz[y]-k个 
						//x一侧黑子m-k个，白子n-m-sz[y]+k个 
					}
				}
			}
		}
	}
} 
int main(){
	int u,v;
	long long w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	} 
	dfs(1,0);
	printf("%lld\n",dp[1][m]);
}
