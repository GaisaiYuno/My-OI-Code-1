//洛谷  斐波那契数列 
//O(log2n) 
#include<iostream>
#include<cstring>
#include<cstdio>
#define size 2
#define mod 1000000007
using namespace std;
long long m[size][size]= {{1,0},{0,1}};//初始化为1 
long long n;
void print(long long x[size][size]){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++) cout<<x[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
void multi_m(long long x[size][size],long long y[size][size],long long ans[size][size]){
	long long tmp[size][size];
	for(int m=0;m<size;m++){  
        for(int s=0;s<size;s++){  
           tmp[m][s]=0;
            for(int n=0;n<size;n++){  
                tmp[m][s]=(tmp[m][s]+x[m][n]*y[n][s])%mod;  
            }
        }                
    }
	for(int m=0;m<size;m++){
		for(int s=0;s<size;s++) ans[m][s]=tmp[m][s]%mod;
	}
}
void fast_pow(long long p) {//快速幂 
	long long t[size][size]= {{1,1},{1,0}};
	while(p>0) {
		if(p%2==1) {
			multi_m(m,t,m) ;
		}
		p/=2;
		multi_m(t,t,t);
		//print(m);
	}
}
int main() {
	cin>>n;
	fast_pow(n-2);
	cout<<(m[0][0]+m[0][1])%mod<<endl;
	print(m); 
}
