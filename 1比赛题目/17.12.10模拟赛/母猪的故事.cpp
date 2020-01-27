//HDU 2160
#include<iostream>
#define maxn 25
using namespace std;
int t,x;
int f[maxn];
int main(){
	f[1]=1;
	f[2]=2;
	for(int i=3;i<maxn;i++){
		f[i]=f[i-1]+f[i-2];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x;
		cout<<f[x]<<endl;
	}
	return 0;
	
}
