//https://vjudge.net/contest/311234#problem/B
/*
答案上界为该无向图中的偶点数量，考虑构造方案达到这个上界
建一个虚点S向所有奇点连边，这样奇点都变成了偶点，而奇点的个数一定是偶数，故S也是个偶点
于是新图存在欧拉回路，根据这个对边进行定向，则原图中所有偶点入度等于出度，达到上界

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200
#define maxm 100000
using namespace std;
int t,n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
 
int st=0;
int deg[maxn+5];
int visv[maxn+5],vise[maxm*2+5];
int cur[maxn+5];
void dfs(int x){
	visv[x]=1;
	for(int& i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vise[i]&&!vise[i^1]){
			vise[i]=vise[i^1]=1;
			if(x!=0&&y!=0) printf("%d %d\n",x,y);
			dfs(y);
		}
	}
}
 
void ini(){
	sz=1;
	memset(head,0,sizeof(head));
	memset(deg,0,sizeof(deg));
	memset(visv,0,sizeof(visv));
	memset(vise,0,sizeof(vise));
}
int main(){
	int u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			deg[u]++;
			deg[v]++;
		}
		st=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(deg[i]%2==1){
				add_edge(st,i);
				add_edge(i,st);
			}else ans++;
		}
		
//		for(int i=1;i<=top;i++) printf("%d ",s[i]);
//		printf("\n");
		printf("%d\n",ans);
		for(int i=0;i<=n;i++){
			dfs(i);
		}
//		for(int i=1;i<top;i++){
//			if(s[i]!=0&&s[i+1]!=0)printf("%d %d\n",s[i],s[i+1]);
//		}
	}
} 
