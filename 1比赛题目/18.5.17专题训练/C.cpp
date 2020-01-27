#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define maxn 305
#define maxm 305
using namespace std;
struct node{
	int x;
	int t;
	node(){
		
	}
	node(int xx,int tim){
		x=xx;
		t=tim;
	}
};
struct edges{
	int from;
	int to;
	int len;
	int next;
}E[maxm];
int head[maxn];
int size=0;
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=E[size].next;
}
int used[maxn];
node bfs(node s){
	queue<node>q;
	q.push(s);
	memset(used,0,sizeof(used));
	used[s.x]=1;
	int maxt=0;
	int maxx=0;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(used[now.x]) continue;
		if(now.t>maxt){
			maxx=now.x;
			maxt=now.t;
		}
		used[now.x]=1;
		for(int i=head[now.x];i!=0;i=E[i].next){
			if(!used[E[i].to]){
				used[E[i].to]=1;
				q.push(node(E[i].to,now.t+E[i].len));
			}
		}
	}
	return node(maxx,maxt);
}
int n,s;
int main(){
	scanf("%d %d",&n,&s);
	int u,v,w;
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	node a=bfs(node(1,0));
	node b=bfs(a);
}
