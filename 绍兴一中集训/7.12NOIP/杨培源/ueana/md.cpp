#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int random(int n){
	return rand()%n+1;
}
int random(int l,int r){
	return l+rand()%(r-l+1);
}
int main(){
//	freopen("ueana.in","w",stdout);
	srand(time(NULL));
	int n=50000;
	for(int i=1;i<=n;i++){
		int k=random(1,4);
		if(k==1) printf("A");
		else if(k==2) printf("G");
		else if(k==3) printf("C");
		else printf("T"); 
	}
	printf("\n");
	printf("10\n");
}
