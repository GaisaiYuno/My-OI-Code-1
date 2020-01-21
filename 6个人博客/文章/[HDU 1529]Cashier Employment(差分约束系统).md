# [HDU 1529]Cashier Employment(差分约束系统)

### 题面

有一个超市，在24小时对员工都有一定需求量，表示为$r_i$,意思为在ｉ这个时间至少要有ｉ个员工，现在有ｎ个员工来应聘，每一个员工开始工作的时间为$t_i(i \in [0,23])$，并持续８小时，问最少需要多少员工才能达到每一个时刻的需求。前一天16点后的人统计入下一天

### 分析

#### 预备知识：（如果你了解过差分约束，可以直接跳过）

首先讲一下差分约束系统的基本定义：如果一个系统由n个变量和m个约束条件组成，形成m个形如$x_i-x_j≤k​$的不等式($i,j∈[1,n],k​$为常数),则称其为差分约束系统(system of difference constraints)。求解差分约束系统，就是找出一组变量x,使得它满足m个约束条件

观察不等式，我们发现它类似于最短路中的不等式$dist_y \leq dist_x +w(x,y)​$。所以我们可以建图求解这个问题。

首先我们建立一个虚拟源点s,从s向i连边权为0的边，然后对于不等式$x_i-x_j≤k$,我们连一条j到i的有向边，边权为k.接着跑Bellman-ford或者SPFA求最短路，如果有负环，则无解。否则$dist_i$就是一组可行解。如果$x_i-x_j \geq k$,那么我们只要改跑最长路就可以了,如果有正环，那么就无解。



#### 本题相关

我们要想办法找出这题的约束条件，然后建图求解。

答案显然有单调性，可以考虑二分答案mid。对于日夜24小时循环的问题，可以采取把环复制一遍，形成长度为48的链求解。

设$d_i$表示前i小时有多少员工开始工作,$p_i$表示第i个小时最多可以请来多少员工开始工作，$r_i$表示第i个小时需要员工的个数。

限制1:$d_i -d_{i-8} \geq r_i (i \geq 8)​$ 保证第i小时在工作的员工够用

限制2:$d_i-d_{i-24} =mid$，即24小时中工作的员工恰好等于答案,可以拆成$d_i-d_{i-24} \geq mid,d_{i-24}-d_i \geq -mid$

限制3:$d_i - d_{i-1} \geq 0$,前缀和显然不会下降

限制4:$d_i - d_{i-1} \leq p_i$，第i个小时在工作的员工不会超过能来的员工数

然后跑差分约束系统，如果无解就增加mid,否则减少mid

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000
#define maxm 10000
#define INF 0x3f3f3f3f
using namespace std;
int n,t;
const int tim=24;
int r[maxn+5],peo[maxn+5];
struct edge {
	int from;
	int to;
	int next;
	int len;
} E[maxm*2+5];
int head[maxn+5];
int sz;
void add_edge(int u,int v,int w) {
//	printf("%d->%d len=%d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

queue<int>q;
int cnt[maxn+5],dist[maxn+5];
bool inq[maxn+5];
bool spfa(int s) {
	while(!q.empty()) q.pop();
	for(int i=0; i<=tim*2; i++) {
		dist[i]=-INF;
		cnt[i]=0;
		inq[i]=0;
	}
	q.push(s);
	dist[s]=0;
	inq[s]=1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=head[x]; i; i=E[i].next) {
			int y=E[i].to;
			if(dist[y]<dist[x]+E[i].len) {//spfa求最长路 
				dist[y]=dist[x]+E[i].len;
				if(!inq[y]) {
					cnt[y]++;
					if(cnt[y]>tim*2) return 0;
					q.push(y);
					inq[y]=1;
				}
			}

		}
	}
	return 1;
}

bool check(int mid) {
	sz=1;
	for(int i=0; i<=tim*2; i++) head[i]=0;
	for(int i=1; i<=tim*2; i++) {
		if(i>=8) {
			//d[i]-d[i-8]>=r[i]
			add_edge(i-8,i,r[i]);
		}
		if(i>=24) {
			//实际上是d[i]-d[i-24]=mid,拆成不等式的形式
			//d[i]-d[i-24]>=mid
			add_edge(i-24,i,mid);
			//d[i]-d[i-24]<=mid
			add_edge(i,i-24,-mid);
		}
		//d[i]-d[i-1]>=0
		add_edge(i-1,i,0);
		//d[i]-d[i-1]<=peo[i]
		add_edge(i,i-1,-peo[i]);
	}
	return spfa(0);
}

void ini() {
	sz=1;
	for(int i=1; i<=tim*2; i++) head[i]=0;
	for(int i=1; i<=tim*2; i++) peo[i]=0;
}
int main() {
	int x;
	scanf("%d",&t);
	while(t--) {
		for(int i=1; i<=tim; i++) {
			scanf("%d",&r[i]);
		}
		scanf("%d",&n);
		ini();
		for(int i=1; i<=n; i++) {
			scanf("%d",&x);
			peo[x+1]++;//默认时间从1开始 
		}
		for(int i=1;i<=tim;i++){//断环为链 
			r[i+tim]=r[i];
			peo[i+tim]=peo[i];
		} 
		int l=0,r=n,mid,ans=n+1;
		while(l<=r) {
			mid=(l+r)>>1;
			if(check(mid)) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(ans==n+1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
}
```



