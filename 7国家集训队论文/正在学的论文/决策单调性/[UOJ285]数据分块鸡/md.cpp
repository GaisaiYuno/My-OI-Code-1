#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 50000
#define maxm 100000
using namespace std;
int random(int n){
	return rand()%n+1;
}
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("10.in","w",stdout);
	srand(time(NULL));
//	int n=random(2,maxn),m=random(1,maxm);
	int n=random(maxn,maxn),m=random(maxm,maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		int l=random(1,n-1),r=random(l+1,n);
//		if(l>r) swap(l,r);
		printf("%d %d\n",l,r);
	}
}

