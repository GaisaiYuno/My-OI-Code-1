//template: dsu on tree
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
vector<int>E[maxn+5];

int sz[maxn+5];
int fa[maxn+5],son[maxn+5];
void dfs1(int x,int f){
	sz[x]=1;
	fa[x]=f;
	for(int y : E[x]){
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
}

bool vis[maxn+5];
int cnt[maxn+5]; 
ll sum[maxn+5];//出现次数为i的颜色的编号和 
ll ans[maxn+5];
int top=0;
void calc(int x,int type){//type=1加入,type=-1擦除 
	sum[cnt[a[x]]]-=a[x];
	cnt[a[x]]+=type;
	sum[cnt[a[x]]]+=a[x];
	if(sum[top+1]) top++;
	else if(top>0&&sum[top]==0) top--;
	for(int y : E[x]){
		if(vis[y]||y==fa[x]) continue;
		calc(y,type);
	}
}
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
	ans[x]=sum[top];
	if(!is_heavy) calc(x,-1);
}
 
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0); 
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
}
