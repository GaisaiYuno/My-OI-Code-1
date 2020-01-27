#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define maxc 26
#define maxn 500000
using namespace std;
typedef long long ll;
int n,m;
map<string,int>id;
int a[maxn+5];
vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}

int sz[maxn+5];
int deep[maxn+5];
int fa[maxn+5],son[maxn+5];
void dfs1(int x,int f){
	sz[x]=1;
	fa[x]=f;
	deep[x]=deep[f]+1;
	for(int y : E[x]){
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}

bool vis[maxn+5];
set<int>cnt[maxn+5];
void calc(int x,int type){
	if(type==1) cnt[deep[x]].insert(a[x]);
	else{
		set<int>::iterator it=cnt[deep[x]].find(a[x]); 
		if(it!=cnt[deep[x]].end()) cnt[deep[x]].erase(it);
	}
	for(int y : E[x]){
		if(!vis[y]&&y!=fa[x]){
			calc(y,type);
		}
	} 
}


struct query{
	int v;
	int h;
	int id;
	query(){
		
	}
	query(int _v,int _h,int _id){
		v=_v;
		h=_h;
		id=_id;
	}
};
vector<query>q[maxn+5];
int ans[maxn+5];
void dfs2(int x,int is_heavy){
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
	for(query p : q[x]) ans[p.id]=cnt[deep[x]+p.h].size();
	if(!is_heavy) calc(x,-1);
}

bool is_root[maxn+5];
int main(){
	int u,v;
	char name[20];
	scanf("%d",&n);
	int ptr=0;
	for(int i=1;i<=n;i++){
		scanf("%s %d",name,&u);
		string tmp=string(name);
		if(id.count(tmp)) a[i]=id[tmp];
		else a[i]=id[tmp]=++ptr;
		if(u!=0) add_edge(i,u);
		else is_root[i]=1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		q[u].push_back(query(u,v,i));
	}
	for(int i=1;i<=n;i++){
		if(is_root[i]) dfs1(i,0);
	}
	for(int i=1;i<=n;i++){
		if(is_root[i]) dfs2(i,0);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
