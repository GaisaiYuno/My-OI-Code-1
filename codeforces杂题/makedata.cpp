#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 15
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1;
	int m=rand()%maxm+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		if(rand()%2==1) printf("7");
		else printf("4"); 
	}
	printf("\n");
	for(int i=1;i<=m;i++){
		if(rand()%2==1) printf("count\n");
		else{
			int l=rand()%n+1;
			int r=rand()%n+1;
			if(l>r) swap(l,r);
			printf("switch %d %d\n",l,r);
		}
	}
}
