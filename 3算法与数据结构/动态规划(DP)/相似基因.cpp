//洛谷 相似基因
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1001
#define MIN -100000
using namespace std;
int n1,n2;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn];
int f[maxn][maxn];
int p[6][6]={
    {0, 0, 0, 0, 0, 0},
    {0, 5,-1,-2,-1,-3},
    {0,-1, 5,-3,-2,-4},
    {0,-2,-3, 5,-2,-2},
    {0,-1,-2,-2, 5,-1},
    {0,-3,-4,-2,-1, 0}
};
int change(char x){
	if(x=='A') return 1;
    if(x=='C') return 2;
    if(x=='G') return 3;
    return 4;

}
int main(){
	int i,j;
	scanf("%d%s%d%s",&n1,s1+1,&n2,s2+1);
	for(i=1;i<=n1;i++)
        for(j=1;j<=n2;j++) f[i][j]=MIN;
	for(i=1;i<=n1;i++) a[i]=change(s1[i]);
	for(i=1;i<=n2;i++) b[i]=change(s2[i]);
	for(i=1;i<=n1;i++)
        f[i][0]=f[i-1][0]+p[a[i]][5];
    for(i=1;i<=n2;i++)
        f[0][i]=f[0][i-1]+p[b[i]][5];
	for(i=1;i<=n1;i++)
        for(j=1;j<=n2;j++)
        {
            f[i][j]=max(f[i][j],f[i][j-1]+p[b[j]][5]);
            f[i][j]=max(f[i][j],f[i-1][j]+p[a[i]][5]);
            f[i][j]=max(f[i][j],f[i-1][j-1]+p[a[i]][b[j]]);
        }
    cout<<f[n1][n2];
    return 0;
}

/*状态转移方程 
dp[i][j]=max(dp[i][j],dp[i-1][j]+(s1与空字符的匹配值),
              dp[i][j-1]+(s2与空字符的匹配值),
			  dp[i-1][j-1]+(s1与s2的匹配值))
*/
