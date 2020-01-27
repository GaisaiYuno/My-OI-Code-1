//flower
#include<iostream>
#include<cstdio>
#define maxn 101
using namespace std;
long long ans=0;
int n,m; 
int a[maxn];
int f[maxn]; 
//bool f[maxn][maxn];
/*状态转移方程
  dp[i]=(dp[i-1]+dp[i-2]+...+dp[i-a[j]])
*/ 
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
    f[0]=1;  
    for(int i=1; i<=n;i++) 
        for(int j=m;j>=1;j--)  
            for(int k=1;k<=a[i]&&j-k>=0;k++) 
                f[j]=(f[j-k]+f[j]) % 1000007; 
    cout<<f[m];//输出
    return 0;
}
 
