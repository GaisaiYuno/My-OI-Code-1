//http://119.29.55.79/contest/92/problem/1
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
#define maxn 300000
using namespace std;
const double pi=acos(-1.0);
typedef complex<double> com;
com a[maxn+5],b[maxn+5],c[maxn+5];
void fft(com *x,int n,int type){//orz  
	if(n==1) return;
	com l[n>>1],r[n>>1];
	for(int i=0;i<n;i++){
		if(!(i&1)) l[i>>1]=x[i]; 
		else r[i>>1]=x[i];
	}
	fft(l,n>>1,type);
	fft(r,n>>1,type);
	
	com wn1=com(cos(2*pi/n),type*sin(2*pi/n)),wnk=com(1,0);	
	for(int i=0;i<(n>>1);i++){
		x[i]=l[i]+wnk*r[i];
		x[i+(n>>1)]=l[i]-wnk*r[i];
		wnk*=wn1;
	}
}

int n;
char stra[maxn+5],strb[maxn+5];
int ans[maxn+5];
int main(){
//	freopen("2.in","r",stdin);
//	freopen("2.ans","w",stdout); 
	scanf("%d",&n);
	scanf("%s",stra);
	scanf("%s",strb);
	for(int i=0;i<n;i++) a[i]=stra[n-1-i]-'0';
	for(int i=0;i<n;i++) b[i]=strb[n-1-i]-'0';	
	int m=n*2;
	n=1;
	while(n<m) n*=2;
	fft(a,n,1);
	fft(b,n,1);
	for(int i=0;i<n;i++) c[i]=a[i]*b[i];
	fft(c,n,-1);
	for(int i=0;i<n;i++) cout<<c[i]<<endl;
	for(int i=0;i<m;i++){
		int x=(int)(c[i].real()/n+0.5);
		ans[i]+=x;
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
//		printf("%.0f",c[i].real()/n);
	}
	int len=m;
	while(ans[len]==0) len--;
	for(int i=len;i>=0;i--) printf("%d",ans[i]);
}
