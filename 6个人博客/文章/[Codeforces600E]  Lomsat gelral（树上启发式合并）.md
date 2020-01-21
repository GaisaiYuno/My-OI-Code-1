## [Codeforces600E]  Lomsat gelral（树上启发式合并）

### 题面

给出一棵N个点的树，求其所有子树内出现次数最多的颜色编号和。如果多种颜色出现次数相同，那么编号都要算进答案
N≤100000

### 分析

树上启发式合并，用map记录颜色出现次数，合并的时候更新最多的出现次数和编号和。

注意合并时的下标问题。当我们merge(x,y)的时候，由于是启发式合并，s[x]可能会并到s[y]去，如果我们直接查询s[x]，就查不到真正的答案。所以要再建立一个数组id[x],记录x的map合并之后到了哪里

### 代码

```cpp
//树上启发式合并 
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
int n;
int c[maxn+5];
vector<int>E[maxn+5];

int id[maxn+5];
//当我们merge(x,y)的时候，由于是启发式合并，s[x]可能会并到s[y]去
//然后直接查询s[x]就炸了，所以id[x]就是记录x的map合并之后到了哪里 
map<int,int>s[maxn+5];
int ans_max[maxn+5];//最多的出现次数 
long long ans_cnt[maxn+5];//编号和 
long long res[maxn+5];
void merge(int x,int y){
	if(s[id[x]].size()<s[id[y]].size()){
		swap(id[x],id[y]);
	}
	int u=id[x],v=id[y];
	for(auto it : s[v]){
		int val=it.first;
		int cnt=it.second;
		s[u][val]+=cnt;
		if(s[u][val]>ans_max[u]){
			ans_max[u]=s[u][val];
			ans_cnt[u]=val;	
		}else if(s[u][val]==ans_max[u]){
			ans_cnt[u]+=val;
		}
	} 
}

void dfs(int x,int fa){
	for(int y : E[x]){
		if(y!=fa){
			dfs(y,x);
			merge(x,y);
		}
	}
	res[x]=ans_cnt[id[x]];
}

int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		id[i]=i;
		s[i][c[i]]=1;
		ans_max[i]=1;
		ans_cnt[i]=c[i];
	} 
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%I64d ",res[i]);
	}
}

```



