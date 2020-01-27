### 题面

[传送门]()

题目大意：给出一个无向图，每个节点可以填1,2,3三个数中的一个

问有多少种填数方案，使两个相邻节点的数之和为奇数

### 分析

如果图中有奇环，一定无解

我们对图黑白染色，由于图可能不联通，记第i个连通分量的黑点数量为$b_i$,白点数量为$w_i$

观察发现每一条边的连接的两个节点，一个是2，另一个是1或3

显然要不黑点全部填2，要不白点全部填2

若黑点填2，则剩下的白点有$2^{w_i}$ 种填法

若白点填2，则剩下的黑点有$2^{b_i}$  种填法

总答案为：

$$\Pi (2^{w_i}+2^{b_i})$$



有两个小坑：

1.多组样例，邻接表记得清空

2.记录颜色数组用for循环初始化，不要用memset,因为数组中非0的数可能很少。memset会访问整个数组，导致TLE

### 代码 

```c++
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define maxn 300005
#define mod 998244353
using namespace std;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

int t,n,m;
vector<int>E[maxn];
int color[maxn];
int cnt0,cnt1;
bool flag=true;
void dfs(int x,int c){
	if(c==1) cnt0++;
	if(c==2) cnt1++; 
	color[x]=c;
	for(auto y : E[x]){
		if(color[y]==0) dfs(y,3-c);
		else if(color[y]==c){
			flag=false;
			return;
		}
	}
} 

void ini(){
	for(int i=1;i<=n;i++) E[i].clear();
//	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++) color[i]=0; 
}
int main(){
	int u,v;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		flag=true;
		long long ans=1; 
		for(int i=1;i<=n;i++){
			if(!color[i]){
				cnt0=cnt1=0;
				dfs(i,1);
				ans=ans*(fast_pow(2,cnt0)%mod+fast_pow(2,cnt1)%mod)%mod;
				if(flag==false) break;
			}
		}
		if(flag==false){
			printf("0\n"); 
		}else{
			printf("%I64d\n",ans);
		}
	}
}
```





