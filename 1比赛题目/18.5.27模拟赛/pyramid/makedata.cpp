#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 5
#define maxq 5
#define maxv 10
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%maxn;
	int q=rand()%maxq;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",rand()%maxv);
	printf("\n");\
	printf("%d\n",q);
	while(q--){
		int l=rand()%n+1;
		int r=rand()%n+1;
		if(l>r) swap(l,r);
		printf("%d %d\n",l,r);
	}
}
