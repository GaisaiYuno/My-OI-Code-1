## [BZOJ 4523] [CQOI2016]路由表(Trie)

### 题面

题面过长，略。

### 分析

对于添加的每个路由表，我们只把掩码那么长的前缀加入01Trie,然后在结尾位置标记插入时间.

查询时我们先找到查询地址在Trie上对应的一条路径。对于路径上的两个串结尾$x,y$,若$x$是$y$的祖先，且$x$的插入时间比$y$晚，那么$x$存在的时候更长的$y$也存在，那么永远不会选择到$x$. 因此我们可以维护一个单调栈，每次碰到一个串结尾就把时间加入,然后弹出更大的元素。最后栈里面留下的元素都是被选择过的串的插入时间，在$[l,r]$范围内的元素的个数即为答案。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 1000000
#define INF 0x3f3f3f3f
using namespace std;
int m;

struct Trie{
	int sz;
	int ch[maxn*32+5][2];
	int val[maxn*32+5];
	void insert(unsigned int v,int len,int tim){
		int x=0; 
		for(int i=31,j=1;j<=len;i--,j++){
			int c=(v>>i)&1;
			if(!ch[x][c]) ch[x][c]=++sz;
			x=ch[x][c];
		} 
		val[x]=tim;
	}
	int query(unsigned int v,int l,int r){
		stack<int>stk;
		int x=0; 
		for(int i=31;i>=0;i--){
			int c=(v>>i)&1;
			if(val[x]){
				while(!stk.empty()&&stk.top()>val[x]) stk.pop();
				stk.push(val[x]);
			}
			if(!ch[x][c]) break;
			x=ch[x][c];
		}
		int ans=0;
		int mint=INF;
		while(!stk.empty()){
			int t=stk.top();
			if(t>=l&&t<=r) ans++;
			stk.pop();
		}
		return ans;
	}
}T;
int main(){
	char cmd[2];
	scanf("%d",&m);
	int tim=0;
	int len;
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='A'){
			unsigned int x,y,z,w;
			unsigned int ans=0;
			scanf("%d.%d.%d.%d/%d",&x,&y,&z,&w,&len);
			ans=x;
			ans=(ans<<8)+y;
			ans=(ans<<8)+z;
			ans=(ans<<8)+w;
			T.insert(ans,len,++tim);
		}else{
			unsigned int x,y,z,w,l,r;
			unsigned int ans=0;
			scanf("%d.%d.%d.%d",&x,&y,&z,&w);
			ans=x;
			ans=(ans<<8)+y;
			ans=(ans<<8)+z;
			ans=(ans<<8)+w;
			scanf("%d %d",&l,&r);
			printf("%d\n",T.query(ans,l,r));
		} 
	}
} 
```

