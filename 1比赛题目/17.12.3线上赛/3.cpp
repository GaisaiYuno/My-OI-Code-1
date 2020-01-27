#include<iostream>
#include<cstring>
#include<cstdio>
#define size 2
#define mod 1000000007
using namespace std;
long long m[size][size]= {{1,0},{0,1}};//初始化为1
long long N,M;
long long ans;
void multi_m(long long x[size][size],long long y[size][size],long long ans[size][size]) {
	long long tmp[size][size];
	for(int m=0; m<size; m++) {
		for(int s=0; s<size; s++) {
			tmp[m][s]=0;
			for(int n=0; n<size; n++) {
				tmp[m][s]=(tmp[m][s]+x[m][n]*y[n][s])%mod;
			}
		}
	}
	//print(tmp);
	for(int m=0; m<size; m++) {
		for(int s=0; s<size; s++) ans[m][s]=tmp[m][s]%mod;
	}
}
long long fast_pow(long long p) {//快速幂
    m[0][0]=1;
    m[0][1]=0;
    m[1][0]=0;
    m[1][1]=1;
	long long t[size][size]= {{1,1},{1,0}};
	while(p>0) {
		if(p%2==1) {
			multi_m(m,t,m) ;
		}
		p/=2;
		multi_m(t,t,t);
	}
	return (m[0][0]+m[0][1])%mod;
}
int main() {
	cin>>N>>M;
	//cout<<fast_pow(N)<<endl;
	//cout<<fast_pow(M+1)<<endl;
	ans=fast_pow(M+1)-fast_pow(N);
	while(ans>=mod)	ans-=mod;
	while(ans<0)	ans+=mod;
	cout<<ans;
	return 0;
}
