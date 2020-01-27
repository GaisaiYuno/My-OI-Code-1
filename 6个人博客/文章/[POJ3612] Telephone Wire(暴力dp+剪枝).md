## [POJ3612] Telephone Wire(暴力dp+剪枝)

### 题面

有N根电线杆，初始高度为h[i],要给相邻的两根连线。可以选择拔高其中一部分电线杆，把一根电线杆拔高$\Delta H$的代价为$\Delta H^2$。拔高后，要给相邻的电线杆连线，连线相邻两根电线杆操作的代价为$C\Delta H$，其中C是一个常量且已经给出。求最小总代价。

### 分析

考虑一个显然的dp,设$dp[i][j]$表示前i根电线杆，第i根拔到高度j的最小代价,记H表示max(h[i])

则$dp[i][j]=min(dp[i][j],dp[i-1][k]+C \times |j-k|+(j-h[i])^2),k \in [h[i-1],H)$ 。这里k的意义是第i-1根电线杆的高度

直接转移是$O(nH^2)$的，但有一个很强的剪枝可以通过本题

若我们固定i,j,考虑k对$dp[i-1][k]+C \times |j-k|+(j-h[i])^2$的影响，k对$dp[i-1][k]$造成了$(k-h[i-1])^2$的影响，又造成了$C \times |j-k|$的影响，总的影响应该是一个关于k的二次函数。而我们知道二次函数是有对称性和单调性的。我们从小到大枚举k，若$dp[i-1][k]+C \times |j-k|+(j-h[i])^2>dp[i][j]$,说明k已经大于那个二次函数的对称轴了，之后的函数值只会更大，这个时候就可以停止枚举k

### 代码

```cpp
//暴力出奇迹 
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define rg register
#define maxn 100000
#define maxh 100
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

int n,c,lim;
int h[maxn+5]; 
int dp[maxn+5][maxh+5];
inline int abs(int x){
	return x>=0?x:-x; 
} 
inline int min(int x,int y){
	return x<=y?x:y; 
}
int main(){
	qread(n);
	qread(c);
	lim=0;
	for(rg int i=1;i<=n;i++){
		qread(h[i]);
		lim=max(lim,h[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	for(rg int j=h[1];j<=lim;j++){
		dp[1][j]=(j-h[1])*(j-h[1]);
	}
	for(rg int i=2;i<=n;i++){
		for(rg int j=h[i];j<=lim;j++){//注意不用从0开始 
			int last=INF;
			for(rg int k=h[i-1];k<=lim;k++){
				int now=dp[i-1][k]+c*abs(j-k)+(j-h[i])*(j-h[i]);
				if(dp[i][j]>now) dp[i][j]=now;
				if(now>last) break;//由于代价是二次函数，找到最小值点就不用再找了 
								   //这是很强的一个优化 
				last=now;
			}
		}
	}
	int ans=INF;
	for(rg int i=h[n];i<=lim;i++) ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
}

```



 