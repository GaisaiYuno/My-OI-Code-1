#include<iostream>
#include<cstdio>
#include<cstring>
#include<complex>
#include<cmath>
#define maxn 300000
using namespace std;
typedef complex<double> com;
const double pi=acos(-1.0); 

int n;
char stra[maxn+5],strb[maxn+5];
com a[maxn+5],b[maxn+5],c[maxn+5];
int ans[maxn+5];
int rev[maxn+5];
void fft(com *x,int type){
	for(int i=0;i<n;i++){
		if(i<rev[i]) swap(x[i],x[rev[i]]);//i<rev[i]防止重复交换，要不循环到rev[i]的时候又换回来了 
	} 
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/(len*2)),type*sin(2*pi/(len*2)));
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
	scanf("%d",&n);
	scanf("%s",stra);
	scanf("%s",strb);
	for(int i=0;i<n;i++) a[i]=stra[n-1-i]-'0';
	for(int i=0;i<n;i++) b[i]=strb[n-1-i]-'0';	
	int m=n*2;
	n=1;
	int k=0;
	while(n<m){
		n*=2;
		k++;
	}
	
	for(int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	fft(a,1);
	fft(b,1);
	for(int i=0;i<n;i++) c[i]=a[i]*b[i];
	fft(c,-1);
//	for(int i=0;i<n;i++) cout<<c[i]<<endl;
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
