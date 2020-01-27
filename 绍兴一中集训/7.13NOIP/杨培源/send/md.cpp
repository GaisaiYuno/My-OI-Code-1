#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define maxn 6
#define maxq 20
#define maxv 100
using namespace std;
inline int random(int n){
	return rand()%n+1;
}
inline int random(int l,int r){
	return l+rand()%(r-l+1);
}
int main(){
	srand(time(NULL));
	int n,q;
	n=random(2,maxn);
	q=random(maxq);
	printf("%d %d\n",n,q);
	for(int i=1;i<=q;i++){
		int w=random(1,2);
		if(w==1){
			int x=random(2,n),y=random(x-1),z=random(maxv);
			printf("%d %d %d %d\n",w,x,y,z);
		}else{
			int x=random(2,n),y=random(x-1),z=1;
			printf("%d %d %d %d\n",w,x,y,z);
		}
	}
}
