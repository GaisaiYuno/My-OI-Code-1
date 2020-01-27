//折线分平面 
//递推类型2 
#include<iostream>
#define maxn 10000
using namespace std;
int n,t;
int f[maxn];
int main() {
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n;
		f[1]=2;
		for(int j=2;j<=n;j++){
			f[n]=f[n-1]+4*(n-1)+1;
		}
		cout<<f[n]<<endl;
	}
}
/*
   f[n]=f[n-1]+4(n-1)+1
*/

