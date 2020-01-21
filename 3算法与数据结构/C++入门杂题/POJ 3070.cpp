#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 10000
using namespace std;
struct matrix{
	long long a[3][3];
	matrix(){
		memset(a,0,sizeof(a));
	}
	friend matrix operator * (matrix p,matrix q){
		matrix r;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				r.a[i][j]=0;
				for(int k=1;k<=2;k++){
					r.a[i][j]=(p.a[i][k]*q.a[k][j]+r.a[i][j])%mod;
				}
			}
		}
		return r;
	}
};
matrix fast_pow(matrix x,int k){
	matrix ans;
	for(int i=1;i<=2;i++) {
		for(int j=1;j<=2;j++){
			if(i==j) ans.a[i][i]=1;
			else ans.a[i][j]=0;
		}
	}
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

long long f(int n){
	if(n==0) return 0;
	matrix x;
	x.a[1][1]=1;
	x.a[1][2]=1;
	x.a[2][1]=1;
	x.a[2][2]=0;
	matrix ans=fast_pow(x,n-2);
	return (ans.a[1][1]+ans.a[1][2])%mod;
}
int main(){
	int n;
	while(scanf("%d",&n)){
		if(n==-1) break;
		else printf("%lld\n",f(n)); 
	}
} 
