#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 200005
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2];
int head[maxn];
int degree[maxn];
int is_del[maxn];
int size=1;
void add_edge(int u,int v){
	size++;
	degree[u]++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

struct long_path{
	int dis;
	int point;
	long_path(){
		
	} 
	long_path(int d,int x){
		dis=d;
		point=x;
	}
}path[maxn];

struct node{
	int u;
	int d;
	node(){
		u=d=0;
	}
	node(int x,int l){
		u=x;
		d=l;
	}
};
int used[maxn];

struct result{
	int u1;
	int u2;
	int delu;
	result(){
		
	}
	result(int x,int y,int del){
		u1=x;
		u2=y;
		delu=del;
	}
}ans[maxn];
int bfs(int sta){
	memset(used,0,sizeof(used));
	queue<node>q;
	q.push(node(sta,0));
	node res;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(used[now.u]) continue;
		used[now.u]=1;
		if(path[now.u].dis<=now.d){
			path[now.u].dis=now.d;
			path[now.u].point=sta;
		}
		if(res.d<=now.d){
			res.d=now.d;
			res.u=now.u;
		}
		for(int i=head[now.u];i;i=E[i].next){
			if(used[E[i].to]) continue;
			q.push(node(E[i].to,now.d+1));
		}
	}
	return res.u;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	int a=bfs(1);
	int b=bfs(a);
	int no_use=bfs(b); 
	int d=path[a].dis;
//	printf("debug:%d %d %d\n",a,b,d);
	queue<int>delet;
	while(!delet.empty()) delet.pop();
	for(int i=1;i<=n;i++){
		if(i!=a&&i!=b&&degree[i]==1){
			delet.push(i); 
//			printf("debug: %d\n",i);
		}
	}
	long long sum=0;
	int now=0;
	int ptr=0;
	while(!delet.empty()){
		now=delet.front();
		delet.pop();
		sum+=path[now].dis;
		ans[++ptr]=result(now,path[now].point,now);
		is_del[now]=1;
		for(int i=head[now];i;i=E[i].next){
			if(is_del[E[i].to]) continue;
			degree[E[i].to]--;
			if(degree[E[i].to]==1) delet.push(E[i].to);
		} 
	}
	sum+=(long long)d*(d+1)/2;
	delet.push(a);
	int cnt=1;
	while(1){
		now=delet.front();
		delet.pop();
		if(now==b) break;
		ans[++ptr]=result(now,b,now);
		cnt++;
		is_del[now]=1;
		for(int i=head[now];i;i=E[i].next){
			if(is_del[E[i].to]) continue;
			delet.push(E[i].to);
		}
	}
	printf("%I64d\n",sum);
	for(int i=1;i<=ptr;i++){
		printf("%d %d %d\n",ans[i].u1,ans[i].u2,ans[i].delu);
	}
} 
