## [HDU 3625]Examining the Rooms (第一类斯特林数)

###　题面

有n个房间，每个房间有一个钥匙，钥匙等概率的出现在n个房间内，每个房间中只会出现且仅出现一个钥匙。你能炸开门k次，问你能进入所有房间的概率。特殊要求：不能炸1号房间的门。

T组询问

T<=2000,k<=n<=2000

### 分析

#### 前置知识（如果你了解斯特林数，可以跳过）

圆排列：把n个元素排在一个圆周上，如果旋转之后两个圆周上的排列一样，那么这两个排列相同

第一类斯特林数S(n,m)表示把n个不同元素构成m个圆排列的方案数

由定义得S(n,0)=0,S(n,n)=1

第一类斯特林数有递推公式$S(n,m)=S(n-1,m-1)+(n-1) \times S(n-1,m)$

证明：我们考虑把第n个元素放在什么位置。如果单独形成一个圆排列，则答案就是S(n-1,m-1).

如果插入到原来的m个圆排列中，那本质上就是在n-1个元素中选一个插到它后面去（定义“后面”为顺时针方向下一个数，定义为逆时针同理)，有n-1种选法，答案就是(n-1)S(n-1,m)

这样我们就可以$O(n^2)$处理出S的值（用NTT可以更快，但这题不需要)



#### 解答过程

第i个房间里的钥匙p[i]构成一个排列p,而通过打开某个房间的门拿到钥匙a,用钥匙a打开门，拿到钥匙b.....这样会构成许多个环。

那么问题就转化为n个元素组成<=k个环的排列数量。直接用第一类斯特林数的定义知$\sum_{i=1}^k S(n,i)$

不能炸一号门其实很简单，就是一号点不能单独为环 $S(n-1,i-1)$

$ans=\frac{1}{n!}\sum_{i=1}^k (S(n,i)-S(n-1,i-1))$



### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20
using namespace std;
typedef long long ll;
ll fact[maxn+5];
ll S[maxn+5][maxn+5];
void ini(int n){
	for(int i=0;i<=n;i++){
		S[i][0]=0;
		S[i][i]=1;
		for(int j=1;j<i;j++){
			S[i][j]=S[i-1][j-1]+(i-1)*S[i-1][j];
		}
	}
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
}

double calc(int n,int k){
	long long ans=0;
	for(int i=1;i<=k;i++){
		ans+=S[n][i]-S[n-1][i-1];
	}
	return 1.0*ans/fact[n];
}
int t,n,k;
int main(){
	ini(maxn);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		printf("%.4lf\n",calc(n,k));
	}
	
}
```





