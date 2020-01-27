## [Codeforces 1239D]Catowise City(2-SAT)

### 题面

有n个主人，每个主人都有一只猫。每个主人认识一些猫(包括自己的猫)。现在要选出一些人和一些猫，个数均大于0且总共为n，且所有人和所有猫都互不认识。判断是否有解，有解输出任意一组方案.

$n \leq 10^6$

### 分析

如果选择人i参加，那么i认识的猫一定不能参加。那么i认识的猫的主人一定要参加。这样就可以保证少了认识的猫，但是多了认识猫的主人，人数和猫数之和仍为n.

因此可以这样建图:**对于人i认识的每只猫的主人j，由i向j连一条有向边，表示选了i就一定要选j。**

根据2-SAT的套路，选了一个点-双联通分量中的任意一个点，那么这个v-DCC里的所有点都要被选择。

那么就可以缩点。如果只有一个v-DCC,说明没有猫被选择，不符合题意。

否则选缩点后的图里任意一个出度为0的v-DCC即可。这里面的全选人，剩下的点全选猫。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack> 
#define maxn 1000000
using namespace std;
int t,n,m;
vector<int>E[maxn*2+5];
void add_edge(int u,int v){
    E[u].push_back(v);
}
 
int dfn[maxn*2+5];
int low[maxn*2+5];
stack<int>st;
int cnt=0,tim=0;
int bel[maxn*2+5];
bool ins[maxn*2+5];
vector<int>bcc[maxn*2+5];
void tarjan(int x){
    dfn[x]=low[x]=++tim;
    st.push(x);
    ins[x]=1;
    for(int y : E[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]); 
        }else if(ins[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(low[x]==dfn[x]){
        cnt++;
        int y;
        do{
            y=st.top();
            st.pop();
            ins[y]=0;
            bel[y]=cnt;
            bcc[cnt].push_back(y); 
        }while(y!=x); 
    }
}
 
bool is_jury[maxn*2+5];
void ini(){
	for(int i=1;i<=n*2;i++){
		E[i].clear();
		bcc[i].clear();
		bel[i]=dfn[i]=low[i]=0;
		is_jury[i]=0;
	}
	cnt=tim=0;
}
 
 
int main(){
	int u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			if(u==v) continue;
			E[u].push_back(v);
		}
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
		if(cnt==1) printf("No\n");
		else{
			printf("Yes\n");
			printf("%d %d\n",bcc[1].size(),n-bcc[1].size());
			for(int x : bcc[1]) {
				is_jury[x]=1;
				printf("%d ",x); 
			}
			printf("\n");
			for(int i=1;i<=n;i++){
				if(!is_jury[i]) printf("%d ",i); 
			} 
			printf("\n"); 
		}
	}
}
```

