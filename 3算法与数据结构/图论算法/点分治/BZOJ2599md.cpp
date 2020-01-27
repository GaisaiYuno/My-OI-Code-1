#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 7 
using namespace std;
int n,k;
inline int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL));
	n=random(maxn);
	k=random(n);
	printf("%d %d\n",n,k);
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1)-1,i-1,random(3)); 
	} 
}

