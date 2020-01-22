#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 6
#define maxm 6
#define maxs 2
#define maxv 5
#define maxt 10
using namespace std;
int random(int l,int r){
	return rand()%(r-l+1)+l; 
}
int main(){
	srand(time(NULL));
	int n=random(2,maxn),m=random(2,maxm);
	printf("%d %d\n",n,m);
	int s=random(1,maxs);
	printf("%d %d %d\n",s,random(1,maxv),random(1,maxv));
	for(int i=1;i<=s;i++){
		printf("%d %d\n",random(1,n-1),random(1,m-1));
	}
	printf("%d\n",random(1,maxt));
}

