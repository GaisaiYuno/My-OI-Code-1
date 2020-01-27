#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
char s[maxn+5];

vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
//	printf("(%d,%d)\n",u,v);
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
	for(int i=1;i<=n;i++){
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
		for(int i=0;i<(int)E[x].size();i++){
			int y=E[x][i];
			if(dist[y]>dist[x]+1){
				dist[y]=dist[x]+1;
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
	for(int i=1;i<=n;i++) add_edge(i,i+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i]==s[j]) add_edge(i,j);
		}
	}
	printf("ok\n");
	for(int i=1;i<=n;i++){
		dijkstra(i);
//		printf("dijkstra %d\n",i);
	}
	printf("%d %lld\n",maxd,cnt/2);
}
