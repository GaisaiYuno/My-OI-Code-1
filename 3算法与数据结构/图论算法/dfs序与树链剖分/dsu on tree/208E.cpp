#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
#define maxlogn 20
using namespace std;
int n,m;
vector<int>E[maxn+5];
bool is_root[maxn+5];
inline void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}

int deep[maxn+5];
int anc[maxn+5][maxlogn+5];
int fa[maxn+5],son[maxn+5],sz[maxn+5];
void dfs1(int x,int f){
	sz[x]=1;
	fa[x]=f;
	anc[x][0]=f;
	deep[x]=deep[f]+1;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int y : E[x]){
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y; 
		}
	}
}
inline int kth_anc(int x,int k){
	for(int i=maxlogn;i>=0;i--){
		if(k&(1<<i)) x=anc[x][i];
	}
	return x;
}


int cnt[maxn+5];
bool vis[maxn+5];
void calc(int x,int type){
	cnt[deep[x]]+=type;
	for(int y : E[x]){
		if(!vis[y]&&y!=fa[x]) calc(y,type);
	}
}

struct qtype{
	int x;
	int k;
	int id; 
	qtype(){
		
	}
	qtype(int _x,int _k,int _id){
		x=_x;
		k=_k;
		id=_id;
	}
};
vector<qtype>q[maxn+5];
int ans[maxn+5];
void dfs2(int x,bool is_heavy){
	for(int y : E[x]){
		if(y!=fa[x]&&y!=son[x]){
			dfs2(y,0);
		}
	}
	if(son[x]){
		dfs2(son[x],1);
		vis[son[x]]=1;
	}
	calc(x,1);
	vis[son[x]]=0;
	for(qtype p : q[x]) ans[p.id]=cnt[deep[p.x]]-1;//记得减去自己 
	if(!is_heavy) calc(x,-1);
}

int main(){
	int f,x,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f);
		if(f!=0) add_edge(f,i);
		else is_root[i]=1;
	}
	for(int i=1;i<=n;i++) if(is_root[i]) dfs1(i,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&k);
		int z=kth_anc(x,k);
		q[z].push_back(qtype(x,k,i));
	}
	
	for(int i=1;i<=n;i++) if(is_root[i]) dfs2(i,0);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
}

