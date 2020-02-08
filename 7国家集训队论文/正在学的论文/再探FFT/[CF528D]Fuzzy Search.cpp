#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 1048576
#define maxc 4
using namespace std;
const double pi=acos(-1.0);
struct com{
	double real;
	double imag;
	com(){
		
	} 
	com(double _real,double _imag){
		real=_real;
		imag=_imag;
	}
	com(double x){
		real=x;
		imag=0;
	}
	void operator = (const com x){
		this->real=x.real;
		this->imag=x.imag;
	}
	void operator = (const double x){
		this->real=x;
		this->imag=0;
	}
	friend com operator + (com p,com q){
		return com(p.real+q.real,p.imag+q.imag);
	}
	friend com operator + (com p,double q){
		return com(p.real+q,p.imag);
	}
	void operator += (com q){
		*this=*this+q;
	}
	void operator += (double q){
		*this=*this+q;
	}
	friend com operator - (com p,com q){
		return com(p.real-q.real,p.imag-q.imag);
	}
	friend com operator - (com p,double q){
		return com(p.real-q,p.imag);
	}
	void operator -= (com q){
		*this=*this-q;
	}
	void operator -= (double q){
		*this=*this-q;
	}
	friend com operator * (com p,com q){
		return com(p.real*q.real-p.imag*q.imag,p.real*q.imag+p.imag*q.real);
	}
	friend com operator * (com p,double q){
		return com(p.real*q,p.imag*q);
	} 
	void operator *= (com q){
		*this=(*this)*q;
	}
	void operator *= (double q){
		*this=(*this)*q;
	}
	friend com operator / (com p,double q){
		return com(p.real/q,p.imag/q);
	} 
	void operator /= (double q){
		*this=(*this)/q;
	} 
	void print(){
		printf("%lf + %lf i ",real,imag);
	}
};
int rev[maxn+5];
void fft(com *x,int n,int type){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(x[i],x[rev[i]]);
	for(int len=1;len<n;len*=2){
		int sz=len*2;
		com wn1=com(cos(2*pi/sz),type*sin(2*pi/sz));
		for(int l=0;l<n;l+=sz){
			int r=l+len-1;
			com wnk=1;
			for(int i=l;i<=r;i++){
				com tmp=x[i+len];
				x[i+len]=x[i]-wnk*tmp;
				x[i]=x[i]+wnk*tmp;
				wnk=wnk*wn1;
			}
		}
	}
	if(type==-1) for(int i=0;i<n;i++) x[i]/=n;
} 

inline int get_id(char c){
	if(c=='A') return 0;
	else if(c=='T') return 1;
	else if(c=='G') return 2;
	else return 3;
}
int n,m,K;
char s[maxn+5],t[maxn+5];
int sum[maxc+5][maxn+5];
int match[maxn+5][maxc+5];//标记s的第i位周围有没有字符j 

com a[maxn+5],b[maxn+5];
long long ans[maxn+5];
int main(){
	scanf("%d %d %d",&n,&m,&K);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<maxc;j++) sum[j][i]=sum[j][i-1]+(get_id(s[i])==j);
	} 
	for(int i=1;i<=n;i++){
		int lb=max(i-K,1);
		int rb=min(i+K,n);
		for(int j=0;j<maxc;j++){
			if(sum[j][rb]-sum[j][lb-1]>0) match[i][j]=1;
			else match[i][j]=0;
		}
	}
	int M=n+m;
	int N=1,L=0;
	while(N<=M){
		N*=2;
		L++;
	}
	for(int i=0;i<N;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	for(int c=0;c<maxc;c++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			if(match[i][c]) a[i-1]=1;
			else a[i-1]=0;
		}
		for(int i=1;i<=m;i++){
			if(get_id(t[i])==c) b[m-i]=1;
			else b[m-i]=0;
		}
		fft(a,N,1);
		fft(b,N,1);
		for(int i=0;i<N;i++) a[i]*=b[i];
		fft(a,N,-1);
		for(int i=0;i<N;i++) ans[i]+=(long long)(a[i].real+0.5);
	} 
	int cnt=0;
	for(int i=0;i<N;i++) if(ans[i]==m) cnt++;
	printf("%d\n",cnt);
}

