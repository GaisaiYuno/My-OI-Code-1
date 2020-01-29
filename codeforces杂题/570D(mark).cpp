#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxc 26
#define maxn 500000
using namespace std;
typedef long long ll;
int n,m;
char a[maxn+5];
vector<int>E[maxn+5];

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
int cnt[maxn+5][maxc+5];//统计子树内每个深度的字母出现情况 
void calc(int x,int type){
	cnt[deep[x]][a[x]-'a']+=type;
	for(int y : E[x]){
		if(!vis[y]&&y!=fa[x]){
			calc(y,type);
		}
	} 
}
bool check(int h){
	int flag=0;
	for(int i=0;i<maxc;i++){
		if(cnt[h][i]%2==1) flag++;
	}
	if(flag>1) return 0;
	else return 1;
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
bool ans[maxn+5];
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
	for(query p : q[x]) ans[p.id]=check(p.h);
	if(!is_heavy) calc(x,-1);
}
 
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&u);
		E[i].push_back(u);
		E[u].push_back(i);
	}
	scanf("%s",a+1);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		q[u].push_back(query(u,v,i));
	}
	dfs1(1,0);
	dfs2(1,0); 
	for(int i=1;i<=m;i++){
		if(ans[i]) printf("Yes\n");
		else printf("No\n");
	}
}
