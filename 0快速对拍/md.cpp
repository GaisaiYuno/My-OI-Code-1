#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 100000
#define maxm 100000
using namespace std;
int random(int n){
	return rand()%n+1;
}
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=random(maxn),m=random(maxm);
	for(int i=1;i<=n;i++) printf("%c",'a'+random(0,5));
	printf("\n");
	for(int i=1;i<=m;i++) printf("%c",'a'+random(0,5));
}

