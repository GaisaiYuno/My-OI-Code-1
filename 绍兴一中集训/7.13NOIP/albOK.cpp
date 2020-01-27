/*
https://www.luogu.org/problemnew/show/U76944
考虑序列第i位的二进制表示与下标i的关系
观察样例：
下标: 00 01 10 11
序列：01 00 11 12
我们发现，当i=2的时候，i的第1位是1，p[i]由0变成了1， 
    总结一下：i的二进制表示从低到高的第1个1的位置记为tmp（lowbit）,则我们要取反第tmp位，否则与上一个数第k位相同
    而比tmp位高的数字不变

设dp[pos][now]表示当前处理到序列第k个位置，p[pos-1]=now时的最小
先找出tmp， 把now的tmp位取反，而0~tmp-1位可任取，继续转移到下一个数nex
dp[pos][now]=min(dp[pos][now],dp[pos+1][nex]+dist(pos+1,nex) 
用记忆化搜索实现，
枚举n O(n), 枚举0~tmp-1位O(2^{k-1})，找tmp O(k) 
时间复杂度O(n*2^{k-1}*k)=O(n^2logn) 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000
#define INF 0x3f3f3f3f
using namespace std;
int n,k;
int w[maxn+5][maxn+5],dp[maxn+5][maxn+5];
int dfs(int pos,int now){
    if(pos==n) return 0;
    if(dp[pos][now]!=INF) return dp[pos][now];
    int tmp=0,bin=pos;
    while(tmp<k&&(bin&1)==0){
        tmp++;
        bin>>=1;
    }//注意，如果pos=0,tmp=k 
    int all=(1<<tmp); //这里的tmp实际上是上面的tmp-1 ，这样可以方便处理tmp=1的边界情况 
    int nex=now^all;
    nex=nex>>(tmp)<<(tmp);//左移过去再左移回来，把0~tmp-1清0
    dp[pos][now]=INF;
    for(int i=0;i<all;i++){
        dp[pos][now]=min(dp[pos][now],w[now][nex+i]+dfs(pos+1,nex+i));
    } 
    return dp[pos][now];
}

int main(){
    scanf("%d",&k);
    n=(1<<k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    printf("%d\n",dfs(0,n));
}
