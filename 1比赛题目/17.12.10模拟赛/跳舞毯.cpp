//HDU 2154
#include<iostream>
#define maxn 1005
#define mod 10000
using namespace std;
int n;
long long f[maxn][4];
int main(){
	f[1][1]=1;
	f[1][2]=0;
	f[1][3]=0;
	for(int i=2;i<maxn;i++){
		f[i][1]=(f[i-1][2]+f[i-1][3])%mod;
		f[i][2]=(f[i-1][1]+f[i-1][3])%mod;
		f[i][3]=(f[i-1][1]+f[i-1][2])%mod;
	}
	while(cin>>n&&n!=0){
		cout<<f[n+1][1]<<endl;
	}
}
