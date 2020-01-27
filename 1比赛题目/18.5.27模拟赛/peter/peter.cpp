#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
int used[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2];
int size=0;
int head[maxn];
int ecnt[maxn];
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
	ecnt[u]++;
}

struct node{
	int x;
	int c;
	node(){
		
	}
	node(int xx,int cnt){
		x=xx;
		c=cnt;
	}
};
int bfs(int s){
	int ans=0;
	memset(used,0,sizeof(used));
	queue<node>q;
	q.push(node(s,a[s]));
	used[s]=1;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int u=now.x;
		used[u]=1;
		int cnt=0;
		for(int i=head[u];i!=0;i=E[i].next){
			if(!used[E[i].to]){
				cnt++;
				if(a[E[i].to]==0) q.push(node(E[i].to,0));
				else if(now.c+a[E[i].to]<=m) q.push(node(E[i].to,now.c+1));
			}
		}
		if(cnt==0) ans++;
	}
	return ans;
}
int main(){
//	freopen("peter.in","r",stdin);
//	freopen("peter.out","w",stdout);
//	freopen("peter13.in","r",stdin);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	printf("%d\n",bfs(1));
}
/*
7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/
