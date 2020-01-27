#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxv 100
using namespace std;
int n,k;
int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL));
	n=random(maxn);
	k=random(maxv);
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++){
		printf("%d %d %d\n",random(k),random(k),random(k));
	}
}
