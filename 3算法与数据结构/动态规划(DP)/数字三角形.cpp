//洛谷 数字三角形 1216
#include<iostream>
#define maxn 1005
using namespace std;
int r;
int a[maxn][maxn];
long long f[maxn][maxn];
int main(){
	cin>>r;
	for(int k=1;k<=r;k++) {
		for(int u=1;u<=k;u++){
			cin>>a[k][u];
		}
	}
	for(int i=r;i>=1;i--){
		for(int j=1;j<=i;j++){
			f[i][j]=a[i][j]+max(f[i+1][j],f[i+1][j+1]); 
		}
	}
    cout<<f[1][1];
} 
/* 状态转移方程：
   f(i,j)=a(i,j)+max(f(i+1,j)，f(i+1,j+1 ))
*/
