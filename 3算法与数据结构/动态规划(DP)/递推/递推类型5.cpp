/*在一个2*n的长方形方格中，铺满1*2的骨牌，给定n,求方案数*/ 
#include<iostream>
#define maxn 100
using namespace std;
long long f[maxn];
int n; 
int main(){
	cin>>n;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++) f[i]=f[i-1]+f[i-2];
	cout<<f[n];
}
