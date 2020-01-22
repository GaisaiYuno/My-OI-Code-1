//利用打标记的思想，每次递归进入一个点x时，更新从x向下的所有询问，对deep[x]+d的节点打标记 
//树状数组里第i个节点存当前深度为i的节点的标记，由于回溯时删除标记，保证当前深度为i的打了标记节点只有1个 
//注意：每次更新x的距离为d的节点时只更新deep[x]+d
//       查询x时要查询x的子树中的值之和（所有节点之和 ，因为如果x的子树中的节点被加了，x一定也被加了）
//回溯时删除标记，这样每次查询时都保证是x的子树中的节点 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 300005
using namespace std;
int n,m;
vector<int>E[maxn];
struct quest {
	int u;
	int d;
	int v;
	quest(){
		
	}
	quest(int x,int dist,int val){
		u=x;
		d=dist;
		v=val;
	}
};
vector<quest>q[maxn];

struct fenwick_tree {
	long long c[maxn];
	inline int lowbit(int x) {
		return x&-x;
	}
	void update(int x,long long v) {
		while(x<=n) {
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	long long sum(int x) {
		long long ans=0;
		while(x>0){
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
	long long query(int l,int r){
		return sum(r)-sum(l-1);
	}
}T;

int deep[maxn];
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y!=fa) dfs1(y,x);
	}
}

long long ans[maxn];
void dfs2(int x,int fa){
	for(int i=0;i<q[x].size();i++){
		T.update(min(deep[q[x][i].u]+q[x][i].d,n),q[x][i].v);
	}
	ans[x]=T.query(deep[x],n);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs2(y,x);
		}
	}
	for(int i=0;i<q[x].size();i++){
		T.update(min(deep[q[x][i].u]+q[x][i].d,n),-q[x][i].v);
	}
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		q[u].push_back(quest(u,v,w));
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}
