//ת���ɱ������·
//��������a->b->c��ת���ɱ�(a,b)���ܵ���(a,c)������
//Ȼ�����·�ñ���,dist[i]��ʾ����i�յ����
//���·�жϸ�һ�¾Ϳ����� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#define maxn 3005
#define maxm 40005
#define maxk 100005
#define INF 0x3f3f3f3f
using namespace std;
int n,m,k;
struct ed {
	int u;
	int v;
	ed() {

	}
	ed(int a,int b) {
		u=a;
		v=b;
	}
	friend bool operator <(ed x,ed y) {
		if(x.u==y.u) return x.v<y.v;
		else return x.u<y.u;
	}
};
map<ed,int>hash_edge;//�ߵı�ź����˵�hash 
map<int,int>not_go[maxm];//not_go[i][j]=1��ʾ���ܴ�i��j 
struct edge {
	int from;
	int to;
	int next;
	int len;
	edge() {

	}
	edge(int u,int v,int w,int he) {
		from=u;
		to=v;
		next=he;
		len=w;
	}
};
int sz=1;
edge E[maxm];
int head[maxn];
void add_edge(int u,int v,int w) {
	sz++;
	E[sz]=edge(u,v,w,head[u]);
	hash_edge[ed(u,v)]=sz;
	head[u]=sz;
}
int p[maxm];
int dist[maxm];
int used[maxm];
struct node {
	int x;
	int d;
	node() {

	}
	node(int u,int dis) {
		x=u;
		d=dis;
	}
	friend bool operator <(node a,node b) {
		return a.d>b.d;
	}
};
priority_queue<node>heap;
void dijkstra(int s) {
	memset(dist,0x3f,sizeof(dist));
	for(int i=head[s]; i; i=E[i].next) {
		dist[i]=1;
		p[i]=-1;
		heap.push(node(i,1));
	}
	while(!heap.empty()) {
		node now=heap.top();
		heap.pop();
		int x=now.x;
		used[x]=1;
		for(int i=head[E[x].to]; i; i=E[i].next) {
			if(dist[i]>dist[x]+E[i].len&&!not_go[x].count(i)&&!used[i]) {
				//ע���ر�����,������Դ�a->b�ٴ�b->a,������3 
				//���Բ���д!used[i]&&!used[i^1] 
				dist[i]=dist[x]+E[i].len;
				p[i]=x;
				heap.push(node(i,dist[i]));
			}
		}
	}
}

void print(int x) {
	if(p[x]==-1) return;
	else print(p[x]);
	printf("%d ",E[x].from);
}
int main() {
	int u,v,a,b,c;
	int w;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&u,&v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	for(int i=1; i<=k; i++) {
		scanf("%d %d %d",&a,&b,&c);
		if(hash_edge.count(ed(a,b))) {
			int id1=hash_edge[ed(a,b)];
			int id2=hash_edge[ed(b,c)]; 
			not_go[id1][id2]=1;
		}
		swap(a,c);//����a->b->c,Ҳ����c->b->a 
		if(hash_edge.count(ed(a,b))) {
			int id1=hash_edge[ed(a,b)];
			int id2=hash_edge[ed(b,c)]; 
			not_go[id1][id2]=1;
		}
	}
	dijkstra(1);
	int ans=INF;
	int final=0;
	for(int i=head[n]; i; i=E[i].next) {
		if(dist[i^1]<ans) {
			ans=dist[i^1];
			final=i^1;
		}
	}
	if(ans<INF) {
		printf("%d\n",ans);
		printf("%d ",1);
		print(final);
		printf("%d",n);
	}else{
		printf("-1");
	} 
}

