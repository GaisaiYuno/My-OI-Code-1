#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;
int T,n,m;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-
	}
}
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int u,int v,int w,int f){
		from=u;
		to=v;
		len=w;
		next=f;
	}
}E[maxn<<1];
int head[maxn];
int size=0;
void add_edge(int u,int v,int w){
	size++;
	E[size]=edge(u,v,w,head[u]);
	head[u]=size;
}
int deep[maxn],fa[maxn],up[maxn];
struct dsu{
	int f[maxn];
	int sz[maxn];
	void ini(int n){
		for(int i=1;i<=n;i++){
//			sz[i]=1;
			f[i]=i;
		} 
	}
	void debug(int n){
		printf("debug:");
		for(int i=1;i<=n;i++) printf("%d ",f[i]);
		printf("\n");
	}
	int get_fa(int x){
		if(f[x]==x) return f[x];
		else{
			f[x]=get_fa(f[x]);
			return f[x];
		};
	}
	int get_size(int x){
		return sz[get_fa(x)];
	}
	void merge(int x,int y){
		if(deep[x]>deep[y]) swap(x,y);
		int fx=get_fa(x);
		int fy=get_fa(y);
		if(fx==fy) return;
		f[fy]=fx;
//		sz[fy]+=sz[fx];
	}
	dsu(){
		
	} 
	dsu(int n){
		ini(n);
	}
};
dsu f1,f2;

void dfs(int x,int f){
	int y;
	deep[x]=deep[f]+1;
	fa[x]=f;
	for(int i=head[x];i;i=E[i].next){
		y=E[i].to;
		if(y==f) continue;
		dfs(y,x);
		up[y]=E[i].len;
		if(E[i].len==1){
			f1.merge(x,y);
			f2.merge(x,y);
		}else if(E[i].len==2){
			f2.merge(x,y);
		} 
	}
} 

void update(int u,int v){
	if(deep[u]>deep[v]) swap(u,v);
	if(up[v]==3){
		f2.merge(u,v);
	}else if(up[v]==2){
		f1.merge(u,v);
	} 
} 
int query(int s,int t){
	if(f2.get_fa(s)==f2.get_fa(t)) return 1;
	else if(f2.get_fa(fa[f1.get_fa(s)])==f2.get_fa(t)) return 1;
	else if(f1.get_fa(s)==f1.get_fa(fa[f2.get_fa(t)])) return 1;
	else return 0;
}
void init(){
	f1.ini(n);
	f2.ini(n);
	size=0;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head)); 
	memset(deep,0,sizeof(deep));
	memset(fa,0,sizeof(fa));
	memset(up,0,sizeof(up)); 
}
int main(){
	freopen("c.in","r",stdin);
	freopen("myans.txt","w",stdout);
	int u,v,s,t,w;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d %d",&n,&m);
		init();
		for(int i=1;i<n;i++){
			scanf("%d %d %d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		deep[1]=1;
		fa[1]=0;
		up[1]=0;
		dfs(1,0);
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %d",&u,&v,&t,&s);
			update(u,v);
//			f1.debug(n);
//			f2.debug(n);
			printf("%d\n",query(s,t));
		}
	} 
} 
/*
1
4 3
1 2 3
2 3 3
3 4 3
2 3 4 1
3 4 4 1
*/
