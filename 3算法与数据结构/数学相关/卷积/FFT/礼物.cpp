//http://119.29.55.79/contest/92/problem/4
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex> 
#define maxn 500000
#define INF 1e18
using namespace std;
typedef long long ll; 
typedef complex<double> com;
const double pi=acos(-1.0);
int rev[maxn+5];
void fft(com *x,int n,int type){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=com(1,0);
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-tmp*wnk;
				x[i]=x[i]+tmp*wnk;
				wnk*=wn1;
			} 
		}
	} 
} 

int n,rubbish;
double sumx,sumx2,sumy,sumy2;
ll x[maxn+5],y[maxn+5];
com a[maxn+5],b[maxn+5],ans[maxn+5]; 
int main(){
	scanf("%d %d",&n,&rubbish);
	for(int i=0;i<n;i++){
		scanf("%lld",&x[i]);
		sumx+=x[i];
		sumx2+=x[i]*x[i];
	} 
	for(int i=0;i<n;i++){
		scanf("%lld",&y[i]);
		sumy+=y[i];
		sumy2+=y[i]*y[i];
	} 
	double c=-(sumx-sumy)/n;
	if(c-floor(c)<ceil(c)-c) c=floor(c);
	else c=ceil(c);
	for(int i=0;i<n;i++){
		a[i]=a[i+n]=x[i];
	}
	for(int i=0;i<n;i++){
		b[i]=y[n-i-1];
	}
	
	int m=1,k=0;
	while(m<=n*3){
		k++;
		m*=2;
	}
	for(int i=0;i<=m;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	fft(a,m,1);
	fft(b,m,1);
	for(int i=0;i<m;i++) ans[i]=a[i]*b[i];
	fft(ans,m,-1);
	double f1=n*c*c+2*c*(sumx-sumy)+sumx2+sumy2;
	double f2=-INF;
	for(int i=n-1;i<=2*n-1;i++) f2=max(f2,ans[i].real()/m);
	ll res=(ll)(f1-2*f2+0.5);
	printf("%lld\n",res); 
}
