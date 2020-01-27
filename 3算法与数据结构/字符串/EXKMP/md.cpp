#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int random(int n){
	return rand()%n+1;
}
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	int n=random(maxn),m=random(maxm);
	for(int i=1;i<=n;i++) printf("%c",'a'+random(0,25));
	printf("\n");
	for(int i=1;i<=m;i++) printf("%c",'a'+random(0,25));
}

