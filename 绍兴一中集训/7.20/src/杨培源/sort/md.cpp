#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 300000
#define maxm 300000
#define maxv 1000000000
using namespace std;
int n;
inline int random(int l,int r){
	return (long long)rand()*rand()%(r-l+1)+l;
}
inline int random(int n){
	return (long long)rand()*rand()%n+1;
}
int main(){
	freopen("sort.in","w",stdout);
	srand(time(NULL));
	int n=maxn;
	int m=maxm;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=1;i<=m;i++){
		printf("%d\n",random(1,n));
	}
}
