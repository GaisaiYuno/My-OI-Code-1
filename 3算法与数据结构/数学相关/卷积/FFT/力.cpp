//http://119.29.55.79/contest/92/problem/3 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
#define maxn 500000
using namespace std;
typedef complex<double> com;
const double pi=acos(-1.0);
int rev[maxn+5];
com a[maxn+5],b[maxn+5],c[maxn+5];
void fft(com *x,int n,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);
	}	
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=com(1,0);
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk*=wn1;
			}
		}
	}
} 

int n;
int main(){
	double x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&x);
		a[i]=x;
	}
	for(int i=0;i<n;i++) b[i]=-1.0/(1.0*(n-i)*(n-i));
	for(int i=n+1;i<=n*2;i++) b[i]=1.0/(1.0*(i-n)*(i-n));
	
	int k=0,m=1;
	while(m<=n*2){
		m*=2;
		k++;
	}
	for(int i=0;i<m;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	
	fft(a,m,1);
	fft(b,m,1);
	for(int i=0;i<m;i++) c[i]=a[i]*b[i];
	fft(c,m,-1);
	for(int i=n;i<=n*2-1;i++) printf("%.3f\n",c[i].real()/m);
}
