#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int is_inter(int u1,int v1,int u2,int v2){
	if(u1>v1)swap(u1,v1);
	if(u2>v2)swap(u2,v2);
	if((u1<u2&&u2<v1&&v1<v2)||(u2<u1&&u1<v2&&v2<v1)) {
		return 1;
	}
	return 0;
}

int is_inter2(int l1,int r1,int l2,int r2) {
	if(l1>r1) swap(l1,r1);
	if(l2>r2) swap(l2,r2);
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}
	if(l2<r1&&r2>r1) return 1;
	else return 0;
}
int main(){
	srand(time(NULL)); 
	int k=0,a,b,c,d;
	while(++k){
//		a=b=c=d=1;
	
		a=rand();
		b=rand();
		c=rand();
		d=rand();
		a=1;
		b=5;
		c=1;
		d=2;
		printf("test %d: ",k);
		printf("[%d,%d] [%d,%d]",a,b,c,d);
		printf("\n");
		if(is_inter(a,b,c,d)!=is_inter2(a,b,c,d)) {
			printf("NO\n");
			printf("[%d,%d] [%d,%d]",a,b,c,d);
			system("pause");
		}
		system("cls");
	}
} 
