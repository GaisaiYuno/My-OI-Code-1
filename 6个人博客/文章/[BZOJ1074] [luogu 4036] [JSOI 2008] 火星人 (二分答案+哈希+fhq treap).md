## [BZOJ1074] [luogu 4036] [JSOI 2008] 火星人 (二分答案+哈希+fhq treap)

### 题面

给出一个长度为n的字符串，m个操作,字符串仅包含小写英文字母

操作1：在k位置后插入字符v:

操作2：将k位置的字符修改为字符v

操作3：查询从该字符串中第 x个字符开始的字符串，与该字符串中第 y个字符开始的字符串，两个字串的公共前缀的长度

###　分析

看到动态插入和修改，考虑用fhq treap维护字符串序列。以下split指按子树大小分裂

操作1：同样split出前k个的子树x，和剩下的子树y,新建一个节点v,merge(merge(x,v),y)

操作2：split出前k-1个的子树x,k对应的子树y，和剩下的子树z,新建一个节点v,merge(merge(x,v),z)即可，y子树丢弃

操作3：考虑二分答案，然后问题就转化为查询区间[l1,r1],区间[l2,r2]是否相等。这可以通过用fhq treap,维护以x为根中序遍历得到序列的hash值，查询的时候只要split(r),split(l-1)即可



### 代码

```cpp
// luogu-judger-enable-o2
//常数略大，开O2AC，待卡常 
//https://www.luogu.org/problem/P4036
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000
#define prime 27
using namespace std;
typedef unsigned int ull;
ull p[maxn+5];
struct fhq_treap{
#define lson(x) (tree[x].ls) 
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int val;
		int dat;
		ull hs;//hash
		int sz;
	}tree[maxn+5];
	int ptr=0;
	int root;
	void push_up(int x){
		tree[x].sz=tree[lson(x)].sz+tree[rson(x)].sz+1;
		tree[x].hs=tree[lson(x)].hs*p[tree[rson(x)].sz+1]+tree[x].val*p[tree[rson(x)].sz]+tree[rson(x)].hs;
        //从左到右hash,相当于中序遍历
        //假如左子树是ab,x是c,右子树是de,整个序列是abcde
        //由于我们把abcde看成一个p进制数来hash，那么ab,c要乘上p的次方
	}
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].hs=val;
		tree[ptr].sz=1;
		return ptr;
	}
	int merge(int x,int y){
		if(!x||!y) return x+y;
		if(tree[x].dat<tree[y].dat){
			tree[x].rs=merge(tree[x].rs,y);
			push_up(x);
			return x;
		}else{
			tree[y].ls=merge(x,tree[y].ls);
			push_up(y);
			return y; 
		}
	}
	void split(int now,int k,int &x,int &y){
		if(now==0){
			x=y=0;
			return;
		}
		if(k<=tree[lson(now)].sz){
			y=now;
			split(tree[now].ls,k,x,tree[y].ls);
		}else{
			x=now;
			split(tree[now].rs,k-tree[lson(now)].sz-1,tree[x].rs,y);
		}
		push_up(now);
	}
	void insert(int pos,int val){//在pos后面插入val 
		int x,y;
		split(root,pos,x,y);
		root=merge(merge(x,New(val)),y);
	}
	void update(int pos,int val){//把pos改成val 
		int x,y,z;
		split(root,pos,y,z);
		split(y,pos-1,x,y);
		root=merge(merge(x,New(val)),z); 
	} 
	ull query(int l,int r){
		int x,y,z;
		ull ans;
		split(root,r,y,z);
		split(y,l-1,x,y);
		ans=tree[y].hs;
		root=merge(x,merge(y,z));
		return ans; 
	}
#undef lson
#undef rson
}T;

int n,m;
char a[maxn+5];
bool check(int x,int y,int len){
	return T.query(x,x+len-1)==T.query(y,y+len-1);
}
int bin_search(int x,int y){
	int l=1,r=min(n-x+1,n-y+1);
	int mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(x,y,mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	int x,y;
	char cmd[2],val[2];
	scanf("%s",a+1);
	n=strlen(a+1);
	p[0]=1;
	for(int i=1;i<=maxn;i++) p[i]=p[i-1]*prime;
	for(int i=1;i<=n;i++){
		T.insert(i-1,a[i]-'a'+1);
	}
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d %d",&x,&y);
			if(x>y) swap(x,y);
			printf("%d\n",bin_search(x,y)); 
		}else if(cmd[0]=='R'){
			scanf("%d %s",&x,val);
			T.update(x,val[0]-'a'+1);
		}else{
			scanf("%d %s",&x,val);
			T.insert(x,val[0]-'a'+1);
			n++;
		}
	}
}
```

