//典型的最小值最大问题 
//建图，跑最小生成树，在树上求最大的边
//主要瓶颈在于建图
//发现如果水壶是定值，那地图上肯定存在许多以建筑物为中心的联通块。
//并且随着水壶的增大，联通块大小也增大，有一些联通块会融合。
//因此考虑把所有建筑物丢到队列搞BFS。如果两个联通块碰到了，就给这两个建筑物连上一条边 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector> 
#define maxh 2005
#define maxn 200005
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
char a[maxh][maxh];
struct point{
	int x;
	int y;
}b[maxn];
int id[maxh][maxh];
int dis[maxh][maxh];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
	int x;
	int y;
	int i;
	int t;
	node(){
		
	} 
	node(int xx,int yy,int id,int tim){
		x=xx;
		y=yy;
		t=tim;
		i=id;
	}
};
queue<node>qu;
void bfs(){
	for(int i=1;i<=p;i++){
		qu.push(node(b[i].x,b[i].y,i,0));
	}
	node now,nex;
	while(!qu.empty()){
		now=qu.front();
		qu.pop();
		for(int i=0;i<4;i++){
			nex.x=now.x+dx[i];
			nex.y=now.y+dy[i];
			if(nex.x<1||nex.y<1||nex.x>h||nex.y>w||a[nex.x][nex.y]=='#') continue;
			if(id[nex.x][nex.y]!=0&&id[nex.x][nex.y]!=id[now.x][now.y]){
				G.push_back(edge(id[now.x][now.y],id[nex.x][nex.y],now.t+dis[nex.x][nex.y]));
			}else if(!id[nex.x][nex.y]){
				id[nex.x][nex.y]=now.i;
				dis[nex.x][nex.y]=now.t+1;
				nex.i=now.i;
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
	bfs();
	kruskal();
	for(int i=1;i<=p;i++) if(!anc[i][0]) dfs(i,0,0);
	for(int i=1;i<=q;i++){
		s=qread();
		t=qread();
		if(find(s)!=find(t)){
			putchar('-');
			putchar('1');
		}
		else qprint(get_max(s,t));
		putchar('\n');
	}
}
