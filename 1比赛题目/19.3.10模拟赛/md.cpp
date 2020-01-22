#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define maxn 5
#define maxm 5
#define maxv 10
using namespace std;
inline int random(int n){
	return rand()%n+1; 
}
int main(){
	srand(time(NULL)); 
	int n,m;
	n=random(maxn);
	m=random(maxm);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		printf("%d ",random(maxv));
	}
	printf("\n");
	for(int i=2;i<=n;i++){
		printf("%d %d\n",random(i-1),i);
	} 
	printf("%d %d\n",0,random(n));
	for(int i=1;i<=m;i++){
		int op=random(2);
		printf("%d ",op);
		if(op==1){
			printf("%d %d\n",random(n),random(maxv));
		}else{
			int l=random(n),r=random(n);
			if(l>r) swap(l,r); 
			printf("%d %d\n",l,r);
		}
	}
}

