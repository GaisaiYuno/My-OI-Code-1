#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100005
using namespace std;
struct edge{
	int from;
	int to;
	int next;
	int mark;//标记是原来的边还是后来加上去的边 
}E[maxn<<1];
int deg[maxn];
int size=0;
int head[maxn];
void add_edge(int u,int v,int w) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].mark=w;
	E[size].next=head[u];
	head[u]=size;
}

int num[maxn];//所在的连通块编号 
int used[maxn];
vector<int>block[maxn];//连通块中路径 
int count(int x,int cnt){//dfs求连通块 
	num[x]=cnt;
	used[x]=1;
	int ans=(deg[i]&1);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!used[y]) ans+=dfs(y,cnt);
	}
	return ans;
}

int vis_edge[maxm];
void euler(int x){
	
}
int n,m;
int main(){
//	freopen("miner.in","r",stdin);
//	freopen("miner.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++;
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	int ans=0;
	int k=0;
	for(int i=1;i<=n;i++){
		if(!used[i]&&head[x]) ans+=max(count(i,++k)/2,1);
	}
	printf("%d\n",ans-1);
	for(int i=1;i<=n;i++){
		if(deg[i]&1){
			block[num[i]].push_back(i);
		}
	} 
	for(int i=1;i<=k;i++){
		int sz=block[i].size();
		for(int j=1;j<=sz;j++){
			
		}
	}
}
