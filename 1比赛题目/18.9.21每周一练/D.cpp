#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 405
#define maxm 160005
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int rail[maxn][maxn];
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int u,int v,int w,int he){
		from=u;
		to=v;
		len=w;
		next=he;
	}
}E[maxm];
int sz=0;
int head[maxn];
void add_edge(int u,int v,int w){
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	head[u]=sz;
}

struct node{
	int u;
	int d;
	node(){
		
	}
	node(int x,int dis){
		u=x;
		d=dis;
	}
	friend bool operator <(node a,node b){
		return a.d>b.d;
	} 
}; 
int dist[maxn]; 
int used[maxn];
priority_queue<node>heap;
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	node now,nex;
	heap.push(node(s,0));
	while(!heap.empty()){
		now=heap.top();
		heap.pop();
		int x=now.u;
		used[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!used[y]){
				if(dist[y]>dist[x]+E[i].len){
					dist[y]=dist[x]+E[i].len;
					heap.push(node(y,dist[y]));
				}
			}
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		rail[u][v]=1;
		rail[v][u]=1;
	}
	//ͼ����ȫͼ,����һ����һ�ֽ�ͨ���߿����߱�(1,n),������һ�ֽ�ͨ�����������ߴ�1��n���� 
	if(rail[1][n]==1){//��ֱ���߱�(1,n),��ʿ��1��n�����· 
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(rail[i][j]==0){
					add_edge(i,j,1);
					add_edge(j,i,1);
				}
			}
		}
	}else{//��ʿֱ���߱�(1,n),�𳵴�1��n�����·
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(rail[i][j]==1){
					add_edge(i,j,1);
					add_edge(j,i,1);
				}
			}
		}
	}
	
	dijkstra(1);
	if(dist[n]>=INF) printf("-1\n");
	else printf("%d\n",max(dist[n],1)); 
}
