#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 10
#define maxv 10
using namespace std;
int main(){
	srand(time(NULL));
	int t=rand()%3+1;
	printf("%d\n",t);
	while(t--){
		int n=rand()%maxn+1;
		printf("%d\n",n);
		for(int i=1;i<=n;i++) printf("%d ",rand()%maxv+1);
		printf("\n");
		int m=rand()%maxm+1;
		printf("%d\n",m);
		while(m--){
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r) swap(l,r);
			printf("%d %d\n",l,r);
		} 
	}
}
