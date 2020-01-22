#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
char c[maxn];
int b[maxn];
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
	x*=sign;
}

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x); 
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int worka[maxn];
char workc[maxn];
int workb[maxn];
inline int solve(register int begin){
	register int cnt=0;
	for(register int i=begin;i<n;i++){
		worka[cnt]=a[i];
		workc[cnt]=c[i];
		cnt++;
	}
	for(register int i=0;i<begin;i++){
		worka[cnt]=a[i];
		workc[cnt]=c[i];
		cnt++;
	}
	workb[0]=worka[0];
	for(register int i=1;i<n;i++){
		if(workc[i]=='+')workb[i]=(worka[i]+worka[i-1])%10;
		else workb[i]=(worka[i]*worka[i-1])%10;
	}
	int l=0,r=0;
	int ans=-1;
	for(register int i=0;i<n;i++){
		if(workb[i]==0&&(i==0||workb[i-1]!=0)) l=i;
		if(workb[i]==0&&(i==n-1||workb[i+1]!=0)){
			r=i;
			ans=max(min(min(l,r),min(n-l,n-r)),ans);
		}
	}
	return ans;
}
int main(){
	int op,pos,num;
	char ch;
	qread(n);
	qread(m);
	for(register int i=0;i<n;i++){
		qread(a[i]);
		c[i]=getchar(); 
	}
	for(register int i=1;i<=m;i++){
		qread(op);
		if(op==1){
			qread(pos);
			qread(num);
			ch=getchar();
			a[pos]=num;
			c[pos]=ch; 
		}else{
			qread(pos);
			qprint(solve(pos));
			putchar('\n');
		}
	}
}
