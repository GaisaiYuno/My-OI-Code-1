#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int pri[20];
inline void qprint(int x) {
	if(x==0) {
		putchar('0');
	} else {
		int ptr=0;
		while(x>0) {
			pri[++ptr]=x%10+'0';
			x/=10;
		}
		for(int i=ptr; i>=1; i--) {
			putchar(pri[i]);
		}
	}
	putchar(' ');
}
void solve(int n,int x){
	if(n==1){
//		printf("%d",x); 
		qprint(x);
		return;
	}
	if(n==2){
//		printf("%d %d",x,2*x);
		qprint(x);
		qprint(2*x);
		return;
	}
	if(n==3){
//		printf("%d %d %d",x,x,3*x);
		qprint(x);
		qprint(x);
		qprint(x*3);
		return;
	} 
	for(int i=1;i<=n;i+=2){
//		printf("%d ",x);
		qprint(x);
	}
	solve(n/2,x*2);
}
int main(){
	freopen("ans.out","w",stdout);
//	cin>>n;
	n=1000000;
	solve(n,1); 
}
