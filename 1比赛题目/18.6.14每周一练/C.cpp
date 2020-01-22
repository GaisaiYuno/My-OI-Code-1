#include<iostream>
#include<cstdio>
#include<cmath>
#define maxn 100000
using namespace std;
int t;
int x;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(x==1) printf("-1\n");
		else if(x==0) printf("1 1\n");
		else{
			long long n=sqrt(x)+1;
			bool flag=false; 
			for(;n<=maxn;n++){
				long long k=sqrt(n*n-x);
				long long m=n/k;
				if(n*n-(n/m)*(n/m)==x){
					printf("%I64d %I64d\n",n,m);
					flag=true;
					break; 
				}
			} 
			if(!flag) printf("-1\n");
		}
	}
}
