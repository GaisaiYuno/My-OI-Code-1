#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 4
#define maxm 4
#define maxv 5
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
		if(rand()%2==0){
			printf("C %d %d\n",random(n),random(maxv));
		}else{
			int l=random(n),r=random(n);
			if(l>r) swap(l,r);
			printf("Q %d %d %d\n",l,r,random(r-l+1));
		}
	}
}

