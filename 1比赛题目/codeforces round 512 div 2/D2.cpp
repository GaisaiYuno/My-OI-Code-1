#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define int long long
int gcd(int a,int b){
	if(a>b) swap(a,b);
	while(a){
		b%=a;
		swap(a,b);
	}
	return b;
}
#undef int
int main(){
#define int long long
	int n,m,k;
	cin>>n>>m>>k;
	int x1,x2,x3,y1,y2,y3;
	x1=y1=0;
	x2=y3=0;
	if(n*m*2%k!=0){
		puts("NO");
		return 0;
	}
	int s=n*m*2/k;
	if(gcd(2*m,k)==1){
		y2=m,x3=n*2/k;
	}
	else{
		y2=m*2/gcd(m*2,k),x3=s/y2;
	}
	printf("YES\n%I64d %I64d\n%I64d %I64d\n%I64d %I64d\n",x1,y1,x2,y2,x3,y3);
}
