#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 3
#define maxv 10
using namespace std;
int n;
inline int random(int n){
	return 1ll*rand()*rand()%n+1;
}
inline int random(int l,int r){
	return  1ll*rand()*rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	for(int i=1;i<=3;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	}
	n=random(maxn);
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d %d\n",random(-maxv,maxv),random(-maxv,maxv));
	}
}
