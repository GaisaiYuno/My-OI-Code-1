### 题面

[传送门](http://codeforces.com/problemset/problem/989/C)

真是令人胃疼的题面

我不管，我要把苹果都给雪菜！（滑稽）(冬马党不要打我)

### 分析

突然感觉这题跟今年NOIP Day1T2有点像，都是根据数加减来构造背包，只不过这题是01背包而不是完全背包

背包模型：

设总和为sum,则容量为sum/2

其实本题不需要代价,dp[j]为1表示容量为j时能装满，否则不能

直接 dp[j]=dp[j-a[i]] (dp[j-a[i]]>0)即可

### 代码

```cpp
#include<iostream>
#include<cstdio>
#define maxn 105
using namespace std;
int n;
int a[maxn];
int dp[maxn*2];
int main(){
    scanf("%d",&n);
    dp[0]=1;
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]/=100;
        sum+=a[i];
    }
    if(sum%2==1){
        printf("NO\n");
    }else{
        for(int i=1;i<=n;i++){
            for(int j=n*2;j>=0;j--){
                if(dp[j]) dp[j+a[i]]=1;
            }
        }
        if(dp[sum/2]) printf("YES\n");
        else printf("NO\n");
    }
}
```



