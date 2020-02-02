# 决策单调性优化dp学习笔记

## 决策单调性的定义

### 四边形不等式



> **定义1.1.1**:
>
> 若函数$w(x,y)(\mathbb{Z} \times \mathbb{Z} \rightarrow \mathbb{Z})$对于$\forall a,b,c,d \in \mathbb{Z}$,其中$a \leq b \leq c \leq d$,都有$w(a,d)+w(b,c) \geq w(a,c)+w(b,d)$,则称函数$w$满足四边形不等式

如果我们考虑用图形来表达，那么可以简记为“交叉”和“包含”的关系

这是四边形不等式最基本的定义。但是在做题中我们常常遇到下面的一种形式.

> **推论1.1.1**:
>
> 若函数$w(x,y)(\mathbb{Z} \times \mathbb{Z} \rightarrow \mathbb{Z})$对于$\forall a,b \in \mathbb{Z}$,其中$a<b$,都有$w(a,b+1)+w(a+1,b) \geq w(a,b)+w(a+1,b+1)$,则称函数$w$满足四边形不等式

证明:

对于$a<c$，有：$w(a,c+1)+w(a+1,c)≥w(a,c)+w(a+1,c+1)$

对于$a+1<c$，有：$w(a+1,c+1)+w(a+2,c)≥w(a+1,c)+w(a+2,c+1)$

两式相加，得：$w(a,c+1)+w(a+1,c)+w(a+1,c+1)+w(a+2,c)≥w(a,c)+w(a+1,c+1)+w(a+1,c)+w(a+2,c+1)$

整理得：
$w(a,c+1)+w(a+2,c)≥w(a,c)+w(a+2,c+1)$

以此类推,可得

$\forall a \leq b \leq c,\ \ w(a,c+1)+w(b,c)\geq w(a,c)+w(b,c+1)$

同理对第二个数做这样的证明,即可得到

$\forall a \leq b \leq c \leq d, \ \ w(a,c+1)+w(b,c)\geq w(a,c)+w(b,c+1)$

### 四边形不等式与决策单调性

> **定义1.2.1**:对于形如$f[i]=\min _{0 \leq j < i}(f[j]+w(j,i))$的状态转移方程,记$p[i]$为$f[i]$取到最小值时$j$的值.$p[i]$即为$f[i]$的最优决策。如果$p[i]$在$[1,n]$上单调不减,则称$f$具有决策单调性

> **定理1.2**:对于形如$f[i]=\min _{0 \leq j < i}(f[j]+w(j,i))$的状态转移方程,若函数$w$满足四边形不等式,则$f$具有决策单调性

$\forall i\in [1,n],j \in [0,p[i]-1]$,根据决策单调性的定义得:

$f[p[i]]+w(p[i],i) \leq f[j]+w(j,i) \ \ \ \ \ \ (1)$(即$p[i]$前的决策都没有$i$优)

$\forall i' \in[i+1,n]$,显然$j<p[i]<i<i'$,由于$w$满足四边形不等式,那么有

$w(j,i')+w(p[i],i) \geq w(j,i)+w(p[i],i')$

移项,得$w(p[i],i')-w(p[i],i) \leq w(j,i')-w(j,i) \ \ \ \ \ \ (2)$

$(1)+(2)$得$f[p[i]]+w(p[i],i') \leq f[j]+val(j,i')$

那么对于$i'$来说,以$p[i]$作为$i'$的决策,比$j<p[i]$作为$i'$的决策更优。因此$f[i'](i'>i)$的最优决策不可能小于$p[i]$,即$p[i'] \geq p[i]$.$f$有决策单调性

于是，我们得到了证明一个dp方程满足决策单调性的方法:

1. 证明权函数$w$满足四边形不等式(比赛中可以采用打表估(xia)计(cai)的方法)
2. 根据定理1.2,状态转移方程$f$满足决策单调性

然而这样有什么用呢？根据决策单调性，我们可以把原来的$O(n^2)$的dp优化到$O(n\log n)$甚至是$O(n)$

## 决策单调性的通用解法:单调队列+二分查找

### [BZOJ 1563] [NOI 2009] 诗人小G

[题目链接](http://119.29.55.79/problem/4001)

> 一首诗包含了若干个句子，对于一些连续的短句，可以将它们用空格隔开并放在一行中，注意一行中可以放的句子数目是没有限制的。小 G 给每首诗定义了一个行标准长度（行的长度为一行中符号的总个数），他希望排版后每行的长度都和行标准长度相差不远。显然排版时，不应改变原有的句子顺序，并且小 G 不允许把一个句子分在两行或者更多的行内。在满足上面两个条件的情况下，小 G 对于排版中的每行定义了一个不协调度, 为这行的实际长度与行标准长度差值绝对值的 P 次方，而一个排版的不协调度为所有行不协调度的总和。
>
> 小 G 最近又作了几首诗，现在请你对这首诗进行排版，使得排版后的诗尽量协调（即不协调度尽量小），并把排版的结果告诉他
>
> $n \leq 5\times 10^5$

#### 转移方程推导

显然,设$dp[i]$为选了第$i$个句子并在此换行的最小不协调度。每句诗的长度为$a[i]$,$sum[i]$为前$i$句诗的总长度，那么

$$dp[i]=\min_{0 \leq j <i}(dp[j]+|sum[i|-sum[j]+(i-j-1)-L|^P)$$

后面的式子表示把第$(j,i]$句分成一行的代价。句子长度为$sum[i]-sum[j]$,空格长度为$i-j-1$

这里的$w$函数为$w(j,i)=|sum[i|-sum[j]+(i-j-1)-L|^P$,由于$P$的次数较高,无法斜率优化。于是尝试证明$w$满足四边形不等式

#### 决策单调性证明

我们要证明$\forall j<i,w(j,i+1)+w(j+1,i) \geq w(j,i)+w(j+1,i+1)$

移项，得$w(j+1,i)-w(j+1,i+1) \geq w(j,i)-w(j,i+1)$

记:

$u=(sum[i]+i)-(sum[j]+j)-(L+1)$

$v=(sum[i]+i)-(sum[j+1]+j+1)-(L+1)$

则只需证明

$$|v|^P=|v+(a[i+1|+1)|^P \geq |u|^P -|u+(a[i+1]+1)|^P$$

即证明对于任意常数$c$,函数$h(x)=|x|^P-|x+c|^P$单调递减.证明比较繁琐，这里引用一下

![prof1.JPG](https://i.loli.net/2019/12/16/XDi5EfMcOVRwv2o.jpg)

![prof2.JPG](https://i.loli.net/2019/12/16/wLXR9QsjvOgUkF8.jpg)

总之,$w$满足四边形不等式,那么$f$有决策单调性

#### 优化方法

由于单调性，每个决策$x$肯定存在一个区间$[l[x],r[x]]$使得当前情况下$p[k]=x(k \in[l[x],r[x]])$，

记$pos(x,y)$表示**当前情况**下,第一个以$x$为决策点不如以$y$为决策点更优的位置(如果当前只计算到$dp[i]$,则对于$i'>i$,$p[i']=i$)。则$r[x]=l[y]=pos(x,y)$.$pos$可以二分查找求出。

我们维护一个单调队列存储决策点。在处理$dp[i]$时,我们这样做:

1. 如果队头的决策点对应区间不包含i,即$r[q[head]]=pos(q[head],q[head+1])<i$则出队

2. 通过队头决策点转移

3. 通过二分寻找出最左边的，以$q[tail]$为决策点不如以i为决策点更优的位置。这个位置实际上是$l[i]$.由于决策单调性，目前从这个位置往右的 dp 都满足以i为决策点是最优的。再二分出$l[q[tail]]=pos(q[tail-1],q[tail])$,如果$l[i]<r[q[tail]]$,说明$q[tail]$决策点对应的所有转移都不如$i$更优,我们把$q[tail]$出队,继续比较下一个决策点

4. 当队尾的弹出停止的时候，将$i$入队，且$i$对应区间右端点为$n$

   

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#define maxn 500000
#define maxl 30
#define INF 1e18
using namespace std;
typedef long double db;
int T;
int n,L,P;
char s[maxn+5][maxl+5];
int sum[maxn+5];
db dp[maxn+5];
int res[maxn+5];
inline db fast_pow(db x,int k){
	db ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
inline db calc(int j,int i){//计算f[j]+val(j,i) 
	return dp[j]+fast_pow(abs(sum[i]-sum[j]+(i-j-1)-L),P);
}
inline int bin_search(int a,int b){//找到第一个决策b比决策a优的位置 
	if(calc(a,n)<calc(b,n)) return n+1;
	int l=b,r=n;
	int ans=-1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(calc(b,mid)<=calc(a,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
void ini(){
	for(int i=1;i<=n;i++){
		dp[i]=INF;
		res[i]=0;
	}
}

int q[maxn+5];
int stk[maxn+5];//找出1~n最优决策的每一段 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&L,&P);
		ini();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			sum[i]=strlen(s[i])+sum[i-1];
		} 
		int head=1,tail=0;
		q[++tail]=0;
		dp[0]=0;
		for(int i=1;i<=n;i++){
			while(head<tail&&bin_search(q[head],q[head+1])<=i) head++;
			//使得head决策点的对应区间包含i 
			res[i]=q[head];
			dp[i]=calc(q[head],i);
			while(head<tail&&bin_search(q[tail-1],q[tail])>=bin_search(q[tail],i)) tail--;
			//把以队尾决策点为决策点不如以i为决策点更优的位置出队 
			q[++tail]=i; //并替换成i 
		}
		if(dp[n]>INF){
			printf("Too hard to arrange\n");
		}else{
			printf("%lld\n",(long long)dp[n]);
			// int top=0;
			// for(int i=n;i;i=res[i]) stk[++top]=i;
			// stk[++top]=0;
			// for(int i=top-1;i>=1;i--){
			// 	int r=stk[i],l=stk[i+1]+1;
			// 	for(int j=l;j<r;j++) printf("%s ",s[j]);
			// 	printf("%s\n",s[r]);
			// } 
		}
		printf("--------------------\n");
	}
}
```





### [UOJ 285]数据分块鸡(法1)



## 决策单调性的特殊解法:斜率优化

先简单复习一下斜率优化:

斜率优化是决策单调性问题一种衍生算法，一类特殊的决策单调性问题可以利用斜率
优化在线性时间内得到解决。  

将一个决策 $j$看作平面上的一个点$(x_j,y_j)$。对于i来说，$\forall k<j,f_j+w(j,i) \leq f_k+w(k,j)$,当且仅当$\frac{y_j-y_k}{x_j-x_k} \leq C_i$

其中$x_j,y_j$均在计算$f_j$后已知,$C_i$已知

实现这一算法的一般方法为维护所有决策点构成的凸包

1. 当$x$单调递增时,在凸包上二分寻找第一个斜率不超过$C_i$的位置,时间复杂度$O(n \log n)$
2. 当$x,C$单调递增时可以利用单调队列直接维护凸包，询问时只需弹出队首不满足条件的元素即可。  时间复杂度$O(n)$
3. 当$x,C$均不单调递增时可以使用cdq分治.时间复杂度$O(n \log n)$

### [ARC 66D]Contest with Drinks Hard(弱化版) 

[题目链接](http://119.29.55.79/problem/4000)

> 在一场比赛中一共有$n$道题，其中解决第$i$道题需要花费$T_i$秒。你可以在所有题中挑选
> 任意一些题并解决它们。定义一种解决方案所得的分数为满足$\forall i \in [L,R]$ 第$i$道题被解决
> 且$1 ≤ L ≤ R ≤ n$的$[L,R]$对数减去解决问题所需要的时间和。
> 求最高分数
> 
>$n \leq 3 \times 10^5$

#### 

设$sum$为序列$a$的前缀和，$dp[i]$表示对于前i个位置其中第i个不选的最大价值，假设枚举j表示上一个不选的位置是j。那么$[j+1,i]$成为了一个满足题面条件的区间，增加的对数为$C_{i-j}^2=\frac{(i-j)(i-j-1)}{2}$,那么

$$dp[i]=\min_{0 \leq j <i},dp[j]-(sum[i-1]-sum[j])+\frac{(i-j)(i-j-1)}{2}$$

化成$dp[j]+sum[j]+\frac{j^2+j}{2}=ji+dp[i]+sum[i-1]-\frac{i^2-i}{2}$

决策点为$(j,dp[j]+sum[j]+\frac{j^2+j}{2})$,斜率为$i$,最小化截距$dp[i]+sum[i-1]-\frac{i^2-i}{2}$,可以直接斜率优化



## 决策单调性的特殊解法:整体分治

### [ARC 66D]Contest with Drinks Hard

[题目链接](http://119.29.55.79/problem/4000)

> 在一场比赛中一共有$n$道题，其中解决第$i$道题需要花费$T_i$秒。你可以在所有题中挑选
> 任意一些题并解决它们。定义一种解决方案所得的分数为满足$\forall i \in [L,R]$ 第$i$道题被解决
> 且$1 ≤ L ≤ R ≤ n$的$[L,R]$对数减去解决问题所需要的时间和。
> 现给出$m$组询问，第i组询问需要你求出将第$X_i$道题的解决时间变为$Y_i$秒后，分数最高
> 方案的得分(询问后序列还原)。
>
> $n \leq 3 \times 10^5$

#### 朴素情况

设$sum$为序列$a$的前缀和，$dp[i]$表示对于前i个位置其中第i个不选的最大价值，假设枚举j表示上一个不选的位置是j。那么$[j+1,i]$成为了一个满足题面条件的区间，增加的对数为$C_{i-j}^2=\frac{(i-j)(i-j-1)}{2}$,那么

$$dp[i]=\min_{0 \leq j <i},dp[j]-(sum[i-1]-sum[j])+\frac{(i-j)(i-j-1)}{2}$$

化成$dp[j]+sum[j]+\frac{j^2+j}{2}=ji+dp[i]+sum[i-1]-\frac{i^2-i}{2}$

决策点为$(j,dp[j]+sum[j]+\frac{j^2+j}{2})$,斜率为$i$,最小化截距$dp[i]+sum[i-1]-\frac{i^2-i}{2}$,可以直接斜率优化

#### 带修改的情况

考虑将pos位置改为x，那么原来要么选了$a_{pos}$,要么没有选$a_{pos}$

1. 不选$a_{pos}$，那么只需要预处理出前缀和后缀的dp值$f$和$g$，那么答案就是$f[pos]+g[pos]$
2. 选了$a_{pos}$,那么要满足选的数构成的区间包含pos。考虑预处理出$h$表示强制选第$i$个的dp值,那么答案就是$h[i]+a[i]-r$

直接枚举跨越$i$的区间比较难办，考虑分治，每个分治区间[l,r]只讨论：前缀意义下,选了上一个不选的在[l,mid],最后一个选的在[mid+1,r]的答案。以及后缀意义下上一个不选的在[mid+1,r],最后一个选的在[l,mid]的答案

//代码过于毒瘤，还没调出来

### [NAIPC2016]Jewel Thief(法1)

[题目链接](http://119.29.55.79/problem/4004)

> 有$n$个物品，每个物品有一个体积$w_i$和价值$v_i$，现在要求对$V \in [1,m]$，求出体积为$V$的
> 背包能够装下的最大价值
>
> $1 ≤ n ≤ 1000000; 1 ≤ m ≤ 100000; 1 ≤ w_i ≤ 300; 1 ≤ v_i ≤ 10^9$

#### 决策单调性发现

注意到物品的体积很小，考虑按体积分类，选取同种体积的物品时，一定优先选择价值大的物品。  

设$dp[i][j]$为使用前i种体积的物品，体积为j的最大价值。类似多重背包的单调队列优化，将模i同余的所有位置拿出来重新标号(即下标看作1,2,3....x)。
则有  

$$dp[i][j]=\max_{k=0}^j dp[i-1][k]+val(k,j)$$

其中$w(k,j)$表示第$i$种体积的物品中,最大的$j-k$个的价值和

显然$val$满足四边形不等式。

#### 问题转化  

令$A$为一个矩阵,$pos(j)=max(\{i|,\forall p \in [0,m],A[i][j]>A[p][j] \})$,即使得第$j$列第$i$行的值最大的$i$(如果有多个i相同，则取编号最大的)

在原问题中，考虑第$i-1$层到第$i$层的转移 ,令$A[k][j]=\begin{cases} dp[i-1][k]+val(k,j),k \leq j \\ -\infty,k>j\end{cases}$,我们发现dp的转移实际上就是在求第$k$行第$j$列的最大值，其中$j$固定。那么$dp[i][j]=A[pos(j)][j]$

于是问题就转化为:已知一个$(m+1)\times(m+1)$大小的矩阵$A$，其中每个元素的值均可以在$O(1)$时间内查询。现
要求对于$j \in [0,m]$,求出$A[pos(j)][j]$

#### 分治求解

对列[l,r]进行分治，维护当前可能成为$pos$的行$[x,y]$，令$mid=\frac{l+r}{2}$,暴力枚举所有可能的行求出$pos(mid)$，分治递归操作$[l,mid-1] [x,pos(mid)]$以及$[mid +1,r] [pos(mid),y]$直至$l = r$或$x = y$。容易发现这样的时间复杂度是$O(m\log m)$

  

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxw 300
#define maxn 1000000
using namespace std;
typedef long long ll;
vector<ll>w[maxw+5];
ll dp[2][maxn+5];
int n,m;
void divide(int l,int r,int x,int y,int now,int mod,int rest){
	//列[l,r],行[x,y]; 
	if(l>r) return;
	int mid=(l+r)>>1,pos=mid;
	dp[now^1][mid*mod+rest]=dp[now][mid*mod+rest];
	for(int j=min(y,mid-1);j>=x;j--){//枚举可能成为pos(mid)的列,注意j<mid 
		if(mid-j>(int)w[mod].size()) break;
		if(dp[now][j*mod+rest]+w[mod][mid-j-1]>dp[now^1][mid*mod+rest]){
			dp[now^1][mid*mod+rest]=dp[now][j*mod+rest]+w[mod][mid-j-1];
			pos=j;
		} 
	}
	divide(l,mid-1,x,pos,now,mod,rest);
	divide(mid+1,r,pos,y,now,mod,rest);
}

inline int cmp(int x,int y){
	return x>y;
}
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		w[x].push_back(y);
	} 
	for(int i=1;i<=maxw;i++){
		sort(w[i].begin(),w[i].end(),cmp);
		for(int j=1;j<(int)w[i].size();j++) w[i][j]+=w[i][j-1]; 
	}
	int now=0;
	for(int i=1;i<=300;i++){
		if(w[i].size()){
			for(int j=0;j<i;j++){
				//将模i同余的所有位置拿出来
				divide(0,(m-j)/i,0,(m-j)/i,now,i,j); 
			}
			for(int j=1;j<=m;j++){
				dp[now^1][j]=max(dp[now^1][j],dp[now^1][j-1]);
				//我们dp的子状态是体积<=j,而分治过程中是=j 
			}
			now^=1;
		}
	}
	for(int i=1;i<=m;i++) printf("%I64d ",dp[now][i]);
}

```





## 决策单调性的特殊解法: SMAWK算法 

### [NAIPC2016]Jewel Thief(法2)



### [UOJ 285]数据分块鸡(法2)

 