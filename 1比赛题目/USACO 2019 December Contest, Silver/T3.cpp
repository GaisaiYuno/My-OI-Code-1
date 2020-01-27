#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxlogn 25
using namespace std;
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

char str[maxn+5];
int deep[maxn+5],cnt0[maxn+5],cnt1[maxn+5];
int anc[maxn+5][maxlogn+5];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	cnt0[x]=cnt0[fa]+(str[x]=='H');
	cnt1[x]=cnt1[fa]+(str[x]=='G');
	anc[x][0]=fa;
	for(int i=1;i<=maxlogn;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
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
int query_0(int x,int y){
	int lc=lca(x,y);
	return cnt0[x]+cnt0[y]-cnt0[lc]-cnt0[anc[lc][0]];
}
int query_1(int x,int y){
	int lc=lca(x,y);
	return cnt1[x]+cnt1[y]-cnt1[lc]-cnt1[anc[lc][0]];
}

int n,m;
char ans[maxn+5];
int main(){
#ifndef LOCAL
	freopen("milkvisits.in","r",stdin);
	freopen("milkvisits.out","w",stdout);
#endif
	int u,v;
	char tp[2];
	scanf("%d %d",&n,&m);
	scanf("%s",str+1);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d %d %s",&u,&v,tp);
		if(tp[0]=='H'){
			if(query_0(u,v)>0) ans[i]='1';
			else ans[i]='0';
		}else{
			if(query_1(u,v)>0) ans[i]='1';
			else ans[i]='0';
		}
	}
	printf("%s",ans+1);
} 
