#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 7
using namespace std;
int n;
int main(){
	srand(time(NULL));
	n=rand()%maxn+1;
	printf("%d\n",n);
	for(int i=2;i<=n;i++){
		printf("%d %d\n",rand()%(i-1)+1,i);
	}
} 
