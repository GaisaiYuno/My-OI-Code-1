//ball
#include<iostream>
#define maxm 35
using namespace std;
long long int n,m;
int f[maxm][maxm];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	f[1][0]=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++)
		  f[i][j]=f[(i-1+n-1)%n+1][j-1]+f[i%n+1][j-1];
	}
	cout<<f[1][m];
	return 0;
} 
/*状态转移方程 
f[i][j]=f[i-1][j-1]+f[i+1][j-1]（f[i][j]球经过j次到第i个人方案数）
*/
