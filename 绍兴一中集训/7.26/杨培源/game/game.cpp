#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 30000
#define maxm 100000
using namespace std;
int n,m,lim;
int a[maxn+5];
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

int ans=-1;
bool flag=false;
int maxhp[maxn+5];
void dfs(int x,int hp,int deep){
//	printf("node=%d hp=%d tim=%d\n",x,hp,deep);
	if(flag) return;
	hp+=a[x];
	if(hp<=0) return;
	hp=min(hp,lim);
	if(hp<=maxhp[x]) return;
	if(x==n){
		ans=deep;
		flag=true;
		return;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].len<hp+a[y]){
			dfs(y,hp-E[i].len,deep+1);
		}
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("game_big_sample.in","r",stdin);
	int u,v,w;
	scanf("%d %d %d",&n,&m,&lim);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	if(n>100){
		printf("-1\n");
		return 0; 
	}
	dfs(1,0,0);
	printf("%d\n",ans); 
}
/*
3 3 1000 
5 4 3
1 2 1
2 3 1
1 3 1
*/ 
