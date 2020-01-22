#include<iostream>
#include<cstdio>
#define maxn 505
using namespace std;
long long f[maxn][maxn],E;
int n,a[maxn];
int main() {
    cin>>n; 
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
		a[n+i]=a[i];//循环 
	}
	for(int i=2;i<=n+1;i++) {
		for(int j=1;i+j-1<=2*n;j++) {
			for(int k=j+1;k<i+j-1;k++){ 
				if(f[j][i+j-1]<f[j][k]+f[k][i+j-1]+a[j]*a[k]*a[i+j-1])
				   f[j][i+j-1]=f[j][k]+f[k][i+j-1]+a[j]*a[k]*a[i+j-1];
				   if(E<f[i][i+n]) E=f[i][i+n];
			} 
		}
	}
	cout<<E;
	return 0;
}
/*状态转移方程
f[l][r]表示[a[l],a[r]]最大值，
有f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[k]*a[r]) k属于[i,j]
*/ 
