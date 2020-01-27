/*
Problem:
Source:
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxt 10
#define maxn 40
#define maxm 40
#define maxv 1000000
using namespace std;
inline int random(int n){
	return (long long)rand()*rand()%n+1;
}
int main(){
#ifdef FILE_IO
	freopen("input.txt","w",stdout);
#endif
	srand(time(NULL)); 
	int t=maxt;
	printf("%d\n",t);
	while(t--){ 
		int n=maxn;
		int m=maxm;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",random(maxv));
			}
			printf("\n");
		}
		printf("\n"); 
	} 
}


