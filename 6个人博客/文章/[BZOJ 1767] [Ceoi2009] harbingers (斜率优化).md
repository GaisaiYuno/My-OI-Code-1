## [BZOJ 1767] [Ceoi2009] harbingers (斜率优化)

###　题面

给定一颗树，树中每个结点有一个邮递员，每个邮递员要沿着唯一的路径走向capital(1号结点)，每到一个城市他可以有两种选择:
1.继续走到下个城市
2.让这个城市的邮递员替他出发
每个邮递员出发需要一个准备时间W[I]，他们的速度是V[I]，表示走一公里需要多少分钟。 现在要你求出每个城市的邮递员到capital的最少时间(不一定是他自己到capital，可以是别人帮他）

### 分析

dp方程很好推,设dp[x]表示x到1的最少时间，dist[x]表示x到1的距离

$dp[x]=max(dp[f]+(dist[x]-dist[f]) \times v[x]+w[x])$，f为x到1路径上的节点

变形一下就是$dp[f]=v[x] \times dist[f] +dp[x]-dist[x] \times v[x]-w[x]$

可以看成坐标系里的点$(dist[f],dp[x])$,用斜率为$v[x]$的直线去截，最小化截距$dp[x]-dist[x] \times v[x]-w[x]$,直接维护斜率单调递增的下凸壳即可



但是有两个问题：

1.斜率v[x]不单调，不弹出队头，直接在凸壳上二分，找到第一个斜率>v[x]的位置即可

2.回溯的时候要删除队列中的x，并把插入的时候弹出的数插回去。直接暴力修改总复杂度是$O(n^2)$的。我们发现弹出再插回其实没有必要，直接改变tail即可。那么我们记录下插入前的tail,二分找到x插入的位置pos,记录pos原来的值，然后修改pos。回溯的时候改回来即可

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
struct edge{
	int from;
	int to;
	ll len;
	int next;
}E[maxn*2+5];
int sz=1;
int ehead[maxn+5];
void add_edge(int u,int v,ll w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=ehead[u];
	ehead[u]=sz;
}

int top=0;
int deep[maxn+5];
ll dist[maxn+5];
int stk[maxn+5];
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=ehead[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dist[y]=dist[x]+E[i].len;
			dfs1(y,x);
			
		}
	}
}

ll dp[maxn+5];
ll w[maxn+5];
ll v[maxn+5];
int head,tail;
int q[maxn+5];

inline double get_up(int j,int k){
	return dp[k]-dp[j];
}
inline double get_down(int j,int k){
	return dist[k]-dist[j];
}

int bin_search1(int l,int r,double k){//找转移位置 
	int ans=r;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(get_up(q[mid],q[mid+1])/get_down(q[mid],q[mid+1])>=k){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
int bin_search2(int l,int r,int i){
	int ans=r+1;
	if(r-l+1<=1) return r+1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(get_up(q[mid-1],q[mid])/get_down(q[mid-1],q[mid])>get_up(q[mid],i)/get_down(q[mid],i)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
} 
void dfs2(int x,int fa){
	int pos1=q[bin_search1(head,tail,v[x])];
	if(x!=1) dp[x]=dp[pos1]+w[x]+v[x]*(dist[x]-dist[pos1]);
	
//	printf("best=%d dp[%d]=%lld\n",pos1,x,dp[x]);
	int pos2=bin_search2(head,tail,x);
	int tmp_tail=tail,tmp_qpos2=q[pos2];
	q[pos2]=x;
	tail=pos2;
	for(int i=ehead[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
		}
	}
	
	q[pos2]=tmp_qpos2;
	tail=tmp_tail;
}

int main(){
//	freopen("10.in","r",stdin);
//	freopen("10.ans","w",stdout);
	int aa,bb;
	long long cc;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %lld",&aa,&bb,&cc);
		add_edge(aa,bb,cc);
		add_edge(bb,aa,cc);
	}
	for(int i=2;i<=n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
	}
	dfs1(1,0);
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	head=1,tail=0;
	dfs2(1,0);
	for(int i=2;i<=n;i++){
		printf("%lld ",dp[i]);
	}
}
```



