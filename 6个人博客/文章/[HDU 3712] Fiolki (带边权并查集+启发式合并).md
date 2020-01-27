## [HDU 3712] Fiolki (带边权并查集+启发式合并)

### 题面

化学家吉丽想要配置一种神奇的药水来拯救世界。
吉丽有n种不同的液体物质，和n个药瓶（均从1到n编号）。初始时，第i个瓶内装着g[i]克的第i种物质。吉丽需要执行一定的步骤来配置药水，第i个步骤是将第a[i]个瓶子内的所有液体倒入第b[i]个瓶子，此后第a[i]个瓶子不会再被用到。瓶子的容量可以视作是无限的。
吉丽知道某几对液体物质在一起时会发生反应产生沉淀，具体反应是1克c[i]物质和1克d[i]物质生成2克沉淀，一直进行直到某一反应物耗尽。生成的沉淀不会和任何物质反应。当有多于一对可以发生反应的物质在一起时，吉丽知道它们的反应顺序。每次倾倒完后，吉丽会等到反应结束后再执行下一步骤。
吉丽想知道配置过程中总共产生多少沉淀。

$n,m \leq 2 \times 10^5,k \leq 5 \times 10^5$

### 分析

注意到初始状态下第i个瓶子里有物质i,也就是说每种物质恰好只在一个瓶子里。那么**混合的过程中，每种反应至多发生一次**。对于一个反应$(a,b)$,因为开始反应前只有1个瓶子里有a,1个瓶子里有b.而当a,b相遇时，会一直进行直到完全反应。

那么，我们只要知道第i个反应发生的时间，然后按时间给反应排序(时间相同时按优先级排序).然后一个个反应按顺序模拟，更新反应物的质量和沉淀质量。

如何求某个反应(a,b)发生的时间呢?。我们把处在同一个烧杯里的物质看成一个联通块，(a,b)发生的时间就是a和b最早连通的时间。用并查集维护连通性，每个点x还要另外记录tim[x],表示x什么时间与父亲相连。答案就是u到v路径上的点tim的最大值。具体参考[[BZOJ 4668\]冷战(并查集+启发式合并)](https://www.cnblogs.com/birchtree/p/11478586.html)

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define maxk 500000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct disjoint_set{
	int fa[maxn+5];
	int tim[maxn+5];
	int sz[maxn+5];
	int find(int x){
		while(fa[x]!=x) x=fa[x];
		return x;
	}
	int get_deep(int x){
		int ans=0;
		while(fa[x]!=x){
			ans++;
			x=fa[x];
		}
		return ans;
	}
	void merge(int x,int y,int t){
		int fx=find(x);
		int fy=find(y);
		if(sz[fx]>sz[fy]) swap(fx,fy);
		fa[fx]=fy;
		tim[fx]=t;
		sz[fy]+=sz[fx];
	}
	int query(int x,int y){
		if(find(x)!=find(y)) return INF; 
		int ans=0;
		int dx=get_deep(x),dy=get_deep(y);
		if(dx<dy){
			swap(x,y);
			swap(dx,dy);
		}
		while(dx>dy){
			ans=max(ans,tim[x]);
			x=fa[x];
			dx--;
		}
		if(x==y) return ans;
		while(x!=y){
			ans=max(ans,max(tim[x],tim[y]));
			x=fa[x];
			y=fa[y]; 
		} 
		return ans;
	}
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
	}
}S;
int n,m,k;
int g[maxn+5];
struct rec{
	int x;
	int y;
	int tim;
	int id;
	friend bool operator < (rec p,rec q){
		if(p.tim==q.tim) return p.id<q.id;
		else return p.tim<q.tim; 
	}
}q[maxk+5]; 
int main(){
	int u,v;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
	} 
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		S.merge(u,v,i);
	}
	for(int i=1;i<=k;i++){
		scanf("%d %d",&q[i].x,&q[i].y);
		q[i].tim=S.query(q[i].x,q[i].y);
		q[i].id=i; 
	}
	sort(q+1,q+1+k);
	ll ans=0;
	for(int i=1;i<=k;i++){
		if(q[i].tim==INF) continue;
		int x=q[i].x,y=q[i].y;
		int sum=min(g[x],g[y]);
		g[x]-=sum;
		g[y]-=sum;
		ans+=sum*2;
	}
	printf("%lld\n",ans);
}

```



[[BZOJ 4025\]二分图(线段树分治+带边权并查集)](https://www.cnblogs.com/birchtree/p/11478303.html)

[[BZOJ 4668\]冷战(并查集+启发式合并)](https://www.cnblogs.com/birchtree/p/11478586.html)

[[BZOJ 3123\] [SDOI 2013]森林(可持久化线段树+并查集+启发式合并)](https://www.cnblogs.com/birchtree/p/11480442.html)
