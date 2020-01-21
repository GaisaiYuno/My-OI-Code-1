## [CF453C] Little Poney and Summer Sun Celebration (思维)

### 题面

§给出一张N个点M条边的无向图，有些点要求经过奇数次，有些点要求经过偶数次，要求寻找一条满足要求的路径，且该路径长度不超过点数的四倍。

§N, M≤100000


### 分析

如果将图整个遍历一遍再回到起点，每个点都被访问了偶数(2)次。对于那些奇数点x,我们先从x走到x的父亲fa,再从fa走回x，然后再继续回溯。这样fa被多访问了2次，奇偶性不变。而x被多访问了一次，访问次数从偶数变为奇数。最后根节点特判一下即可。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100000
using namespace std;
int n,m;
vector<int>E[maxn+5];
vector<int>ans;
bool vis[maxn+5];
int tim[maxn+5];
int cnt[maxn+5];//记录访问次数,一开始等于输入，dfs时不断^1
                //如果有解的话cnt会都变成0（奇数+奇数=偶数，偶数+偶数=偶数）
void dfs(int x,int fa){
	ans.push_back(x);
	vis[x]=1;
	cnt[x]^=1;
	for(int y : E[x]){
		if(y!=fa&&!vis[y]){
			dfs(y,x);
			ans.push_back(x);
			cnt[x]^=1;
		}
	}
	if(fa!=0&&cnt[x]==1){
		ans.push_back(fa);
		ans.push_back(x);
		cnt[fa]^=1;
		cnt[x]^=1;
	}
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	int st=1;
	for(int i=1;i<=n;i++){
		if(cnt[i]==1) st=i;
	}
	dfs(st,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]&&cnt[i]){
			printf("-1\n");
			return 0;
		}
	}
	int sz=ans.size();
	if(cnt[st]) sz--;//如果回到起点会使起点不满足，就不回起点，去掉最后一个点(sz--)
	printf("%d\n",sz);
	for(int i=0;i<sz;i++) printf("%d ",ans[i]);
}
```

