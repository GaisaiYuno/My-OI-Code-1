#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxc 105
#define maxn 100005
#define maxm 2000005
#define INF 0x3f3f3f3f
using namespace std;
struct edge{
	int from;
	int to;
	int next;
	int flow;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d : %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
}

int deep[maxn];
bool bfs(int s,int t){
	for(int i=s;i<=t;i++) deep[i]=0;
	queue<int>q;	
	q.push(s);
	deep[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
			} 
		}
	}
	if(deep[t]) return 1;
	else return 0;
}

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			rest-=k;
			E[i].flow-=k;
			E[i^1].flow+=k;
			if(rest==0) break;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int now=0,ans=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) ans+=now;
	}
	return ans;
}
int n,m;
int a[maxc][maxc];
const int dirx[4]={-1,1,0,0},diry[4]={0,0,-1,1};
inline int get_id(int x,int y){
	return m*(x-1)+y;
} 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int s=0,t=n*m*2+1;
	int all=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<0){
				int k=-a[i][j]-1;
				int maxv=0;
				for(int x=i,y=j;x>0&&x<=n&&y>0&&y<=m;x+=dirx[k],y+=diry[k]){
					if(a[x][y]>0) maxv=max(maxv,a[x][y]);
				}
				all+=maxv;
				if(k<2) add_edge(s,get_id(i,j),INF);
				else add_edge(get_id(i,j)+n*m,t,INF);
				for(int x=i,y=j;x>0&&x<=n&&y>0&&y<=m;x+=dirx[k],y+=diry[k]){
					if(x+dirx[k]>0&&x+dirx[k]<=n&&y+diry[k]>0&&y+diry[k]<=m){
						if(k<2) add_edge(get_id(x,y),get_id(x+dirx[k],y+diry[k]),maxv-max(0,a[x][y]));
						else add_edge(get_id(x+dirx[k],y+diry[k])+n*m,get_id(x,y)+n*m,maxv-max(0,a[x][y]));
					}
				}
			}else{
				add_edge(get_id(i,j),get_id(i,j)+n*m,INF); 
			}
		}
	}
	printf("%d\n",all-dinic(s,t));
}

