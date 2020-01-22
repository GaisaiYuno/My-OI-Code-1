#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 200000
#define maxc 10
using namespace std;
typedef long long ll;
int n;
char s[maxn+5];
vector<int>pos[10];

struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].len=w;
	E[sz].next=head[v];
	head[v]=sz;
}


struct node{
	int id;
	int dis;
	node(){
		
	}
	node(int _id,int _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (node p,node q){
		return p.dis>q.dis;
	}
};
int dist[maxn+5];
bool vis[maxn+5];
int maxd;
ll cnt;
void dijkstra(int s){
	priority_queue<node>q;
	for(int i=1;i<=n+8;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
	int nowd=0;
	for(int i=1;i<=n;i++) nowd=max(nowd,dist[i]);
	if(nowd>maxd){
		maxd=nowd;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(dist[i]==nowd){
				cnt++;
				printf("(%d,%d) %d\n",s,i,nowd);
			}
		}
	}else if(nowd==maxd){
		for(int i=1;i<=n;i++){
			if(dist[i]==nowd){
				cnt++;
				printf("(%d,%d) %d\n",s,i,nowd);
			}
		}
	}
}
int main(){
//#ifdef LOCAL
//	freopen("input.txt","r",stdin);
//#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		pos[s[i]-'a'+1].push_back(i);
	}
	for(int i=1;i<=8;i++){
		for(int j=0;j<(int)pos[i].size();j++){
			add_edge(pos[i][j],i+n,1);
		}
	}
	for(int i=1;i<n;i++){
		if(s[i]!=s[i+1]) add_edge(i,i+1,2);
	}
//	printf("ok\n");
//	printf("%d\n",sz);
	for(int i=1;i<=n;i++){
		dijkstra(i);
//		printf("dijkstra %d\n",i);
	}
	printf("%d %lld\n",maxd/2,cnt/2);
}
