## [TJOI2018]游园会(状压dp+LCS)

### 题面

小豆参加了 NOI 的游园会，会场上每完成一个项目就会获得一个奖章，奖章只会是 N, O, I 的字样。
在会场上他收集到了K个奖章组成的串。兑奖规则是奖章串和兑奖串的最长公共子序列长度为小豆最后奖励的等级。
现在已知兑奖串长度为 N ，并且在兑奖串上不会出现连续三个奖章为 `NOI` ，即奖章中不会出现子串 `NOI` 。
现在小豆想知道各个奖励等级会对应多少个不同的合法兑奖串。

###　分析

声明:为了避免变量重复，我们将题面中的K用m代替。记奖章串为a串，兑奖串为b串.NOI三个字符分别用数字0,1,2代替

容易想到计数dp,设$dp[i][j]$表示长度为$i$,与$b$串的LCS为$j$的合法a串数量。但是只有LCS长度我们无法转移。考虑求LCS的过程

$lcs[i][j]=\max(lcs[i][j-1],lcs[i-1][j],(lcs[i-1][j-1]+1)[a_i=b_j])$

由于b串是固定的,那么a串第i个位置的字符确定了,转移后$lcs[i]$也确定了。而根据$lcs[i]$,我们可以求出当前的lcs长度$\max_{j \in [1,m]}(lcs[i][j])$.那么,我们就可以用$lcs[i]$来作为计数dp的子状态。而容易发现$lcs[i]$是单调递增的一个序列，且元素之间最多相差1.于是我们不用记录$lcs[i]$,而是记录$lcs[i]$的差分.把每个数加起来就得到了真正的LCS.因为$m \leq 15$,所以可以状压。

根据前面的讨论，我们可以在dp之前预处理出$sta[s][c]$表示s状态的LCS,加上确定的字符c转移后的状态。容易发现s的二进制里1的个数就是LCS长度。

注意到还有不能出现NOI的限制,再记录一维表示当前串末尾与NOI匹配的位数。

综上，子状态$dp[i][s][j]$表示长度为$i$,$lcs[i]$的差分为$s$, 末尾与NOI匹配的位数为$j$的a串个数。

那么我们可以写出转移方程:

$dp[i+1][sta[s][k]][match[j][k]]+=dp[i][s][j] (k\in \{0,1,2 \},j和k不同时为2)$

其中$match[j][k]$表示末尾与NOI匹配的位数为$j$时，加上k字符后的匹配位数。直接手玩一下再打个表就可以了。实现上注意第一位要滚动数组。

时间复杂度$O(n 2^m)$

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 1000
#define maxm 15
#define maxs 32768
using namespace std;
typedef long long ll; 
int n,m;
const char noi[]="NOI"; 
char str[maxn+5];
int b[maxn+5];
int sta[maxs+5][3];

void ini() {
	static int f[maxn+5]; //相当于dp[i-1]
	static int g[maxn+5];//相当于dp[i]
	for(int s=0; s<(1<<m); s++) {
		//s表示dp[i-1]的差分，要加起来才能得到dp[i-1]
		for(int j=0; j<m; j++) f[j+1]=f[j]+(s>>j&1);
		for(int k=0; k<=2; k++) { //枚举a[i]的值
			for(int j=1; j<=m; j++) {
				g[j]=max(g[j-1],f[j]);//dp[i][j]=max(dp[i][j-1],dp[i-1][j])
				if(str[j]==noi[k]) g[j]=max(g[j],f[j-1]+1);//dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1) (a[i]==b[j])
			}
			int t=0;
			for(int j=1; j<=m; j++) {
				if(g[j]-g[j-1]>0) t|=(1<<(j-1));//再把dp[i]差分
			}
			sta[s][k]=t;//当a[i]=k时,dp状态会由s变成t
//			printf("trans[%d][%d]=%d\n",s,k,sta[s][k]); 
		}

	}
}

const int match[3][3]={{1,0,0},{1,2,0},{1,0,3}};
//match[i][j]表示原本末尾与匹配了i位,加上字符noi[j]之后末尾匹配的位数 
inline int count_1(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

ll ans[maxm+5];
ll dp[2][maxs+5][3];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",str+1);

	ini();
	int now=0;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		memset(dp[now^1],0,sizeof(dp[now^1]));
		for(int s=0;s<(1<<m);s++){//lcs数组状态 
			for(int j=0;j<=2;j++){//匹配了"NOI"几位 
				for(int k=0;k<=2;k++){//当前字符 
					if(j==2&&k==2) continue;//出现"NOI" 
					int newj=match[j][k]; //计算新的与"NOI"的匹配位数 
					dp[now^1][sta[s][k]][newj]+=dp[now][s][j];
					dp[now^1][sta[s][k]][newj]%=mod;
				}
			}
		}
		now^=1;
	}
	for(int s=0;s<(1<<m);s++){
		for(int j=0;j<=2;j++){
			int lis=count_1(s); //lis长度dp[i][j]就是差分数组里1的个数 
			ans[lis]+=dp[now][s][j];
			ans[lis]%=mod;
		}
	}
	for(int i=0;i<=m;i++) printf("%lld\n",ans[i]);
}
```

