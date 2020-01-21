#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
#define maxm 100005
using namespace std;
int used[maxn];
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2];
int head[maxn];
int size=0;
int n,m;
void add_edge(int u,int v,int w){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].len=w;
	E[size].next=head[u];
	head[u]=size;
} 

struct node{
	int x;
	int t;
	node(){} 
	node(int xx,int tim){
		x=xx;
		t=tim;
	}
};
node bfs(int s){
	memset(used,0,sizeof(used));
	queue<node>q;
	q.push(node(s,0));
	node now,nex;
	int tx,ty;
	int maxt=0,maxx=s;
	used[s]=1;//注意起点要判重 
	while(!q.empty()){
		now=q.front();
		q.pop();
		int u=now.x;
	    if(now.t>maxt){
	    	maxx=now.x;
	    	maxt=now.t;
		} 
		for(int i=head[u];i!=0;i=E[i].next){
			if(!used[E[i].to]){
				used[E[i].to]=1;
				q.push(node(E[i].to,now.t+E[i].len));
			}
		} 
	}
	return node(maxx,maxt);
}
int main(){
	int u,v,w;
	while(scanf("%d %d %d",&u,&v,&w)!=EOF){
		
		add_edge(u,v,w);
		add_edge(v,u,w);
	} 
	node tmp1=bfs(1);
	node tmp2=bfs(tmp1.x);
	printf("%d\n",tmp2.t);
}
