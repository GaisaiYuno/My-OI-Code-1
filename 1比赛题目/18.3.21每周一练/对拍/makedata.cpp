#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define MAXN 10
#define MAXC 20
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%MAXN+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		int l=rand()%MAXC+1;
		int r=rand()%MAXC+1;
		int type=rand()%2;
		if(l>r) swap(l,r);
		printf("%d %d",l,r);
		if(type==1) printf(" w\n");
		else printf(" b\n");
	}
}
