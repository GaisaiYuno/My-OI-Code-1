#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1000000
using namespace std;
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

int maxl[maxn+5];
int son[maxn+5];
void dfs1(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs1(y,x);
			if(maxl[y]>maxl[son[x]]) son[x]=y;
		}
	}
	maxl[x]=maxl[son[x]]+1;
}

int ini[maxn+5];
int *id=ini;//把长度n的内存初始化为0,然后分给各个重链，长度之和为O(n) 
int *dp[maxn+5];
int ans[maxn+5];
void dfs2(int x,int fa){
	dp[x][0]=1;
	if(son[x]){
		dp[son[x]]=dp[x]+1;
		dfs2(son[x],x);
		ans[x]=ans[son[x]]+1;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&y!=son[x]){
			dp[y]=id;
			id+=maxl[y];//给y分配maxl的空间
			dfs2(y,x);
			for(int j=1;j<=maxl[y];j++){
				dp[x][j]+=dp[y][j-1];
				if(dp[x][j]>dp[x][ans[x]]) ans[x]=j;
				else if(dp[x][j]==dp[x][ans[x]]&&j<ans[x]) ans[x]=j;
			} 
		}
	}
	if(dp[x][ans[x]]==1) ans[x]=0;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1,0);
	dp[1]=id;
	id+=maxl[1];
	dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}

