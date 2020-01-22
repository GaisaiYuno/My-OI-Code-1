#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 5
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=maxn;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%c",'a'+random(0,7));
}
