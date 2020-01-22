#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 200000
#define maxI 100000000
#define maxv 1000000000
using namespace std;
int random(int n){
	return (long long)rand()*rand()%n+1;
}
int n,I; 
int main(){
	srand(time(NULL));
	n=random(maxn);
	I=random(maxI);
	printf("%d %d\n",n,I);
	for(int i=1;i<=n;i++) printf("%d " ,random(maxv));
}

