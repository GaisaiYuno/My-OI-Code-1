#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 10
#define maxv 50
using namespace std;
int n,m;
inline int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL)); 
	n=random(maxn);
	m=random(maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=1;i<=m;i++){
		if(random(2)==1){
			printf("M %d %d\n",random(maxn),random(maxn));
		}else{
			printf("K %d\n",random(maxn));
		}
	}
}

