#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#define maxn 1000000
using namespace std;
int n;
int a[maxn+5];
int main(){
	srand(time(NULL));
	n=maxn;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		a[i]='A'+rand()%26;
		printf("%c",a[i]);
	}
	printf("\n");
	random_shuffle(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		printf("%c",a[i]);
	}
}

