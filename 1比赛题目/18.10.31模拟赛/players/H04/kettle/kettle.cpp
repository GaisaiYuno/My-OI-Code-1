#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector> 
#define maxn 5005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
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
	if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}	
}

struct edge{
	int from;
	int to;
	int len;
	edge(){
		
	}
	edge(int u,int v,int w){
		from=u;
		to=v;
		len=w;
	}
	friend bool operator <(edge x,edge y){
		return x.len<y.len;
	}
}; 
vector<edge>G;
vector<edge>T[maxn];

int h,w,p,q;
char a[maxn][maxn];
struct point{
	int x;
	int y;
}b[maxn];
int id[maxn][maxn];
int used[maxn][maxn];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
	int x;
	int y;
	int t;
	node(){
		
	} 
	node(int xx,int yy,int tim){
		x=xx;
		y=yy;
		t=tim;
	}
};
queue<node>qu;
void bfs(int sx,int sy){
	memset(used,0,sizeof(used));
	node now,nex;
	qu.push(node(sx,sy,0));
	used[sx][sy]=1;
	while(!qu.empty()){
		now=qu.front();
		qu.pop();
		if(id[now.x][now.y]){
//			printf("debug %d %d %d\n",id[sx][sy],id[now.x][now.y],now.t);
//			G[id[sx][sy]].push_back(edge(id[now.x][now.y],now.t));
			G.push_back(edge(id[sx][sy],id[now.x][now.y],now.t-1));
		}
		for(int i=0;i<4;i++){
			nex.x=now.x+dx[i];
			nex.y=now.y+dy[i];
			if(nex.x>=1&&nex.x<=h&&nex.y>=1&&nex.y<=w&&a[nex.x][nex.y]!='#'&&!used[nex.x][nex.y]){
				used[nex.x][nex.y]=1;
				nex.t=now.t+1;
				qu.push(nex);
			}
		}
	}
}

int fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void kruskal(){
	int u,v,fu,fv;
	for(int i=1;i<=p;i++){
		fa[i]=i;
	}
	sort(G.begin(),G.end());
	int m=G.size();
	for(int i=0;i<m;i++){
		u=G[i].from;
		v=G[i].to;
		fu=find(u);
		fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			T[u].push_back(edge(u,v,G[i].len));
			T[v].push_back(edge(v,u,G[i].len));
//			printf("debug %d %d %d\n",u,v,G[i].len);
		}
	}
}
//int vis[maxn];
//long long dist[maxn];
//void prim(int n){
//	memset(dist,0x3f,sizeof(dist));
//	dist[1]=0;
//	vis[1]=1;
//	long long minv;
//	int x,t; 
//	for(int i=1;i<=n;i++){
//		minv=INF;
//		for(int j=1;j<=n;j++){
//			if(dist[j]<minv){
//				minv=dist[j];
//				x=j;
//			}
//		}
//		t=G[x].size();
//		for(int j=0;j<t;j++){
//			int y=G[x][j].to;
//			if(!vis[y]){
//				vis[y]=1;
//				dist[y]=G[x][j].len;
//				printf("debug:%d %d %d\n",x,y,G[x][j].len);
//				T[x].push_back(edge(y,G[x][j].len));
//				T[y].push_back(edge(y,G[x][j].len));
//			}
//		}
//	}
//}

int deep[maxn];
int anc[maxn][25];
int maxl[maxn][25];
void dfs(int x,int fa,int len){
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=20;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	maxl[x][0]=len;
	for(int i=1;i<=20;i++){
		maxl[x][i]=max(maxl[x][i-1],maxl[anc[x][i-1]][i-1]);
	}
	int t=T[x].size();
	for(int i=0;i<t;i++){
		int y=T[x][i].to;
		if(y!=fa){
			dfs(y,x,T[x][i].len);
		}
	} 
} 

int get_max(int x,int y){
	int ans=0;
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]){
			ans=max(ans,maxl[x][i]);
			x=anc[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=20;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			ans=max(ans,maxl[x][i]);
			ans=max(ans,maxl[y][i]);
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	ans=max(ans,maxl[x][0]);
	ans=max(ans,maxl[y][0]);
	return ans;
}

int main(){
	freopen("kettle.in","r",stdin);
	freopen("kettle.out","w",stdout); 
	int s,t;
	h=qread();
	w=qread();
	p=qread();
	q=qread();
	for(int i=1;i<=h;i++){
		scanf("%s",a[i]+1); 
	}
	for(int i=1;i<=p;i++){
		b[i].x=qread();
		b[i].y=qread();
		id[b[i].x][b[i].y]=i;
	}
	for(int i=1;i<=p;i++){
		bfs(b[i].x,b[i].y);
	}
	kruskal();
	dfs(1,0,0);
	for(int i=1;i<=q;i++){
		s=qread();
		t=qread();
		qprint(get_max(s,t));
		putchar('\n');
	}
}
