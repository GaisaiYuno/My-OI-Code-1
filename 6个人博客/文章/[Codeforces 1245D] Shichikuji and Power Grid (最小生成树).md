## [Codeforces 1245D] Shichikuji and Power Grid (最小生成树)

### 题面

有n个城市,坐标为$(x_i,y_i)$,还有两个系数$c_i,k_i$.在每个城市建立发电站需要费用$c_i$.如果不建立发电站，要让城市通电，就需要与有发电站的城市连通。i与j之间连一条无向的边的费用是$(k_i+k_j)$*两个城市之间的曼哈顿距离.求让每个城市都通电的最小费用,并输出任意一个方案。

### 分析

把选每个点的代价转成虚拟原点到这个点的边,这个套路很常见，但在最小生成树题里还是第一次见到。

城市之间两两连边，边权按题目里提到的计算。然后建立一个虚拟源点，向每个城市$i$连边，边权为$c_i$.对整个图跑一个最小生成树即可.

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 2000
using namespace std;
typedef long long ll;
int n; 
struct node{
	int x;
	int y;
	int c;
	int k;
}a[maxn+5];
inline ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
} 

struct edge{
	int from;
	int to;
	ll len;
	int next;
}E[maxn*maxn+5];
int head[maxn+5];
int sz=0;
void add_edge(int u,int v,ll w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
} 
bool cmp(edge p,edge q){
	return p.len<q.len;
}

int fa[maxn+5];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

vector< pair<int,int> >res;
ll kruskal(){
	ll ans=0;
	for(int i=1;i<=n+1;i++) fa[i]=i;
	sort(E+1,E+1+sz,cmp);
	for(int i=1;i<=sz;i++){
		int u=E[i].from,v=E[i].to;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=E[i].len;
			fa[fu]=fv;
			res.push_back(make_pair(E[i].from,E[i].to));
		} 
	}
	return ans;
}

vector<int>poi;//poi~ 
vector< pair<int,int> >edg;
int main(){
	int st;
	scanf("%d",&n);
	st=n+1;
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].c);
		add_edge(st,i,a[i].c);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i].k);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			add_edge(i,j,(a[i].k+a[j].k)*dist(a[i].x,a[i].y,a[j].x,a[j].y));
		}
	}
	printf("%I64d\n",kruskal());
	for(auto ed : res){
		if(ed.first==st) poi.push_back(ed.second);
		else edg.push_back(ed);
	}
	printf("%d\n",poi.size());
	for(int x : poi) printf("%d ",x);
	printf("\n");
	printf("%d\n",edg.size());
	for(auto x : edg) printf("%d %d\n",x.first,x.second); 
}

```

