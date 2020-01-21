# Meet in the Middle 总结

[TOC]



## 1.算法模型

### 1.1 Meet in the Middle算法的适用范围

如果将搜索的路径看成一个有向图，Meet in the Middle 算法适用于求有向图上从A到B，且长度为L的路径数。

换句话说，Meet in the Middle 算法适用于求经过L步变化，从A变到B需要的方案数

### 1.2Meet in the Middle的基本思想

	对于一般的搜索算法，我们一般是从一个初始状态开始搜索，直到找到结果。

	meet in the middle算法采用从初态和终态出发各搜索一半状态，使得搜索树在中间相遇，这样

	可以显著减少搜索的深度。

	如下图所示：

	

### 1.3Meet in the Middle的算法过程

1. 从状态A出发搜索L1步，记录走L1步到达状态i的步数为count(i)
2. 从状态B出发搜索L2步，如果到达状态i,且count(i)不为0，则把count(i)累加到答案中

 首先要保证L1+L2=L，一般选择L1=L2=$\frac{L}{2}$ ,但在某些问题中，不均匀的搜索反而会跑得更快

通俗的说，就是从起点，终点各搜索一半状态，再将状态合起来



### 1.4Meet in the Middle的时间复杂度分析

设A到B搜索L步，每个搜索树的节点的分叉最多D个，计算出下一个节点的时间为T，每个节点的空间为S

则总状态数为$ 2*D^{\frac{L}{2}}$

搜索答案需要$O(D^{\frac{L}{2}}T)$的时间，合并答案理论上需要$O(D^{\frac{L}{2}}S)$的时间（在后面的代码实现部分我们会讨论，由于写法的不同，时间复杂度可能会略大），总时间复杂度为$O(D^{\frac{L}{2}}(S+T))$

## 2.代码实现

Meet in the Middle算法有几种实现方法，搜索部分大致相同，合并答案部分有多种实现

我们以下面这道题为例：



### 例题 [SPOJ ABCDEF]

在[-30000,30000]范围里，给出一组整数集合S。找到满足的六元组的总数使得：

$$\frac{ab+c}{d}-e=f$$

并且保证元组$(a,b,c,d,e,f):a,b,c,d,e,f \in S;d \neq0$



我们将问题转化成$ab+c=d(e+f)$ (注意，**使等式两边未知数个数相等或尽量均匀分布**是用meet in the middle算法解决等式问题的常见方法)

然后我们先搜索ab+c的所有可能结果（可以用DFS，但for循环更简洁）

然后搜索d(e+f)的所有可能结果，然后将两步的结果合起来即可得到答案

### 法1： 结果合并法

	**我们将两次搜索的结果分别存在数组a,b里，然后尝试在$O(m)$或$O(m\log m)$的时间内将结果合并**

	（在本部分，我们定义m为搜索到的状态数量）

	首先我们把a,b数组排序

	对于此题来说，对于a数组的每一个数a[i],我们在b中二分查找与a[i]相等的数的个数 （查找第一>=a[i]的数的位置与第一个>a[i]的数的位置，两个位置相减即为答案

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];
long long num[maxn*maxn*maxn+5];
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){//搜索出a数组
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num[++m]=s[i]*s[j]+s[k];
			}
		}
	}
	sort(num+1,num+1+m);
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){//搜索出b数组，为了节约空间，此处不必存储
				l=lower_bound(num+1,num+1+m,s[i]*(s[j]+s[k]))-num;//第一个=a[i]的数的位置
				r=upper_bound(num+1,num+1+m,s[i]*(s[j]+s[k]))-num-1;//最后一个一个=a[i]的数的位置
				if(r>=l) ans+=(r-l+1);
			}
		}
	}
	printf("%lld\n",ans);
} 
```



### 法2：哈希表

此方法相对较简洁，理论时间复杂度也更低，为$O(m)$

（因为法1常常要用到排序和二分查找，时间复杂度要多一个log）

**第一次搜索时把答案存进哈希表，第二次搜索时在哈希表中查询**即可

但是考虑到hash过程中可能会产生碰撞，导致效率降低。本人不太推荐这种方法（被卡了很多次）

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];

const int c=133331;
struct myhash {
	struct node {
		long long v;
		long long cnt; 
		node* next;
	};
	node a[200005];
	void set0(){
		for(int i=0;i<maxn;i++){
			a[i].v=0;
			a[i].next=NULL;
		}
	}
	void push(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		node *tmp=a[t%c].next;
		if(tmp==NULL){
			tmp=new node();
			tmp->v=x;
			tmp->cnt=1;
			tmp->next=NULL; 
			a[t%c].next=tmp;
			return;
		}
		while(tmp!=NULL){
			if(tmp->v==x){
				tmp->cnt++;
				return;
			} 
			tmp=tmp->next;
		}
		if(tmp==NULL){ 
			node *tmp=new node();
			tmp->v=x;
			tmp->cnt=1;
			tmp->next=a[t%c].next;
			a[t%c].next=tmp;
		} 
	}
	long long count(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		if(a[t%c].next==NULL) return 0;
		else {
			node* tmp=a[t%c].next;
			while(tmp!=NULL) {
				if(tmp->v==x) return tmp->cnt;
				tmp=tmp->next;
			}
			return 0;
		}
	}
};
myhash num;
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	num.set0();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num.push(s[i]*s[j]+s[k]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){ 
				ans+=num.count(s[i]*(s[j]+s[k]));
			}
		}
	}
	printf("%lld\n",ans);
} 
```





### 法3：map

使用STL map，本质和法2一样，但是由于map是基于红黑树，时间复杂度为$O(m\log m)$

虽然map的效率看起来比哈希表低，但map更稳定，不会出现冲突的情况。

```c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];
map<long long,long long>num;//num[i]表示数字i出现的次数
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num[s[i]*s[j]+s[k]]++;//存进map里
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans+=num[s[i]*(s[j]+s[k])];//直接查询
			}
		}
	}
	printf("%lld\n",ans);
} 
```

三种实现方法的比较：

| 实现方法 | 时间复杂度 | 实际运行效率               | 思维难度               | 代码量           |
| -------- | ---------- | -------------------------- | ---------------------- | ---------------- |
| 序列合并 | O(mlogm)   | 较快                       | 较大（有些题不好合并） | 中               |
| 散列表   | O(m)       | 不被卡时最快，但可能会被卡 | 较小                   | 大（手写hash表） |
| STL map  | O(mlogm)   | 较快，但常数较大           | 最小                   | 小               |



## 3.扩展运用

我们通过一些例题来了解



### [BZOJ 4800] 冰球世界锦标赛

有n个物品，m块钱，给定每个物品的价格，求买物品的方案数。 



解法：先搜索用前n/2个物品凑出的钱数，再搜索后n/2个物品凑出的钱数

采用结果合并法，lans存储前一半物品凑出的钱数，rans存储后一半

对于lans[i]，在rans中查找<=m-lans[i]的数的个数

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 45
#define maxs 2000005
using namespace std;
int n;
long long m;
long long a[maxn];
int lcnt; 
long long lans[maxs];//前一半
int rcnt; 
long long rans[maxs];//后一半
void dfs(long long *ans,int &size,int deep,int top,long long sum){
    //ans答案数组，size结果数量，deep表示当前搜索的物品，top表示最多搜到第几个物品，sum表示总和
	if(sum>m) return;
	if(deep==top+1){
		ans[++size]=sum;
		return;
	}
	dfs(ans,size,deep+1,top,sum+a[deep]);
	dfs(ans,size,deep+1,top,sum);
}

int main(){
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(lans,lcnt,1,n/2,0);//搜索[1,n/2]
	dfs(rans,rcnt,n/2+1,n,0);//搜索[n/2+1,n]
	sort(lans+1,lans+1+lcnt);
	sort(rans+1,rans+1+rcnt);
	long long ans=0;
	for(int i=1;i<=lcnt;i++){//合并答案
		ans+=upper_bound(rans+1,rans+1+rcnt,m-lans[i])-rans-1;
        //这里求的是<=m-lans[i]的rans的个数，即rans中第一个大于m-lans[i]的数的位置-1
	} 
	printf("%lld\n",ans);
}
```



### [POJ 1186] 方程的解数

　已知一个n元高次方程： 

　　$k_1x_1^{p_1}+k_2x_2^{p_2}+ \dots+k_nx_n^{p_n}=0$

　其中：x1, x2,…,xn是未知数，k1,k2,…,kn是系数，p1,p2,…pn是指数。且方程中的所有数均为整数。 

　　假设未知数1 <= xi <= M, i=1,,,n，求这个方程的整数解的个数。



解法:将方程变形为

$k_1x_1^{p_1}+k_2x_2^{p_2}+ \dots+k_{n/2}x_{n/2}^{p_{n/2}}=-k_{n/2+1}x_{n/2+1}^{p_{n/2+1}}-\dots-k_{n-1}x_{n-1}^{p_{n-1}}-k_nx_n^{p_n}$

然后就可以类似例题"ABCDEF"，分别搜索左边和右边的所有可能取值，然后再合并

合并方法类似点分治的合并，维护两个索引i,j

i从1~n遍历lans

对于每个i，j从n到1循环，直到找到一个rans[j0]=lans[i0]

然后对于i，从i0向后找到与ans[i0]相等的所有i，并计算出个数cnt1

对于j,从j0向前找到与ans[j0]相等的所有j,并计算出个数cnt2

根据乘法原理，应将cnt1*cnt2累加进答案

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 7
#define maxs 33750005
using namespace std;
int n,m;
int k[maxn];
int p[maxn];
int x[maxn];
int lcnt; 
long long lans[maxs];
int rcnt; 
long long rans[maxs];
inline long long fast_pow(long long x,long long k){
	int ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

void dfs(long long *ans,int &size,int deep,int l,int r,long long sum){
	if(deep==r+1){
		ans[++size]=sum;
		return;
	}
	for(int i=1;i<=m;i++){
		x[deep]=i;//枚举x的可能取值
		dfs(ans,size,deep+1,l,r,sum+k[deep]*fast_pow(x[deep],p[deep]));
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&k[i],&p[i]);
	}
	dfs(lans,lcnt,1,1,n/2,0);
	dfs(rans,rcnt,n/2+1,n/2+1,n,0);
	sort(lans+1,lans+1+lcnt);
	sort(rans+1,rans+1+rcnt);
	int j=rcnt;
	long long ans,cnt1,cnt2;
	ans=0;
	for(int i=1;i<=lcnt;i++){//合并答案
		while(lans[i]+rans[j]>0){
			j--;
		}
		if(j<=0) break;
		if(lans[i]+rans[j]!=0) continue;
		cnt1=cnt2=1;
		while(i<lcnt&&lans[i+1]==lans[i]){
			i++;
			cnt1++;
		}
		while(j>1&&rans[j-1]==rans[j]){
			j--;
			cnt2++;
		}
		ans+=cnt1*cnt2;
	}
	printf("%lld\n",ans);
} 
```

### [BZOJ 2679] Balanced Cow Subsets

给n个数，从中任意选出一些数，使这些数能分成和相等的两组。
求有多少种选数的方案。n≤20



解法：转化为和上面的方程类似的模型

$ a_1x_1+a_2 x_2+ \dots a_n x_n=0 $

其中x只能取1,-1,0 (1代表放在集合1,-1代表放在集合2，0代表不选)

同样对方程移项

不同的是，此题求的不是方程的解，而是方程的解对应集合的数量

我们采用状压，每次搜索除了记录数的和，还要记录状态 （选为1，不选为0）

因为这题不方便用序列合并，我们用map和vector来实现：

开一个map,状态个数个vector

第一次搜索，记录下lsum,lset(lsum为和，lset为对应的集合，mp为一个STL map),用map来离散化，得到lsum对应的离散化后值，并往该值对应的vector中插入lset

第二次搜索，如果搜到的和rsum在mp里面出现过，则可以查到rsum对应的vector编号

遍历这个vector,若vector中的数是lset,当前搜索的集合为rset,则lset+rset为满足条件的集合 （和相等且不重复）

用一个bool数组统计该集合是否出现过即可

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#define maxn 25
#define mod 999917
#define maxh 1000005
#define maxb 1050000
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n;
long long a[maxn];
int vis[maxb];
map<long long,int>mp;
vector<int>v[maxh];
int ans=0;
int cnt=0;
void dfs1(int deep,int top,long long sum,int s) {
	if(deep==top+1) {
		if(!mp.count(sum)) mp[sum]=++cnt;
		v[mp[sum]].push_back(s);
		return;
	}
	dfs1(deep+1,top,sum+a[deep],s|(1<<(deep-1)));
	dfs1(deep+1,top,sum-a[deep],s|(1<<(deep-1)));
	dfs1(deep+1,top,sum,s);
}

void dfs2(int deep,int top,long long sum,int s) {
	if(deep==top+1) {
		if(!mp.count(sum)) return;
		int id=mp[sum];
		for(int i=0;i<v[id].size();i++){
			if(!vis[v[id][i]|s]) ans++;
			vis[v[id][i]|s]=1;
		} 
		return;
	}
	dfs2(deep+1,top,sum+a[deep],s|(1<<(deep-1)));
	dfs2(deep+1,top,sum-a[deep],s|(1<<(deep-1)));
	dfs2(deep+1,top,sum,s);
}

int main() {
	n=qread();
	for(int i=1; i<=n; i++) {
		a[i]=qread();
	}
	int m=n/2;;
	dfs1(1,m,0,0);
	dfs2(m+1,n,0,0);
	printf("%d\n",ans-1);

}
```



------

参考资料：

乔明达《搜索问题中的meet in the middle技巧》  









