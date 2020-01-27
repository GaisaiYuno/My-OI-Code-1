#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#define maxn 5
#define maxv 5
using namespace std;
int main() {
	srand(time(NULL));
	int n=rand()%maxn+1;
	printf("%d\n",n);
	for(int i=1; i<=n; i++ ) printf("%d ",rand()%maxv+1);
	printf("\n");
	for(int i=1; i<=n; i++ ) printf("%d ",rand()%maxv+1);
	printf("\n");
	for(int i=1; i<=n; i++ ) printf("%d ",rand()%maxv+1);
	printf("\n");
}
