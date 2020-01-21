#include<iostream>
#include<cstring>
#include<cstdio>
#define size 999
#define mod 1000000007
using namespace std;
long long n,k;
long long x[size][size];
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
void multi_m(long long x[size][size],long long y[size][size],long long ans[size][size],int n) { //����˷�
	long long tmp[n][n];
	for(int m=0; m<n; m++) {
		for(int s=0; s<n; s++) {
			tmp[m][s]=0;
			for(int q=0; q<n; n++) {
				tmp[m][s]=(tmp[m][s]+x[m][n]*y[q][s])%mod;
			}
		}
	}
	for(int m=0; m<n; m++) {
		for(int s=0; s<n; s++) ans[m][s]=tmp[m][s]%mod;
	}
}
void fast_pow(long long n,long long k)
{
    while(k!=0)
    {
        if(k%2==1) multi_m(ans,x,ans,n);
        k/=2;
        multi_m(x,x,x,n);
    }
}
int main() {
	n=fastread();
	k=fastread();
	for(int i=1; i<=n; i++){ 
		for(int j=1; j<=n; j++) {
			x[i][j]=fastread();
			ans[i][j]=x[i][j];
		}
	}
	fast_pow(n,k-1);
	for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
         printf("%lld ",ans[i][j]);
      cout<<endl;
    } 
}
