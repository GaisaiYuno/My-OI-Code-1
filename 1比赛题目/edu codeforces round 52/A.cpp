#include<iostream>
#include<cstdio>
using namespace std;
int t;
long long s,a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%I64d %I64d %I64d %I64d",&s,&a,&b,&c);
		printf("%I64d\n",s/c+(s/c)/a*b);
	}
} 
