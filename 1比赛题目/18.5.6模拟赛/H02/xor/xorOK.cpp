//CF 691E
#include<iostream>
#include<cstdio>
#include<cstring> 
#define SIZE 105
#define maxn 105
using namespace std;
const long long mod=1000000007;
int n;
long long k;
long long num[maxn];
struct matrix {
	int n;
	int m;
	long long a[SIZE][SIZE];
	matrix() {
		n=2;
		m=2;
		memset(a,0,sizeof(a));
	}
	matrix(int x,int y) {
		n=x;
		m=y;
		memset(a,0,sizeof(a));
	}
	void print() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	void setv(int x) {
		if(x==0) {
			memset(a,0,sizeof(a));
		}
		if(x==1) {
			memset(a,0,sizeof(a));
			for(int i=1; i<=n; i++) a[i][i]=1;
		}
	}
	friend matrix operator *(matrix x,matrix y) {
		matrix tmp=matrix(x.n,y.m);
		for(int i=1; i<=x.n; i++) {
			for(int j=1; j<=y.m; j++) {
				tmp.a[i][j]=0;
				for(int k=1; k<=y.n; k++) {
					tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
				}
				tmp.a[i][j]%=mod;
			}
		}
		return tmp;
	}
};
matrix fast_pow(matrix x,long long k) {
	matrix ans=matrix(n,n);
	ans.setv(1);
	while(k>0) {
		if(k&1) {
			ans=ans*x;
		}
		k>>=1;
		x=x*x;
	}
	//ans.print();
	return ans;
}
long long count_1(long long x) {
	long long ans=0;
	while(x>0){
		if(x&1) ans++;
		x/=2;
	}
	return ans;
}
int main() {
	scanf("%d %I64d",&n,&k);
	for(int i=1; i<=n; i++) scanf("%I64d",&num[i]);
	matrix xor_mat=matrix(n,n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(count_1(num[i]^num[j])%3==0 )xor_mat.a[i][j]=1;
			else xor_mat.a[i][j]=0;
		}
	}
//	freopen("mat1.txt","w",stdout);
//	xor_mat.print();
	xor_mat=fast_pow(xor_mat,k-1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=ans+xor_mat.a[i][j];
		}
		ans%=mod;
	}
	printf("%I64d\n",ans);
}
