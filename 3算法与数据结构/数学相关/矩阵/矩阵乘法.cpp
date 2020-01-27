#include<iostream>
#include<cstring>
#include<cstdio>
#define size 999
#define mod 1000000007
using namespace std;
long long n,k;
long long x[size][size];
long long tmp[size][size];
long long ans[size][size];
long long fastread() {
	long long x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
		if(c=='-') sign=-1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void multi_ans() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			tmp[i][j]=ans[i][j];
			ans[i][j]=0;
		}
	}
	for(int m=0; m<n; m++) {
		for(int s=0; s<n; s++) {
			for(int q=0; q<n; q++) {
				ans[m][s]=(ans[m][s]+x[m][q]*tmp[q][s]%mod)%mod;
			}
		}
	}
}
void multi_x() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			tmp[i][j]=x[i][j];
			x[i][j]=0;
		}
	}
	for(int m=0; m<n; m++) {
		for(int s=0; s<n; s++) {
			for(int q=0; q<n; q++) {
				x[m][s]=(x[m][s]+tmp[m][q]*tmp[q][s]%mod)%mod;
			}
		}
	}
}
void fast_pow(long long k) {
	while(k!=0) {
		if(k%2==1) multi_ans();
		k/=2;
		multi_x();
	}
}
int main() {
	n=fastread();
	k=fastread();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			x[i][j]=fastread();
		    ans[i][j]=x[i][j];
		}
	}
	fast_pow(k-1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			printf("%lld ",ans[i][j]);
		cout<<endl;
	}
}
