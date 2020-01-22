#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define MAXN 5
#define MAXM 15
using namespace std;
int n,m;
inline int random(int n){
	return rand()%n+1;
} 

int main(){
	srand(time(NULL));
	int u,v;
	n=random(MAXN)+1;
	m=random(min(MAXM,n*(n-1)/2));
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		u=random(n);
		v=random(n);
		if(u==v) v=u+1;
		printf("%d %d\n",u,v);
	} 
}

