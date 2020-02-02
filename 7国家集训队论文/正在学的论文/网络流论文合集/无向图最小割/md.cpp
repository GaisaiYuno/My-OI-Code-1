#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 5
#define maxm 10
#define maxv 10
#define maxq 5
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1);
}
int main(){
	srand(time(NULL));
	int n=random(4,maxn);
	int m=random(n,maxm);
	printf("%d %d\n",n,m);
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1),i,random(maxv));
	}
	for(int i=1;i<=m-(n-1);i++){
		int x=random(n);
		int y=random(n);
		while(x==y) y=random(n);
		printf("%d %d %d\n",x,y,random(maxv));
	}
	int q=random(maxq);
	printf("%d\n",q);
	for(int i=1;i<=q;i++){
		int x=random(n);
		int y=random(n);
		while(x==y) y=random(n);
		printf("%d %d\n",x,y);
	}
}

