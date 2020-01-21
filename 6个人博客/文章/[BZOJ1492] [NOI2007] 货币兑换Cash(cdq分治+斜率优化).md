## [BZOJ1492] [NOI2007] 货币兑换Cash(cdq分治+斜率优化)

### 题面

![](http://www.lydsy.com/JudgeOnline/images/1492_1.jpg)

### 分析

#### dp方程推导

显然，必然存在一种最优的买卖方案满足：每次买进操作使用完所有的人民币；每次卖出操作卖出所有的金券.

设dp[i]表示第i天卖出所有金券的能够得到的钱数。则有：

$$dp[i]=max(dp[i-1],\frac{dp[j]}{A[j] \times R[j]+B[j] } \times (A[i] \times R[j]+B[i])） （0 \leq j < i)$$

意义是第j天按R[j]的比例用所有钱买入股票，然后在第i天全部卖出，比例仍为R[j]

去掉max，把i,j分开移项，得

$$dp[i]=\frac{dp[j]}{A[j] \times R[j]+B[j] } \times B[i]+\frac{dp[j] \times R[j]}{A[j] \times R[j]+B[j] } \times A[i]$$

令$x[j]=\frac{dp[j]}{A[j] \times R[j]+B[j] }$,$y[j]=\frac{dp[j] \times R[j]}{A[j] \times R[j]+B[j] }$

那么状态转移方程就变成了$dp[i]=x[j] \times B[i]+y[j] \times A[i]$

变换成直线方程的形式，y[j]前面有个系数A[i],把它除掉，得

$$y[j]=-\frac{B[i]}{A[i]} \times x[j]+dp[i]$$

因此用斜率为$-\frac{B[i]}{A[i]}$的直线经过点$(x[j],y[j])$，解出的最小截距就是$dp[i]$的值。注意到$-\frac{B[i]}{A[i]}$和x[j]并不单调，不能用单调队列优化。考虑cdq分治求解



#### cdq 分治

cdq分治求解斜率优化其实类似一个三维偏序过程，第一维是点i对应的直线斜率(本题中是$-\frac{B[i]}{A[i]}$)，第二，三维是对应的点的下标

首先在cdq分治的时候需要维护一个数组a，记录a对应的dp值下标id,和它对应点的坐标。先把a按直线斜率排序，然后开始cdq分治。

当我们分治到区间[l,r]的时候，我们执行以下伪代码

```
procedure CDQ(l,r){
	if(l==r){
		用a[l]对应的dp值来更新a的(x,y)
		return
	}
	mid=(l+r)/2
	把[l,r]内的元素按id分成两个区间，id<=mid的分到[l,mid],否则分到[mid+1,r]
	CDQ(l,mid),先递归计算id值小的
	把[l,mid]区间对应的点建出凸壳，用于下一步更新[mid+1,r]的dp值
	for(k in [mid+1,r]){
		用单调队列更新a[k]对应的dp值，因为我们cdq之前按斜率排过序，所以不会出问题
		注意到在这里面即使a[k]对应的dp值的最优决策不在[mid+1,r]中，那么回溯到一个更大的区间后，也会被更新到
	}
	CDQ(mid+1,r)，继续递归下去更新
	按x,y归并排序[l,mid],[mid+1,r],这样回溯的时候x单调递增，才可以直接单调栈(队列)建凸壳
}

```

注意精度问题，以及斜率为$+ ∞$的情况

### 代码

```cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath> 
#define eps 1e-8
#define INF 1e18
#define maxn 100000
using namespace std;
typedef long long ll; 
typedef double db;
int n;
db S;
db A[maxn+5],B[maxn+5],R[maxn+5];
struct Vector{
	int id;
	db x;
	db y;
	Vector(){
		
	}
	Vector(int _id,db _x,db _y){
		id=_id; 
		x=_x;
		y=_y;
	}
}a[maxn+5];
typedef Vector point;
db slope(point p,point q){
	db down=p.x-q.x;
	db up=p.y-q.y;
	if(fabsl(down)<=eps) return INF;
	else return up/down;
}

int cmp1(point p,point q){
	db k1=(fabs(A[p.id])>eps)?-B[p.id]/A[p.id]:INF;
	db k2=(fabs(A[q.id])>eps)?-B[q.id]/A[q.id]:INF;
	return k1<k2;//按斜率排序，保证斜率单调	
}
int cmp2(point p,point q){//按x,y归并排序 
	if(p.x==q.x) return p.y<q.y;
	else return p.x<q.x;
}

int head,tail;
point q[maxn+5];
point tmp[maxn+5];
db dp[maxn+5];

db get_x(int j){
	return dp[j]/(A[j]*R[j]+B[j]);
}
db get_y(int j){
	return dp[j]*R[j]/(A[j]*R[j]+B[j]);
}
void cdq_divide(int l,int r){
	if(l==r){
		dp[a[l].id]=max(dp[a[l].id],dp[a[l].id-1]);
		a[l].x=get_x(a[l].id);
		a[l].y=get_y(a[l].id);
		return; 
	}
	int mid=(l+r)>>1;
	int pl=l,pr=mid+1;
	for(int i=l;i<=r;i++){
		if(a[i].id<=mid) tmp[pl++]=a[i];
		else tmp[pr++]=a[i];	
	} 
	for(int i=l;i<=r;i++) a[i]=tmp[i];
	
	cdq_divide(l,mid);
	head=1,tail=0;
	for(int i=l;i<=mid;i++){
		while(head<tail&&slope(q[tail-1],q[tail])<=slope(q[tail-1],a[i])) tail--;
		q[++tail]=a[i];
	} 
	
	for(int k=r;k>mid;k--){
		int i=a[k].id;
		db s2=(fabs(A[i])>eps)?-B[i]/A[i]:INF;
		while(head<tail&&slope(q[head],q[head+1])>=s2) head++;
		int j=q[head].id;
		dp[i]=max(dp[i],A[i]*get_y(j)+B[i]*get_x(j));
//		dp[i]=max(dp[i],dp[i-1]);
	}
	cdq_divide(mid+1,r);
	
	int num=l-1;
	pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r){//按x,y归并排序 
		if(cmp2(a[pl],a[pr])) tmp[++num]=a[pl++];
		else tmp[++num]=a[pr++];
	}  
	while(pl<=mid) tmp[++num]=a[pl++];
	while(pr<=r) tmp[++num]=a[pr++];
	for(int i=l;i<=r;i++) a[i]=tmp[i];
}

int main(){
	// freopen("5.in","r",stdin); 
	scanf("%d %lf",&n,&S);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf %lf",&A[i],&B[i],&R[i]);
	}
	dp[0]=S;
	for(int i=0;i<=n;i++){
		a[i].id=i; 
	}
	sort(a,a+1+n,cmp1);
	cdq_divide(0,n);
	printf("%.3lf\n",dp[n]); 
} 
```







