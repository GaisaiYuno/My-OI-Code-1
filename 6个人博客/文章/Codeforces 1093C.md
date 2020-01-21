### 题面

[传送门](https://codeforces.com/contest/1093/problem/C)

题目大意：

有一个长n(n为偶数)的序列a

已知a满足 $a_1≤a_2≤⋯≤a_n$

给出一个长度为$\frac{n}{2}$ 的序列b，定义$b_i=a_i+a_{n-i+1}$

求出序列a (输出任意一种答案即可)

### 分析

为了保证序列不下降，我们采用贪心的思想，先假设$a_i=a_{i-1}$,这样给后面的数留有的余地更大

然后计算出$a_{n-i+1}=b_i-a_i$，如果$a_{n-i+1}>a_{n-i+1+1}$,即不满足不下降的条件，则进行局部调整

令$a_{n-i+1}=a_{n-i+1+1}$，重新计算$a_i=b_i-a_{n-i+1}$ (注，设$a_{n+1}=+\infin $)

由于$a_{n-i+1}>a_{n-i+2}$，新的$a_i$的值会变大，依然满足不下降的条件

该方法的正确性显然，时间复杂度$O(n)$

### 代码

```c++
#include<iostream>
#include<cstdio>
#define maxn 200005
#define INF 0x7fffffffffffffff
using namespace std;
int n;
long long a[maxn];
long long b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++) scanf("%I64d",&b[i]);
	a[n+1]=INF; 
	for(int i=1;i<=n/2;i++){
		a[i]=a[i-1];
		a[n+1-i]=b[i]-a[i];
		if(a[n+2-i]<a[n+1-i]){
			a[n+1-i]=a[n+2-i];
			a[i]=b[i]-a[n+1-i];
		}
	}	
	for(int i=1;i<=n;i++){
		printf("%I64d ",a[i]);
	}
}
```

