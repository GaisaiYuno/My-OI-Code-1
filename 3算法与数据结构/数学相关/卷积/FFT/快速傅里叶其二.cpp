//http://119.29.55.79/contest/92/problem/2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
#define maxn 400000
using namespace std;
const double pi=acos(-1.0);
typedef complex<double> com;
int n;
com a[maxn+5],b[maxn+5],c[maxn+5];
int rev[maxn+5];
void fft(com*x,int type){//orz Fourier
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
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

int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		a[i]=x;
		b[n-i-1]=y;
	}
	int m=n*2,k=0;
	n=1;
	while(n<m){
		n*=2;
		k++;
	}
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	fft(a,1);
	fft(b,1);
	for(int i=0;i<n;i++) c[i]=a[i]*b[i];
	fft(c,-1);
	for(int i=m/2-1;i<=m-2;i++) printf("%d\n",(int)(0.5+c[i].real()/n));
}
