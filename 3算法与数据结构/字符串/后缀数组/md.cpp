#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<ctime>
#define maxn 1000000
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("1.in","w",stdout);
	srand(time(NULL));
	int n=maxn;
	for(int i=1;i<=maxn/2;i++) printf("ab");
}

