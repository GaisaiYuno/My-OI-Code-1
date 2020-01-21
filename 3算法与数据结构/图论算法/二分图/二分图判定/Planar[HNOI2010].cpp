//http://111.230.183.91/contest/9/problem/1
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 2005 
#define maxm 10005
using namespace std;
int t,n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int head[maxn];
int sz;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
int id[maxn];

bool flag;
int v[maxn];
vector<int>G[maxn];
void dfs(int x,int color){
	v[x]=color;
	for(int i=0;i<G[x].size();i++){
		int y=G[x][i];
		if(!v[y]){
			dfs(y,3-color);
		}else if(v[y]==color){
			flag=false;
		}
	}
}

void ini(){
	flag=true;
	memset(v,0,sizeof(v));
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	sz=0;
	for(int i=1;i<=n;i++){
		G[i].clear();
	}
}

int is_bi_graph(){
	for(int i=1;i<=n;i++){
		if(!v[i]) dfs(i,1);
		if(!flag) return 0;
	}
	if(flag) return 1;
	else return 0;
}

int is_inter(int l1,int r1,int l2,int r2){
	if(l1>r1) swap(l1,r1);
	if(l2>r2) swap(l2,r2);
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}  
	if(l1<l2&&r1>r2) return 0;
	if(l2<r1&&l2>l1) return 1;
	else return 0; 
}

int main(){
	int p,q;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&p,&q);
			add_edge(p,q);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&p);
			id[p]=i;
		}
		if(m>3*n-6&&n>=3){
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(is_inter(id[E[i].from],id[E[i].to],id[E[j].from],id[E[j].to])){
//					printf("[%d,%d] [%d,%d] %d %d\n",id[E[i].from],id[E[i].to],id[E[j].from],id[E[j].to],i,j);
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		if(is_bi_graph()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
/*
1
6 8
1 2
2 3
3 4
4 5
5 6
1 5
2 4
3 6
1 2 3 4 5 6
*/ 
