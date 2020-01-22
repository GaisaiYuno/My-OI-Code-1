#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 100005
using namespace std;
struct edge{
	int to,cost;
};
vector<edge>G[MAXN];
void add_edge(int u,int v,int w){
	edge temp;
	temp.to=v;
	temp.cost=w;
	G[u].push_back(temp);
}
int vis[MAXN],dis[MAXN];
inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void spfa(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	vis[s]=true;
	queue<int>Q;
	Q.push(s);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		vis[v]=false;
		for (int i=0;i<G[v].size();++i){
			int u=G[v][i].to;
			int len=G[v][i].cost;
			if (dis[u]>dis[v]+len){
				dis[u]=dis[v]+len;
				if (!vis[u]){
					vis[u]=true;
					Q.push(u);
				}
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	spfa(1);
	printf("%d\n",dis[n]);
}
//in on under in front of behind next to between
//One,two,three,four.
//Where is the fox 
