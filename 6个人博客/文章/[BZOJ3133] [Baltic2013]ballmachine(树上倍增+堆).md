## [BZOJ3133] [Baltic2013]ballmachine(树上倍增+堆)

###　题面

有一个装球机器，构造可以看作是一棵树。有下面两种操作：

从根放入一个球，只要下方有空位，球会沿着树滚下。如果同时有多个点可以走，那么会选择编号最小的节点所在路径的方向。比如依次在树根`4`放2个球，第一个球会落到`1`，第二个会落到`3`：

![img](https://www.lydsy.com/JudgeOnline/upload/201304/1(7).jpg)

 

从某个位置拿走一个球，那么它上方的球会落下来。比如依次拿走`5, 7, 8`三个球：

![img](https://www.lydsy.com/JudgeOnline/upload/201304/2(1).jpg)

### 分析

我们可以预处理出从根节点放第i个球时,球到达的位置x.因此，对于每个节点x，我们记录放第几个球的时候才能落到x,记为seq[x]。

预处理的时候先dfs一遍，求出每个节点子树中的最小节点编号。然后再dfs一遍，按照子树中的最小节点编号从小到大遍历。实现上直接sort一遍邻接表即可。容易发现，seq[x]就是x在树的后序遍历序列中处在第几个(因为球会尽量往最下方走)

```cpp
void dfs2(int x,int fa){
	for(int i=0;i<(int)E[x].size();i++){//E[x]已经排过序
		int y=E[x][i];
		if(y!=fa){
			dfs2(y,x);
		}
	} 
	seq[x]=++tim;
	hash_seq[seq[x]]=x;
}
```

然后考虑动态插入和删除。

维护一个最小堆，满足堆顶元素seq最小。插入的时候弹出堆顶，把堆顶对应的节点的状态标记为有球。

删除节点x的时候,x到根节点链上的节点会往下落一层。因此只需要用树上倍增找到x祖先里深度最浅的有球节点，将它的状态标记为无球，然后插入最小堆.

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#define maxn 100000
#define maxlogn 21 
using namespace std;
int n,m;
int root;
vector<int>E[maxn+5];

int log2n;
int min_id[maxn+5];//子树中节点的最小编号 
int anc[maxn+5][maxlogn+5];
int deep[maxn+5];
bool cmp(int x,int y){
	return min_id[x]<min_id[y];
}
void dfs1(int x,int fa){
	min_id[x]=x;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs1(y,x);
			min_id[x]=min(min_id[x],min_id[y]);
		}
	} 
}

int tim;
int seq[maxn+5]; //掉球顺序 
int hash_seq[maxn+5];//seq=i的节点编号 
int is_ball[maxn+5];//是否有球 
priority_queue<int,vector<int>,greater<int> >q;//按落球顺序从小到大，存储没有球的节点 
void dfs2(int x,int fa){
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if(y!=fa){
			dfs2(y,x);
		}
	} 
	seq[x]=++tim;
	hash_seq[seq[x]]=x;
}

int insert(int num){
	int ans;
	for(int i=1;i<=num;i++){
		int x=hash_seq[q.top()];
		q.pop();
		is_ball[x]=1;
		if(i==num){
			ans=x;
			break;
		} 
	}
	return ans;
}
int del(int x){
	int orig_x=x;
	for(int i=log2n;i>=0;i--){
		if(is_ball[anc[x][i]]) x=anc[x][i];
	}
	is_ball[x]=0;
	q.push(seq[x]);
	return deep[orig_x]-deep[x];
}

int main(){
	int f;
	int op,num;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&f);
		if(f==0) root=i;
		else E[f].push_back(i);
	} 
	dfs1(root,0);
	for(int i=1;i<=n;i++) sort(E[i].begin(),E[i].end(),cmp);
	dfs2(root,0);
	for(int i=1;i<=n;i++) q.push(seq[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&op,&num);
		if(op==1) printf("%d\n",insert(num));
		else printf("%d\n",del(num));
	}
}

```

