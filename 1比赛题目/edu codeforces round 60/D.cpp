#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxm 105
#define mod 1000000007
using namespace std;
long long n;
int m;
struct matrix{
	long long v[maxm][maxm];
	matrix(){
		memset(v,0,sizeof(v)); 
	}
	friend matrix operator * (matrix a,matrix b){
		matrix c;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				c.v[i][j]=0;
				for(int k=1;k<=m;k++){
					c.v[i][j]+=a.v[i][k]*b.v[k][j]%mod;
					c.v[i][j]%=mod;
				}
			}
		}
		return c;
	}
};
matrix fast_pow(matrix x,long long k){
	matrix ans;
	for(int i=1;i<=m;i++) ans.v[i][i]=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
int main(){
	scanf("%I64d %d",&n,&m);

	matrix T,A;
	for(int i=1;i<=m;i++){
		T.v[1][i]=1;
	}
	A.v[1][1]=A.v[1][m]=1;
	for(int i=2;i<=m;i++){
		A.v[i][i-1]=1;
	}
	T=fast_pow(A,n)*T;
	printf("%I64d\n",T.v[1][1]);
}

