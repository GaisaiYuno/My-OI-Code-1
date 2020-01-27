#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int n=rand()%1000+1;
	int m=rand()%n;
	int x=rand()%n+1;
	int k=rand()%4;
	printf("%d %d %d %d",n,m,k,x);
}
