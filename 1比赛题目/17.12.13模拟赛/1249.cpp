#include<iostream>
#define maxn 10005
using namespace std;
int t,n;
int f[maxn];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cout<<2+3*n*(n-1)<<endl;
	}
}
