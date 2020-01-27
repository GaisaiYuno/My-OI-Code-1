#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
#define maxn 100000
#define maxlogn 20
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

int log2n;
int tim=0;
int dfn[maxn+5];
int id[maxn+5];
int deep[maxn+5];
long long dis[maxn+5];
int anc[maxn+5][maxlogn+1];
void dfs(int x,int fa){
	deep[x]=deep[fa]+1;
	dfn[x]=++tim;
	anc[x][0]=fa;
	id[dfn[x]]=x;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dis[y]=dis[x]+E[i].len;
			dfs(y,x);
		}
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			x=anc[x][i];
		}
	}
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}
inline long long dist(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}



set<int>seq;
long long sum=0;
void add(int x){
	if(seq.size()<1){
		seq.insert(dfn[x]);
		return;
	}
	set<int>::iterator pos=seq.lower_bound(dfn[x]);
	set<int>::iterator nex=seq.upper_bound(dfn[x]);
	set<int>::iterator front=seq.begin(),back=(--seq.end());
	if(pos==seq.begin()){
		sum-=dist(id[*back],id[*front]);
		sum+=dist(id[*back],x);
		sum+=dist(x,id[*front]);
	}else if(pos==seq.end()){
		sum-=dist(id[*back],id[*front]);
		sum+=dist(id[*back],x);
		sum+=dist(x,id[*front]);
	}else if(nex==seq.end()){
		nex=seq.begin();
		set<int>::iterator pre=--pos;
		sum-=dist(id[*pre],id[*nex]);
		sum+=dist(id[*pre],x);
		sum+=dist(x,id[*nex]);
	}else{
		set<int>::iterator pre=--pos;
		sum-=dist(id[*pre],id[*nex]);
		sum+=dist(id[*pre],x);
		sum+=dist(x,id[*nex]);
	}
	seq.insert(dfn[x]);
} 
//void debug(){
//	printf("debug: ");
//	for(int x : seq){
//		printf("%d ",x);
//	}
//	printf("\n");
//}
void del(int x){
//	debug();
	set<int>::iterator pos=seq.lower_bound(dfn[x]);
	set<int>::iterator nex=seq.upper_bound(dfn[x]);
	set<int>::iterator front=seq.begin(),back=(--seq.end());
	if(pos==seq.begin()){
		sum+=dist(id[*back],id[*nex]);
		sum-=dist(id[*back],x);
		sum-=dist(x,id[*nex]);
	}else if(pos==seq.end()){
		sum+=dist(id[*back],id[*front]);
		sum-=dist(id[*back],x);
		sum-=dist(x,id[*front]);
	}else if(nex==seq.end()){
		nex=seq.begin();
		set<int>::iterator pre=--pos;
		sum+=dist(id[*pre],id[*nex]);
		sum-=dist(id[*pre],x);
		sum-=dist(x,id[*nex]);
	}else{
		set<int>::iterator pre=--pos;
		sum+=dist(id[*pre],id[*nex]);
		sum-=dist(id[*pre],x);
		sum-=dist(x,id[*nex]);
	}
	seq.erase(dfn[x]);
//	debug(); 

} 
int main(){
	char cmd[2];
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w); 
	} 
	log2n=log2(n)+1; 
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='+'){
			scanf("%d",&u);
			add(u); 
		}else if(cmd[0]=='-'){
			scanf("%d",&u);
			del(u);
		}else{
			printf("%lld\n",sum/2);
		}
	}
}
