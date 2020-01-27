#include<iostream>
#include<cstdio>
#define maxn 5
#define maxm 5
#define maxd 5
#define maxv 1000
using namespace std;
int random(int n){
	return rand()%n+1;
} 
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n,m,d; 
int main(){
	n=random(maxn);
	m=random(maxm);
	d=random(maxd);
	printf("%d %d %d\n",n,m,d);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++) printf("%.1lf ",random(-maxv,maxv)/100.0);
		printf("\n");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++) printf("%.1lf ",random(-maxv,maxv)/100.0);
		printf("\n");
	}
}

