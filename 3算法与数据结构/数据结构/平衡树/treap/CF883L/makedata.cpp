#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxt 100
using namespace std;
int n,k,m;
int _random(int n){
	return rand()%n+1;
} 
long long __random(long long n){
	return (long long)rand()*rand()%n+1;
}
int main(){
	srand(time(NULL));
	n=maxn;
	k=maxn;
	m=maxn;
	printf("%d %d %d\n",n,k,m);
	for(int i=1;i<=k;i++){
		printf("%d ",_random(n));
	}
	printf("\n");
	long long tt;
	int aa,bb;
	for(int i=1;i<=m;i++){
		tt=__random(maxt);
		aa=_random(n);
		bb=_random(n);
		printf("%lld %d %d\n",tt,aa,bb);
	}
}
