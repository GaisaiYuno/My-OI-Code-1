
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
#define maxn 1000005
using namespace std;
inline long long addm(long long x) {
	return x>=mod?x-mod:x;
}
struct matrix {
	long long a[3][3];
	friend matrix operator * (matrix p,matrix q) {
		matrix ans;
		ans.a[1][1]=addm(p.a[1][1]*q.a[1][1]%mod+p.a[1][2]*q.a[2][1]%mod);
		ans.a[1][2]=addm(p.a[1][1]*q.a[1][2]%mod+p.a[1][2]*q.a[2][2]%mod);
		ans.a[2][1]=addm(p.a[2][1]*q.a[1][1]%mod+p.a[2][2]*q.a[2][1]%mod);
		ans.a[2][2]=addm(p.a[2][1]*q.a[1][2]%mod+p.a[2][2]*q.a[2][2]%mod);
		return ans;
	}
	void print(){
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
};

inline matrix fast_pow(matrix x,long long k) {
	matrix ans;
	ans.a[1][1]=1;
	ans.a[2][2]=1;
	ans.a[1][2]=0;
	ans.a[2][1]=0;
	while(k) {
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

inline matrix fast_pow(matrix x,char* k) {
	int len=strlen(k+1);
	matrix ans;
	ans.a[1][1]=1;
	ans.a[2][2]=1;
	ans.a[1][2]=0;
	ans.a[2][1]=0;
	for(int i=len; i>=1; i--) {
		ans=ans*fast_pow(x,k[i]-'0');
		x=fast_pow(x,10);
	}
	return ans;
}

char N[maxn],M[maxn];
long long a,b,c,d;

matrix A,B,T;
int main() {
	scanf("%s %s",N+1,M+1);
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	int nl=strlen(N+1);
	int ml=strlen(M+1);
	for(int i=nl;i>=1;i--){ 
		if(N[i]=='0') N[i]='9';
		else {
			N[i]--;
			break;
		}
	} 
	for(int i=ml;i>=1;i--){ 
		if(M[i]=='0') M[i]='9';
		else {
			M[i]--;
			break;
		}
	} 
	A.a[1][1]=a;
	A.a[1][2]=0;
	A.a[2][1]=b;
	A.a[2][2]=1;
	B.a[1][1]=c;
	B.a[1][2]=0;
	B.a[2][1]=d;
	B.a[2][2]=1;
	T.a[1][1]=1;
	T.a[1][2]=1;
	T.a[2][1]=0;
	T.a[2][2]=0;
	A=fast_pow(A,M);
//	A.print();
//	matrix tmp=A*B;
//	tmp.print();
//	tmp=fast_pow(A*B,N);
//	tmp.print();
	T=T*fast_pow(A*B,N)*A;
	printf("%lld\n",T.a[1][1]);
}

