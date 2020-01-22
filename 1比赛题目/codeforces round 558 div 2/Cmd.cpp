#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime> 
#define maxn 4
#define maxv 10 
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1); 
} 

int main(){
	srand(time(NULL));
	int n;
	n=random(maxn);
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	}
}

