#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<cassert>
#define maxn 200005
#define maxm 200005
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
	int mark;//标记是原来的边还是后来加上去的边
} E[maxm<<1];
int deg[maxn];
int size=1;//设size=1,则反向边可以存在i和i^1的位置，方便判断
int head[maxn];
void add_edge(int u,int v,int w) {
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].mark=w;
	E[size].next=head[u];
	head[u]=size;
}

int num[maxn];//所在的连通块编号
int used[maxn];
vector<int>block[maxn];//连通块中路径
int count(int x,int cnt) { //dfs求连通块
	num[x]=cnt;
	used[x]=1;
	int ans=(deg[x]&1);
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(!used[y]) ans+=count(y,cnt);
	}
	return ans;
}

int vis_edge[maxm<<1];
int top=0;
int path[maxn<<1];
void euler(int x) {
	used[x]++;
//	if(used[x]>deg[x]&&x!=n+1) return;
//	printf("ok\n");
	for(int& i=head[x]; i; i=E[i].next) {//玄学优化，用引用减少重边的访问， 去掉会TLE 
		if(!vis_edge[i]&&!vis_edge[i^1]) {
			int tmp=i; 
			vis_edge[i]=vis_edge[i^1]=1;
			euler(E[i].to);
			path[++top]=tmp;
		}
	}
}
int main() {
//	freopen("miner1.in","r",stdin);
//	freopen("miner.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++;
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	int ans=0;
	int k=0;
	for(int i=1; i<=n; i++) {
		if(!used[i]&&head[i]) ans+=max(count(i,++k)/2,1);
	}
	printf("%d\n",ans-1);
//	printf("%d %d\n",deg[1],deg[2]);
	for(int i=1; i<=n; i++) {
		if(deg[i]&1) {
			block[num[i]].push_back(i);
		}
	}
	int start=n+1;//建一个虚拟节点
	int pre=n+1;//边的起点
	for(int i=1; i<=k; i++) {
		int sz=block[i].size();
		for(int j=0; j<sz; j++) {
			if(pre!=0) {
				add_edge(pre,block[i][j],2);
				add_edge(block[i][j],pre,2);
				pre=0;
			} else pre=block[i][j];
		}
	}
//	printf("ok\n");
	memset(used,0,sizeof(used));
	euler(start);
	if(top) {
		printf("%d\n",E[path[top]].to);
		for(int i=top-1; i>=1; i--) {
			if(E[path[i]].mark==1) printf("0 %d\n",E[path[i]].to);
			else printf("1 %d\n",E[path[i]].to);
		}
	}
	for(int i=1; i<=n; i++) {
		if(block[num[i]].size()==0&&head[i]&&used[i]==0) {
			if(!top)printf("%d\n",i);
			else printf("1 %d\n",i);
			top=0;
			euler(i);
			for(int j=top; j>=1; j--)printf("0 %d\n",E[path[j]].to);
		}
	}
}
