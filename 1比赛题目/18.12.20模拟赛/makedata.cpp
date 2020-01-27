#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 10
#define maxm 10
#define maxv 10
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
int main(){
	srand(time(NULL));
	int n=random(maxn);
	int m=random(maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	int cmd,l,r,s,t;
	for(int i=1;i<=m;i++){
		cmd=random(3);
		l=random(n);
		r=random(n);
		s=random(maxv);
		t=random(maxv);
		if(l>r) swap(l,r);
		printf("%d ",cmd);
		if(cmd==1){
			printf("%d %d\n",l,r);
		}else{
			printf("%d %d %d %d\n",l,r,s,t);
		}
	}
}
