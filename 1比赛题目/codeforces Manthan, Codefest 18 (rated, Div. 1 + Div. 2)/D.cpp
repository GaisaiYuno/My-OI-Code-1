#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue>
#include<vector>
#include<algorithm>
#define maxn 200005
using namespace std;
int n;
int seq[maxn];
vector<int>graph[maxn];
void add_edge(int u,int v){
	graph[u].push_back(v);
}
int size[maxn];
vector<int>level[maxn];
int used[maxn];
int cntnode[maxn];
struct node{
	int u;
	int d;
	node(){
		
	}
	node(int x,int deep){
		u=x;
		d=deep;
	}
};
void bfs(int s){
	queue<node>q;
	q.push(node(s,1));
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int x=now.u;
		printf("%d\n",x);
		used[x]=1;
		level[now.d].push_back(x);
		cntnode[now.d]++;
		int sz=graph[x].size();
		for(int i=0;i<sz;i++){
			int y=graph[x][i];
			if(!used[y]){
				size[x]++;
				q.push(node(y,now.d+1));
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&seq[i]);
	}
	for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
	bfs(1);
	queue<int>q;
	q.push(1);
	int ptr=2;
	bool flag=true;
	while(!q.empty()&&flag&&ptr<=n){
		int x=q.front();
		q.pop();
		for(int i=1;i<=size[x];i++){
			int pos=lower_bound(graph[x].begin(),graph[x].end(),seq[ptr])-graph[x].begin();
			if(graph[x][pos]!=seq[ptr]||pos==graph[x].end()-graph[x].begin()){
				flag=false;
				break;
			}else{
				 q.push(seq[ptr]);
				 ptr++;
				 if(ptr>n) break;
			}
		}
	}
	if(flag) printf("Yes\n");
	else printf("No\n");
} 
