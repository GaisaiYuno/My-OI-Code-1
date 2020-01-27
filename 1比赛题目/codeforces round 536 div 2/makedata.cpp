#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime> 
#define maxv 10
#define maxn 7
using namespace std;
int n;
inline int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL));
	int n=random(maxn);
	int m=random(maxn);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=1;i<=m;i++){
		printf("%d %d\n",random(n),random(maxv));
	}
}

