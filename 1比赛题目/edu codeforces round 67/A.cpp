#include<iostream>
#include<cstdio>
using namespace std;
int T;
long long n,s,t;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d %I64d %I64d",&n,&s,&t);
		long long all=s+t-n;
		long long toy=s-all;
		long long stk=t-all;
		long long ans=max(toy,stk)+1;
		printf("%I64d\n",ans);
	}
}

