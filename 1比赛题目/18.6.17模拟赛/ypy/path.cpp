#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#define maxn 10005
#define maxm 50005
using namespace std;
int n,p,q;
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
inline void qprint(int x){
	int num[15];
	int ptr=1;
	while(x>0){
		num[ptr++]=x%10;
		x/=10;
	}
	for(int i=ptr-1;i>=1;i--) putchar(num[i]+'0');
	putchar('\n');
}
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int x,int y,int z){
		from=x;
		to=y;
		len=z;
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
int fa[maxn];
void ini(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void kruskal(){
	sort(G+1,G+1+p);
	for(int i=1;i<=p;i++){
		int fx=find(G[i].from);
		int fy=find(G[i].to);
		if(fx!=fy){
			add_edge(G[i].from,G[i].to,G[i].len);
			add_edge(G[i].to,G[i].from,G[i].len);
			fa[fx]=fy;
		}
	}
}
int used[maxn];
int ans=-1;
void dfs(int u,int to,int maxv){
	if(u==to){
		ans=maxv;
		return;
	}
	used[u]=1;
	for(int i=head[u];i;i=MST[i].next){
		if(used[MST[i].to]) continue;
		dfs(MST[i].to,to,max(MST[i].len,maxv));
	}
}
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	int s,t,r,f,g;
//	scanf("%d %d",&n,&p);
	n=qread();
	p=qread();
	for(int i=1;i<=p;i++){
//		scanf("%d %d %d",&s,&t,&r);
		s=qread();
		t=qread();
		r=qread();
		G[i]=edge(s,t,r);
	}
	ini();
	kruskal();
//	scanf("%d",&q);
    q=qread();
	for(int i=1;i<=q;i++){
//		scanf("%d %d",&f,&g);
		f=qread();
		g=qread();
		memset(used,0,sizeof(used));
		ans=-1;
		dfs(f,g,0);
//		printf("%d\n",ans);
		qprint(ans);
	}
}
