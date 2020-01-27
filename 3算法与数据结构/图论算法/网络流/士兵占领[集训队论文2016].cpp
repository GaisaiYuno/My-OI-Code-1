/*
Problem:士兵占领[集训队论文2016]
Source:http://111.230.183.91/problem/162
Description:
每一行建一个点,与源点连边，容量r[i] 
每一列建一个点，与汇点连边,容量c[i]
对于可以放的格子(i,j)，从第i行向第j列连边 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxr 105
#define maxc 105
#define maxn 205
#define maxm 100005
#define INF 0x7fffffff
using namespace std;
int row,col,block;
int board[maxr][maxc];
int r[maxn];
int c[maxn];

struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
int flow[maxm];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

int deep[maxn];
int bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			} 
		}
	}
	return 0;
}

int dfs(int x,int t,int minf){
	if(x==t) return minf;
	int rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0) deep[y]=0;
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

int dinic(int s,int t){
	int maxflow,nowflow;
	maxflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)){
			maxflow+=nowflow;
		}
	}
	return maxflow;
}

int main(){
	int sum=0;
	int x,y;
	scanf("%d %d %d",&row,&col,&block);
	for(int i=1;i<=row;i++){
		scanf("%d",&r[i]);
		sum+=r[i];
	}
	for(int i=1;i<=col;i++){
		scanf("%d",&c[i]);
		sum+=c[i];
	}
	for(int i=1;i<=block;i++){
		scanf("%d %d",&x,&y);
		board[x][y]=1;
	}
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			if(!board[i][j]){
				add_edge(i,j+row,1);
				add_edge(j+row,i,0);
			}
		}
	}
	for(int i=1;i<=row;i++){
		add_edge(0,i,r[i]);
		add_edge(i,0,0);
	}
	for(int i=1;i<=col;i++){
		add_edge(i+row,row+col+1,c[i]);
		add_edge(row+col+1,i+row,0);
	}
	int ans=sum-dinic(0,row+col+1);
	if(ans!=0) printf("%d\n",ans);
	else printf("JIONG!");
}

