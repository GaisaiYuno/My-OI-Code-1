#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 1000
#define maxv 1000
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	int n=random(maxn);
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",random(maxv));
	printf("\n");
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1),i,random(maxv));
	}
	printf("\n");
}
