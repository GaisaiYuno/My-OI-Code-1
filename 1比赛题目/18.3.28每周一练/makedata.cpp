#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int t=rand()%100;
	while(t--) {
		int n=rand()%100;
		printf("%d\n",n);
		for(int i=1; i<=n; i++) {
			int s=rand()%n;
			int e=rand()%n;
			if(s>e) swap(s,e);
			printf("%d %d\n",s,e);
		}
		printf("\n");
	}
	printf("0");
}
