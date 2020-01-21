#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 5
#define maxm 5
#define maxv 10
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
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",random(i-1),i,random(maxv));
	} 
	for(int i=1;i<=m;i++){
		printf("%d\n",random(n));
	}
} 

