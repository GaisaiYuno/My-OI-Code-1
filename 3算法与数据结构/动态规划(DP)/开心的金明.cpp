//洛谷 开心的金明 1060
#include<iostream>
using namespace std;
long long  v[100000],w[100000];
long long f[100000];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>v[i]>>w[i];
		w[i]=w[i]*v[i];
	}
	for(int j=0;j<m;j++){
		for(int k=n;k>=v[j];k--){
			if(f[k-v[j]]+w[j]>f[k])
			 f[k]=f[k-v[j]]+w[j];
		}
	}
	cout<<f[n];
	return 0;
} 
