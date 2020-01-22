#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define maxn 200005
#define maxm 200005
#define maxlog 32
using namespace std;
int n,m,q;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
struct edge{
	int from;
	int to;
	int len;
	int next;
	int index;
	edge(){
		
	}
	edge(int x,int y,int z,int i){
		from=x;
		to=y;
		len=z;
		index=i;
	}
	friend bool operator <(edge x,edge y){
		return x.len<y.len;
	}
};
edge G[maxm*2],MST[maxm*2];
int head[maxn];
int size=0;
void add_edge(int u,int v,int w){
	size++;
	MST[size].from=u;
	MST[size].to=v;
	MST[size].len=w;
	MST[size].next=head[u];
	head[u]=size;
}
int fset[maxn];
void set_init(){
	for(int i=1;i<=n;i++) fset[i]=i;
}
int find(int x){
	if(fset[x]==x) return x;
	else{
		fset[x]=find(fset[x]);
		return fset[x];
	}
}
long long kruskal(){
	long long ans=0;
	sort(G+1,G+1+m);
	for(int i=1;i<=m;i++){
		int fx=find(G[i].from);
		int fy=find(G[i].to);
		if(fx!=fy){
			add_edge(G[i].from,G[i].to,G[i].len);
			add_edge(G[i].to,G[i].from,G[i].len);
			fset[fx]=fy;
			ans+=G[i].len; 
		}
	}
	return ans;
}

int deep[maxn],fa[maxn][maxlog];
long long mlen[maxn][maxlog];
int log2n;
void lca_init(){
	queue<int>q;
	q.push(1);
	deep[1]=1; 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=MST[i].next){
			int y=MST[i].to;
			if(deep[y]) continue;
			deep[y]=deep[x]+1;
			fa[y][0]=x;
			mlen[y][0]=MST[i].len;
			for(int j=1;j<=log2n;j++){
				fa[y][j]=fa[fa[y][j-1]][j-1];
				mlen[y][j]=max(mlen[y][j-1],mlen[fa[y][j-1]][j-1]);
			}
			q.push(y);
		}
	}
}
long long lca_query(int x,int y){
	if(deep[x]>deep[y]) swap(x,y);
	long long maxl=0;
	for(int i=log2n;i>=0;i--){
		if(deep[fa[y][i]]>=deep[x]){
			maxl=max(maxl,mlen[y][i]);
			y=fa[y][i];
		}
	}
//	if(maxl==0) maxl=mlen[y][0];
	if(x==y) return maxl;
	for(int i=log2n;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			maxl=max(maxl,max(mlen[x][i],mlen[y][i]));
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	maxl=max(maxl,max(mlen[x][0],mlen[y][0]));
	return maxl;
}
long long ans[maxm];
int main(){
	int s,t,r;
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		s=qread();
		t=qread();
		r=qread();
		G[i]=edge(s,t,r,i);
	}
	set_init();
	long long tlen=kruskal();
	log2n=log2(n)+1;
	lca_init();
	q=qread();
	for(int i=1;i<=q;i++){
		s=qread();
		t=qread();
		if(find(s)!=find(t)) printf("-1\n");
		else printf("%lld\n",lca_query(s,t));
	} 
}
