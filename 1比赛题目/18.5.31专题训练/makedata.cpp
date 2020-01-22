#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxt 10 
#define maxn 20
#define maxv 10000
using namespace std;
int main(){
	srand(time(NULL));
	int t=rand()%maxt+1;
	printf("%d\n",t); 
	while(t--){
		int n=rand()%maxn;
		printf("%d\n",n);
		for(int i=1;i<=n;i++) printf("%d ",rand()%maxv);
		printf("\n");
	}
}
