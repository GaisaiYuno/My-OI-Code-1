### [BZOJ 4455] [ZJOI 2016] 小星星 (树形dp+容斥原理+状态压缩)

### 题面

给出一棵树和一个图，点数均为n,问有多少种方法把树的节点标号,使得对于树上的任意两个节点u,v,若树上u,v之间有一条边，图上u,v对应的点之间也有一条边。

$n \leq 17$

### 分析

看到$n \leq 17$,我们应该想到状态压缩。但直接用子集dp的时间复杂度为$O(3^nn^3)$,会TLE。所以我们压缩的状态可能有问题，考虑优化。

显然题目给了两个限制:

1. 原树中的每条边都要在图中出现

2. 每个标号仅出现一次。 

第一个限制可以在dp转移时保证。第二个限制我们在下文中会讨论。先考虑问题的弱化版，只有第一个限制。

在只有第一个限制的前提下，我们可以写出一个简单的树形dp.$dp[x][j]$表示树上$x$的子树中的节点都已经标号，节点$x$的标号为$j$时，的标号方案数。那么:

$$ dp[x][j]=\prod_{y\in son(x)} \sum_{k=1}^n dp[y][k]\ ((j,k) \in G)$$

其中$son(x)$表示$x$的儿子集合,$G$表示原图的边集。最终答案为$\sum_{i=1}^n dp[1][i]$

这样dp的时间复杂度为$O(n^3)$

第二个限制其实可以用容斥原理求解。如果每个标号不仅出现一次，那么有些图上的节点就一定没有被选到。那么答案就是0个节点没被选的方案数-1个节点没被选的方案数+2个节点没被选的方案数......

于是可以用状态压缩枚举没原图被选的节点集合，对于每个节点集合，跑一次上面所述的dp，注意枚举时忽略掉原图没被选的节点。然后根据集合里元素个数的奇偶性，判断加上答案还是减去答案。时间复杂度$O(2^n n^3)$

总结:**先找到题目里的所有限制,在满足题目所给的其余限制的前提下，对其中一个限制进行容斥，也就是先不管这个限制，再减去其不符合限制的答案即可。**

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 17
#define maxm 1000
using namespace std;
typedef long long ll;
int count_bit(int x){//求x的二进制表示里1的个数
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int n,m;
int g1[maxn+5][maxn+5];
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

bool is_del[maxn+5];//哪些节点没被选
ll dp[maxn+5][maxn+5];
void dfs(int x,int fa){
	for(int i=1;i<=n;i++){
		if(is_del[i]) dp[x][i]=0;
		else dp[x][i]=1;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			for(int j=1;j<=n;j++){
				if(is_del[j]) continue;
				ll sum=0;
				for(int k=1;k<=n;k++){
					if(g1[j][k]&&!is_del[k]) sum+=dp[y][k];
				}
				dp[x][j]*=sum;
			}
		}
	}
}

int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		g1[u][v]=g1[v][u]=1;
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	ll ans=0;	
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) is_del[j]=1;
			else is_del[j]=0;
		}
		dfs(1,0);
		ll sum=0;
		for(int j=1;j<=n;j++) sum+=dp[1][j];
		if(count_bit(i)%2==1) ans-=sum;//容斥，如果没被选的个数是奇数，就减去
		else ans+=sum;
	}
	printf("%lld\n",ans);
}
```

