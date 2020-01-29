#include<iostream>
#include<cstdio>
#define maxn 5005
using namespace std;
int a[maxn];
int ask(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int main(){
	int n;
	scanf("%d",&n);
	fflush(stdout);
	int x=ask(1,2);
	int y=ask(1,3);
	int z=ask(2,3);
	a[1]=(x+y+z)/2-z;
	a[2]=(x+y+z)/2-y;
	a[3]=(x+y+z)/2-x;
	for(int i=4;i<=n;i++){
		int tmp=ask(3,i);
		a[i]=tmp-a[3];
	}
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}

