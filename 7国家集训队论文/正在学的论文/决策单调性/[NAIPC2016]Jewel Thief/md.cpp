#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 1000000
#define maxm 100000
#define maxw 300
#define maxv 1000000000
using namespace std;
int random(int n){
	return 1ll*rand()*rand()%n+1;
}
int random(int l,int r){
	return 1ll*rand()*rand()%(r-l+1)+l;
}
int main(){
	freopen("10.in","w",stdout);
	srand(time(NULL));
	int n=random(2,maxn),m=random(1,maxm);
//	int n=maxn,m=random(maxm,maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		printf("%d %d\n",random(maxw),random(maxv));
	}
}

