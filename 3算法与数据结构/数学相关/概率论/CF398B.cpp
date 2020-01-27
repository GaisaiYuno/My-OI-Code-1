#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#define maxn 2000
using namespace std;
//dp[x][y]表示还剩x行y列需要染色时，期望达到目标状态的步数
//dp[x][y]=(x*y*dp[x-1][y-1]+x*(n-y)*dp[x-1][y]+y*(n-x)*dp[x][y-1]+dp[x][y]*(n-x)(n-y))/(n*n)
//dp[0][0]=0
//从dp[0][0]推到dp[r][c],r,c为还有多少行没染
int n,m;
double dp[maxn+5][maxn+5];
set<int>row,col;
int r,c; 
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		row.insert(x);
		col.insert(y);
	}
	r=n-row.size();
	c=n-col.size();
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0]+(double)n/i;
		dp[0][i]=dp[0][i-1]+(double)n/i;
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			dp[i][j]=(n*n+i*j*dp[i-1][j-1]+i*(n-j)*dp[i-1][j]+(n-i)*j*dp[i][j-1])/(n*n-(n-i)*(n-j)); 
		}
	}
	printf("%.10f\n",dp[r][c]);
}

