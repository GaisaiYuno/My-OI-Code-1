## [BZOJ 1535] [Luogu 3426]SZA-Template (KMP+fail树+双向链表)

### 题面

 Byteasar 想在墙上涂一段很长的字符,他为了做这件事从字符的前面一段中截取了一段作为模版. 然后将模版重复喷涂到相应的位置后就得到了他想要的字符序列.一个字符可以被喷涂很多次,但是一个位置不能喷涂不同的字符.做一个模版很费工夫,所以他想要模版的长度尽量小,求最小长度是多少.

拿样例来说ababbababbabababbabababbababbaba , 模版为前8个字符ababbaba, 喷涂的过程为: ababbababbabababbabababbababbaba 

### 分析

分析模板串，我们会发现3条性质

> 模板串性质: 
>
> 1. 一个模板串A是要求的文本串B的公共前后缀
> 2. 如果一个模板串A有另一个模板串B（也就是B可以覆盖A），那么B是比A更优的一个解
> 3. 如果模板串A可以完全覆盖文本串B，那么A在B中的匹配位置（按照开头算）之间的空格数不会超过A的长度

证明:

1.如果不是前后缀的话，那开头和结尾就没法涂了

2.由模板串的定义显然

3.画个图或者看样例，喷涂的时候模板串必须相邻或重叠

由性质1，我们发现满足条件的模板串一定是1~next[n],或next[next[n]],next[next[next[n]]]...这样的子串。

因此我们可以枚举前缀的长度，然后$O(n)$判定,但这样的复杂度仍是$O(n^2)$的，考虑优化

-----

这时就需要用到fail树。

fail树其实就是把失配的位置连起来得到的一棵树。我们对于$i \in [1,n]$,连边$(next[i],i)$,$next[i]$为$i$的父亲。由于$next[i]<i$,连出来的一定是一棵树

显然fail树的根为0，fail树上的节点x表示文本串中1~x位,长度为x的子串。而1~next[n],或next[next[n]],next[next[next[n]]]...这样的子串其实就是fail树上0~next[n]的一条链。

> fail树的性质:
>
> y代表的子串的一个公共前后缀为x代表的子串，当且仅当点x是点y的祖先

因此我们就可以先把0~next[n]的链上的节点标记，从根对fail树dfs。每次选在链上的儿子节点递归，然后删除其他儿子节点子树里的所有节点。用一个初始时为1~n的链的双向链表维护相邻元素之间的距离(初始距离为1,删掉x,y中间的一个节点z,x,y之间的距离变为dist(x,z)+dist(y,z))。

容易发现这个距离就是**模板串在文本串中的匹配位置之间的空格数**.根据模板串的性质3,空格数不会超过模板串的长度。而节点x又表示长度为x的子串,因此递归到$x \geq 空格数 $的时候，x就是最小长度.

由于每个节点最多被删除一次，时间复杂度$O(n)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 500000
using namespace std;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int n;
char s[maxn+5];
int nex[maxn+5];

struct list{
	int pre[maxn+5],nex[maxn+5];
	int mv;
	void ini(int n){
		mv=1;
		for(int i=1;i<=n;i++){
			pre[i]=i-1;
			nex[i]=i+1;
		}
	}
	void del(int x){
		pre[nex[x]]=pre[x];
		nex[pre[x]]=nex[x];
		mv=max(mv,nex[x]-pre[x]);
		pre[x]=nex[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			del(y);
		}
	}
	inline int query(){
		return mv;
	}
}S;
int ans=0;
bool mark[maxn+5];
void dfs(int x){//x实际上是某个nex,代表前缀(模板串)长度 
	int to;
	if(S.query()<=x){//模板串性质3 
		ans=x;
		return;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(mark[y]) to=y;
		else S.del(y);//根据fail树的性质2,把不能匹配的部分去掉，得到两个匹配位置之间的最大距离 
	}
	dfs(to);
} 
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}
	for(int i=1;i<=n;i++) add_edge(nex[i],i);//建立fail树 
	S.ini(n);
	for(int i=n;i>0;i=nex[i]) mark[i]=1;//模板串性质1 
	dfs(0);
	printf("%d\n",ans);
}
```

