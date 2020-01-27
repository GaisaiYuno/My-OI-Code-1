#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 100005
#define maxm 200005
#define maxc 1000005
using namespace std;
int n,m,s;
int vis[maxn][2];
int pre[maxc+5];
struct node{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int size=0;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
    E[size].next=head[u];
    head[u]=size;
} 
int bfs(int s){
	queue<int>q;
	q.push(s);
	int cnt=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=E[i].next){
			cnt++;
			q.push(E[i].to);
		}
		if(cnt>=maxc) return 1;
	}
	return 0;
}
int flag;
void dfs(int u,int d,int &flag,int &ans){
	if(flag==1) return;
	pre[d]=u;
	vis[u][d%2]=1;
	int ecnt=0;
	for(int i=head[u];i;i=E[i].next){
		int v=E[i].to;
		ecnt++;
		if(vis[v][(d+1)%2]) continue;
		return dfs(v,d+1,flag,ans);
	}
	if(d%2==1&&ecnt==0){
		flag=1;//有解 
		ans=d;
		return ;
	}
	if(d%2==0&&flag==0){
		flag=-1;//无解 
		ans=-1;
		return;
	}
}
int main(){
	int c,u,v; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		for(int j=1;j<=c;j++){
			scanf("%d",&v);
			add_edge(i,v);
		}
	}
	scanf("%d",&s);
	bool is_ring=bfs(s); 
	if(is_ring) flag=2;//有环 
	else flag=0;
	int ans=0; 
	dfs(s,0,flag,ans);
	if(flag==1){
		printf("Win\n");
		for(int i=0;i<=ans;i++) printf("%d ",pre[i]);
	}else if(flag==-1){
		printf("Lose\n");
	}else if(flag==2){
		printf("Draw\n");
	}
}
