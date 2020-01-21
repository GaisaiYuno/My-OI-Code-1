## [BZOJ1009] [HNOI2008] GT考试(KMP+dp+矩阵快速幂)

### 题面

 阿申准备报名参加GT考试，准考证号为N位数X1X2….Xn,他不希望准考证号上出现不吉利的数字。他的不吉利数学A1A2…Am有M位，不出现是指X1X2…Xn中没有恰好一段等于A1A2…Am. A1和X1可以为0 

$0 \leq X_i \leq 9,0\leq Ai\leq 9,m \leq 20,n \leq 10^9$

### 分析

先考虑暴力的思路,设$dp[i][j]$表示前i位数与不吉利数字匹配了前j位的方案数

那么$dp[i][f(j,c)]=\sum dp[i-1][j] (c \in[0,9])$

实际上就是从0~9枚举第i位的数字，然后更新匹配的位数。其中$f(j,c)$表示加入数字c后的匹配位数。

但是$n \leq 10^9$,直接dp显然会超时，发现每层转移都是一样的，所以可以矩阵快速幂优化

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000 
#define maxm 20
using namespace std;
typedef long long ll;
char t[maxm+5];
int nex[maxm+5];
void get_nex(char *a){
	int len=strlen(a+1);
	for(int i=2,j=0;i<=len;i++){
		while(j>0&&a[j+1]!=a[i]) j=nex[j];
		if(a[j+1]==a[i]) j++;
		nex[i]=j; 
	}
} 

int n,m,mod;
int match(int j,char c){
	while(j>0&&t[j+1]!=c) j=nex[j];
	if(t[j+1]==c) j++;
	return j;
}

struct matrix{
	ll x[maxn+5][maxn+5];
	void set(int p){
		if(p==0){
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) x[i][j]=0;
		}else{
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) x[i][j]=0;
			for(int i=0;i<m;i++) x[i][i]=1;
		}
	}
	void print(){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				printf("%lld ",x[i][j]);
			}
			printf("\n");
		}
	}
	friend matrix operator * (matrix a,matrix b){
		matrix ans;
		ans.set(0);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					ans.x[i][j]+=a.x[i][k]*b.x[k][j]%mod;
					ans.x[i][j]%=mod;
				}
			}
		}
		return ans;
	}
};
matrix fast_pow(matrix x,int k){
	matrix ans;
	ans.set(1);
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1; 
	}
	return ans;
}

int main(){
	scanf("%d %d %d",&n,&m,&mod);
	scanf("%s",t+1);
	get_nex(t);
//	dp[0][0]=1; 
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++){
//			for(char ch='0';ch<='9';ch++){
//				int k=match(j,ch);
//				dp[i][k]+=dp[i-1][j];
//				dp[i][k]%=mod;
//			}
//		}
//	}
	matrix tp,ans;
	tp.set(0);
	for(int j=0;j<m;j++){
		for(char ch='0';ch<='9';ch++){
			int k=match(j,ch);
			tp.x[j][k]++;
		}
	}
//	tp.print();
	ans=fast_pow(tp,n);
//	ans.print();
	ll res=0;
	for(int j=0;j<m;j++){
		res+=ans.x[0][j];
		res%=mod;
	}
	printf("%lld\n",res);
}
```



