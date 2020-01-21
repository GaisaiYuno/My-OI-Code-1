//洛谷 不等数列 
#include<iostream>
#define maxn 1001
#define mod 2015
using namespace std;
int f[maxn][maxn]; 
int n,k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) f[i][0]=f[i][i-1]=1;
	 //f[1][0]=1; 
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
		   f[i][j]=max(f[i][j],f[i-1][j-1]*(i-j)+f[i-1][j]*(j+1))%mod;
	}
	cout<<f[n][k];
} 
/*递推公式
f[i][j]表示前i个数中有j个小于号
插入数x大于原来所有数 
若原来为>号 5 4>3 2 1 ---->5 4<x>3 2 1  多一个<号
     有i-1-j个>号，故*(i-j-1)
若原来为<号 1 2 3<4 5----->1 2 3<x>4>5   多一个<号
     有j个<号，故*(i-j-1)
但放在头尾也会多出一个<
如 5 4 3 2 1<x 或x>5 4 3 2 1,所以再+1 
f[i][j]=max(f[i][j],f[i-1][j-1]*(i-j)+f[i-1][j]*(j+1));
*/ 
