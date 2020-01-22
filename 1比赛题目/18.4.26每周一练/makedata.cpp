#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXN 10
#define MAXV 10000
#define MAXM 10
using namespace std;
int main(){
//	freopen("segtree.in","w",stdout);
	srand(time(NULL));
	int n=rand()%MAXN+1;n=100000; 
	int m=rand()%MAXM+1;m=100000;
	printf("%d %d\n",n,m);
	while(n--){
		printf("%lld ",(long long)(rand()%MAXV+1)*100000ll);
	} 
	printf("\n");
	while(m--){
		long long x,cmd,l,r;
		cmd=rand()%2+1;
		l=rand()%n+1;
		r=rand()%n+1;
		if(l>r) swap(l,r);
		cmd=1;
		if(cmd==1){
			x=((long long)(rand()%MAXV+1)*100000ll);
			l=rand()*rand()%100000;r=rand()*rand()%100000;
			if(l>r) swap(l,r);
			printf("%lld %lld %lld %lld\n",cmd,l,r,x);
		}else{
			printf("ll%d %lld %lld \n",cmd,l,r);
		}
	}
} 

