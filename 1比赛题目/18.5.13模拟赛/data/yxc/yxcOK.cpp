//dp[i][j]=max(dp[i-1][x]+num[i+1][j] ) k-1<=i<=n 
//对于位置i,统计上一个数出现位置last[i] 
//用线段树区间更新  [i,last[i]] +1  叶子dp[i-1][j]建树 
//对于dp[i-1][[i]  维护{k,j] 

