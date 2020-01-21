## [Luogu P4735]最大异或和(可持久化Trie)

### 题面

给定一个非负整数序列{a}，初始长度为N。

有M个操作，有以下两种操作类型：

1、Ax：添加操作，表示在序列末尾添加一个数x，序列的长度N+1。

2、Qlrx：询问操作，你需要找到一个位置p，满足l<=p<=r，使得：a[p] xor a[p+1] xor ... xor a[N] xor x 最大，输出最大是多少。

### 分析

维护$sum[i]=sum[i-1] \ \text{XOR} \  a[i]$,那么答案就是$sum[p-1] \ \text{XOR} \ sum[n] \ \text{XOR} \ x$.这样$a[1],a[2] \dots a[p-1]$都被异或了两次抵消掉。

那么问题就变成,找到一个位置$p$,满足$l\leq p \leq r$,使得对于定值$val=x \ \text{XOR} \ a[n]$,有$val \ \text{XOR} \ a[p-1]$最大。类似[[51nod 1295]Xor key(可持久化trie)](https://www.cnblogs.com/birchtree/p/11624657.html)这样求解。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#define maxlog 32
#define maxn 600000
using namespace std;



struct persist_trie{
    int sz[maxn*maxlog+5];
    int root[maxn+5];
    int ch[maxn*maxlog+5][2];
    int ptr;
    void insert(int pos,int val){
        int now=root[pos]=++ptr;
        int last=root[pos-1];
        for(int i=maxlog-1;i>=0;i--){
            sz[now]=sz[last]+1;
            int k=(val>>i)&1;
            ch[now][k]=++ptr;
            ch[now][k^1]=ch[last][k^1];
            now=ch[now][k];
            last=ch[last][k];
        } 
        sz[now]=sz[last]+1;
    } 
    int query(int l,int r,int val){
        int now=root[r];
        int last=root[l-1];
        int ans=0;
        for(int i=maxlog-1;i>=0;i--){
            int k=(val>>i)&1;
            int lsz=sz[ch[now][k^1]]-sz[ch[last][k^1]];
            if(lsz){
                now=ch[now][k^1];
                last=ch[last][k^1];
                ans=ans<<1|1;
            }else{
                now=ch[now][k];
                last=ch[last][k];
                ans=ans<<1;
            }
        }
        return ans;
    }
}T;

int n,m;
int a[maxn+5],sum[maxn+5];
//sum[p]表示前缀异或和
//a[p]^a[p+1]^...a[n]=sum[p-1]^sum[n] 
//问题变成已知x^sum[n],在[l,r]中求一个sum[i],使得sum[i]^(x^sum[n])最大 
int main(){
    int l,r,x;
    char ch[10];
    scanf("%d %d",&n,&m);
    T.insert(0,sum[0]);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
        T.insert(i,sum[i]);
    }
    for(int i=1;i<=m;i++){
    	scanf("%s",ch);
    	if(ch[0]=='A'){
    		scanf("%d",&x);
    		n++;
    		sum[n]=sum[n-1]^x;
    		T.insert(n,sum[n]);
		}else{
			scanf("%d %d %d",&l,&r,&x);
			printf("%d\n",T.query(max(l-1,1),r-1,x^sum[n]));
		} 
    }
}
```



