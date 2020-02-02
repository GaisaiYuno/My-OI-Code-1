## [BZOJ 4212]神牛的养成计划(Trie+可持久化Trie)

### 题面

已知n个字符串,有m个询问(强制在线)。每个询问给出两个字符串$s_1,s_2$,问$n$个字符串中有多少个字符串满足既是$s_1$的前缀，又是$s_2$的后缀

$n$个字符串总长度$\leq 2 \times 10^6$,$m \leq 10^5,\sum(|s_1|+|s_2|) \leq 2 \times 10^6$

###　分析

先把$n$个字符串按照字典序排序并按顺序编号,然后正序插入前缀Trie.在每个节点记录包含这个节点代表的前缀的最小编号和最大编号。

这样,满足是$s_1$的前缀的字符串就处于一个连续的区间$[p,q]$。那么我们再把排序后的$n$个字符串倒序插入可持久化Trie,在$[p,q]$区间上查询与$s_2$匹配 的数量即可。

### 代码

```cpp

    
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm> 
#define maxn 2000
#define maxl 2000000
#define maxs 26
using namespace std;
inline void qread(string &s){
	s.clear();
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	while(c>='a'&&c<='z'){
		s.push_back(c);
		c=getchar();
	}
}
int n,m;
string in[maxn+5];

struct Trie {
	int ch[maxl+5][maxs+1];
	int maxt[maxl+5],mint[maxl+5];//子树里字符串的最小和最大编号 
	int ptr=0;
	void insert(string &s,int tim) {
		int n=s.length();
		int x=0;
		for(int i=1; i<=n; i++) {
			int c=s[i-1]-'a';
			if(!ch[x][c]) ch[x][c]=++ptr;
			x=ch[x][c];
			if(!mint[x]) mint[x]=tim;
			maxt[x]=max(maxt[x],tim);
		}
	}
	int query(string &s){
		int n=s.length();
		int x=0;
		for(int i=1; i<=n; i++) {
			int c=s[i-1]-'a';
			if(!ch[x][c]) return 0; 
			x=ch[x][c];
		}
		return x;
	}
} Tpre;

struct persist_trie{
    int root[maxn+5];
    int sz[maxl+5];
    int ch[maxl+5][maxs];
    int ptr;
    void insert(int pos,int pre,string &s){
        int now=root[pos]=++ptr,last=root[pre];
        int n=s.length();
        for(int i=n;i>=1;i--){//倒序插入,这样可以匹配后缀 
            for(int j=0;j<maxs;j++) ch[now][j]=ch[last][j];
            int c=s[i-1]-'a';
            ch[now][c]=++ptr;
            now=ch[now][c];
            last=ch[last][c];
            sz[now]=sz[last]+1;
        }
    }
    int query(int l,int r,string &s){
        int now=root[r];
        int last=root[l-1];
        int n=s.length();
        for(int i=n;i>=1;i--){
            int c=s[i-1]-'a';
            int cnt=sz[ch[now][c]]-sz[ch[last][c]];
            if(cnt==0) return 0;
            now=ch[now][c];
            last=ch[last][c];
        }
        return sz[now]-sz[last];
    }
}Tnex;

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s1,s2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) qread(in[i]);
	sort(in+1,in+1+n);
//	printf("------");
	for(int i=1;i<=n;i++){
		Tpre.insert(in[i],i);
		//把字符串按字典序排序后加入,这样一个前缀相同的字符串的编号是连续的 
	}
	for(int i=1;i<=n;i++){
		Tnex.insert(i,i-1,in[i]);//倒用于匹配后缀 
	}
	scanf("%d",&m);
	int ans=0;
	for(int i=1;i<=m;i++){
		qread(s1);
		qread(s2);
		for(int i=0;i<(int)s1.length();i++) s1[i]=(s1[i]-'a'+ans)%26+'a';
		for(int i=0;i<(int)s2.length();i++) s2[i]=(s2[i]-'a'+ans)%26+'a'; 
		int x,l,r;
		x=Tpre.query(s1);
		if(x){
			l=Tpre.mint[x],r=Tpre.maxt[x];//在trie上找出能与s1匹配的字符串的编号区间 
			ans=Tnex.query(l,r,s2);//在可持久化trie上的对应区间找出后缀匹配个数 
		}else ans=0;
		printf("%d\n",ans);
	}
}



```



