## [BZOJ 2199] [USACO11JAN] 大陆议会The Continental Cowngress(2-SAT)

### 题面

题面较长，略

### 分析

考虑把问题转化成一个依赖性问题

我们把每只奶牛投出的两票中至少有一票和最终结果相符合转化:一只奶牛刚好投两次票，所以只要不满足奶牛的其中一次投票，就要满足另一次，这样就转化成了依赖性问题。

然后把每个议案拆成两个点，一个代表Y,一个代表N，每次把第一票不符合的点向符合的点连边，跑2-SAT

如果用传统的tarjan算法不好判断Y,N都可以的情况，观察数据范围$n \leq 1000,m \leq 4000$,每次判断的的时候直接枚举第i个议案的结果是Y还是N，然后从对应的两个拆点开始BFS，看看有没有矛盾即可。如果两个点都没有矛盾，输出?.

时间复杂度$O(n(n+m))$

### 代码

```cpp
//Tarjan+拓扑不好判断?的情况，暴力dfs 
//xi为A或xj为B 转化为 xi为B且xj为A 
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring> 
#define maxn 1000 
using namespace std;
int n,m;
vector<int>E[maxn*2+5];
void add_edge(int u,int v){
//	printf("%d %d\n",u,v);
	E[u].push_back(v);
}
int mark[maxn*2+5];
void dfs(int x){
	mark[x]=1;
	for(int y : E[x]){
		if(!mark[y]) dfs(y);
	}
}

bool check(int x){
	for(int i=1;i<=n*2;i++) mark[i]=0;
	dfs(x);
	for(int i=1;i<=n;i++){
		if(mark[i]&&mark[i+n])  return 0;
	} 
	return 1;
} 

char ans[maxn+5];
int main(){
	char op1[2],op2[2];
	int u,v,p,q;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %s %d %s",&u,op1,&v,op2);
		if(op1[0]=='Y') p=1;
		else p=0;
		if(op2[0]=='Y') q=1;
		else q=0;
		add_edge(u+n*p,v+n*(1-q));
        /*
        i为Y，i+n为N
        举例理解，如果op1和op2为Y,N
        那么第一个询问是N，不满足，对应的点就是u+1*n,第二个询问是N,满足，对应的点就是v+1*n
        */
		add_edge(v+n*q,u+n*(1-p));
	}
	bool flag1,flag2;
	for(int i=1;i<=n;i++){
		flag1=check(i);
		flag2=check(i+n);
		if(!flag1&&!flag2){
			printf("IMPOSSIBLE\n");
			return 0;
		}else if(flag1&&!flag2){
			ans[i]='Y';
		}else if(!flag1&&flag2){
			ans[i]='N';
		}else{
			ans[i]='?';
		} 
	}
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
}


```

