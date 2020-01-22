/*
Problem:B
Source:Codeforces Good Bye 2018 https://codeforces.com/contest/1091/
Algorithm:
Description:
∂‘x,y«Û∫Õ
n*tx=sum(xi)
n*ty=sum(yi) 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int x,y,a,b;
long long sumx,sumy;
int main(){
	scanf("%d",&n);
	sumx=sumy=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		sumx+=x;
		sumy+=y;
	}
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a,&b);
		sumx+=a;
		sumy+=b;
	}
	printf("%I64d %I64d\n",sumx/n,sumy/n);
}

