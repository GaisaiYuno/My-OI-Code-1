## [BZOJ4477] [JSOI2015]字符串树(可持久化Trie+LCA)

### 题面

字符串树本质上还是一棵树，即N个节点N-1条边的连通无向无环图，节点
从1到N编号。与普通的树不同的是，树上的每条边都对应了一个字符串。萌萌
和JYY在树下玩的时候，萌萌决定考一考JYY。每次萌萌都写出一个字符串S和
两个节点U,V，需要JYY立即回答U和V之间的最短路径（即,之间边数最少的
路径。由于给定的是一棵树，这样的路径是唯一的）上有多少个字符串以为前
缀。

### 分析

先不考虑树上的情况。我们在Trie上维护一个sz[p]表示p子树内字符串结尾的个数，查询以S为前缀的字符串个数，就先在Trie上找到S结尾所在节点x,sz[x]即为答案。

类比主席树求树上路径第$k$大,我们对于每个树结点开一棵可持久化Trie记录到根路径上的字符串出现情况。初始化时从父亲继承,查询时用x,y的答案减去两倍lca(x,y)的答案。

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
#define maxlogn 20
#define maxl 10
#define maxs 26
using namespace std;
int n,m;
char str[maxn+5][maxl+5];
char tmp[maxl+5];
struct persist_trie{
	int root[maxn+5];
	int sz[maxn*maxs+5];
	int ch[maxn*maxs+5][maxs];
	int ptr;
	inline int get_id(char c){
		return c-'a';
	}
	void insert(int pos,int pre,char* s){
		int now=root[pos]=++ptr,last=root[pre];
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			for(int j=0;j<maxs;j++) ch[now][j]=ch[last][j];
			int c=get_id(s[i]);
			ch[now][c]=++ptr;
			now=ch[now][c];
			last=ch[last][c];
			sz[now]=sz[last]+1;//sz[p]p子树内字符串结尾的个数
            //显然s结尾往上的所有Trie节点的sz都要比原来+1
		}
	}
	int query(int pos,char *s){
		int now=root[pos];
		int len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=get_id(s[i]);
			now=ch[now][c];
		}
		return sz[now];
	}
}T;

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
int deep[maxn+5],anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
	T.insert(x,fa,str[x]);
	anc[x][0]=fa;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	deep[x]=deep[fa]+1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=maxlogn;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=maxlogn;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}




int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		add_edge(u,v);
		scanf("%s",str[v]+1);
	}
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %s",&u,&v,tmp+1);
		int lc=lca(u,v);
		int ans=T.query(u,tmp)+T.query(v,tmp)-2*T.query(lc,tmp);
		printf("%d\n",ans);
	}
} 
```



