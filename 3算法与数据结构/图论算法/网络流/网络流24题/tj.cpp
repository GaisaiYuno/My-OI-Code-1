// by spli
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> Pair;
const int N=100;
const int inf=0x3f3f3f3f;
int car,m,n;
int a[N][N],p[N][N];
struct node {
	int to,nxt,fl,c;
} e[N*N*N];
int head[N*N],cnt;
queue<int>q;
int dis[N*N*2];
bool vis[N*N*2];
int pe[N*N*2],pv[N*N*2];
void add(int f,int t,int fl,int c) {
	e[cnt]=(node) {
		t,head[f],fl,c
	};
	head[f]=cnt++;
}
void add_edge(int f,int t,int fl,int c) {
	add(f,t,fl,c);
	add(t,f,0,-c);
}
bool spfa(int S,int T) {
	for(int i=S; i<=T; ++i) dis[i]=-inf;
	dis[S]=0;
	vis[S]=1;
	q.push(S);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u]; ~i; i=e[i].nxt) {
			int v=e[i].to;
			if(e[i].fl>0&&dis[v]<dis[u]+e[i].c) {
				dis[v]=dis[u]+e[i].c;
				pe[v]=i;
				pv[v]=u;
				if(!vis[v]) {
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return dis[T]>(-inf);
}
Pair mcf(int S,int T) {
	int C=0,F=0;
	int flow=0;
	while(spfa(S,T)) {
		flow=inf;
		for(int i=T; i!=S; i=pv[i])
			flow=min(flow,e[pe[i]].fl);
		C+=flow*dis[T];
		F+=flow;
		for(int i=T; i!=S; i=pv[i])
			e[pe[i]].fl-=flow,e[pe[i]^1].fl+=flow;
	}
	return Pair(F,C);
}
void DFS(int x,int y,int pos,int k,int T) {
	int kx,ky,mov;
	for(int i=head[pos]; ~i; i=e[i].nxt) {
		int v=e[i].to;
		if(v==0) continue;
		if(v==T) continue;
		if(v==pos-n*m) continue;
		if(!e[i^1].fl) continue;
		e[i^1].fl--;
		if(v>n*m) {
			DFS(x,y,v,k,T);
			return;
		}
		if(v==p[x][y]+1) kx=x,ky=y+1,mov=1;
		else kx=x+1,ky=y,mov=0;
		printf("%d %d\n",k,mov);
		DFS(kx,ky,v+n*m,k,T);//²»ÄÜÐ´DFS(V)
		return;
	}
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&car,&m,&n);
	int num=n*m,now=0;
	int S=0,T=num*2+1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) {
			scanf("%d",&a[i][j]);
			p[i][j]=++now;
			if(a[i][j]==1) continue;
			if(a[i][j]==2) add_edge(p[i][j],p[i][j]+num,1,1),add_edge(p[i][j],p[i][j]+num,inf,0);
			if(a[i][j]==0) add_edge(p[i][j],p[i][j]+num,inf,0);
		}
	if(a[1][1]!=1) add_edge(S,1,car,0);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) {
			if(a[i][j]==1) continue;
			if(a[i][j+1]!=1&&p[i][j+1]) add_edge(p[i][j]+num,p[i][j+1],inf,0);
			if(a[i+1][j]!=1&&p[i+1][j]) add_edge(p[i][j]+num,p[i+1][j],inf,0);
		}
	if(a[n][m]!=1) add_edge(p[n][m]+num,T,car,0);
	Pair ans=mcf(S,T);
	int f=ans.first;
	printf("debug:%d\n",ans.second);
	for(int i=1; i<=f; ++i)
		DFS(1,1,1,i,T);
	return 0;
}
