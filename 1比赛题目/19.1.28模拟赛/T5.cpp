/*
For Selina
*/
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxc 3
using namespace std;
int t,n;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}
	if(x==0){
		putchar('0');
		return;
	}
	if(x>0){
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

struct matrix{
	unsigned long long a[maxc][maxc];
	matrix(){
		memset(a,0,sizeof(a));
	}
	friend matrix operator * (matrix a,matrix b){
		matrix c;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				c.a[i][j]=0;
				for(int k=1;k<=2;k++){
					c.a[i][j]+=a.a[i][k]*b.a[k][j];
				}
			}
		}
		return c;
	}
};

matrix fast_pow(matrix x,int k){
	matrix ans;
	ans.a[1][1]=1;
	ans.a[1][2]=0;
	ans.a[2][1]=0;
	ans.a[2][2]=1;
	while(k>0){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

int p,q;
int main(){
	qread(t);
	while(t--){
		qread(p);
		qread(q);
		qread(n);
		matrix T;
		T.a[1][1]=p;
		T.a[1][2]=-q;
		T.a[2][1]=1;
		T.a[2][2]=0;
		T=fast_pow(T,n-1);
		unsigned long long ans=(p*T.a[1][1]+2*T.a[1][2]);
		cout<<ans<<endl;
	}
}
