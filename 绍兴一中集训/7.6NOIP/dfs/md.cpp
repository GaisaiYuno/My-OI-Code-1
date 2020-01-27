#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 3000
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1);
}

int main(){
#ifdef DEBUG
	freopen("1.in","w",stdout);
#endif
	srand(time(NULL));
	int n=random(maxn);
	printf("%d\n",n);
	printf("0 ");
	for(int i=2;i<=n;i++){
//		printf("-1\n");
		int p=random(1,3);
		if(p<3) printf("-1 ");
		else printf("%d ",random(1,i-1));
	}
}
