#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<algorithm>
#define maxn 20
#define maxq 10
#define maxv 100
using namespace std;
int a[maxn];
int main(){
	srand(time(NULL));
	int n=rand()%maxn+1;
	int q=rand()%maxq+1;
	printf("%d %d\n",n,q);
	for(int i=1;i<=n;i++){
		a[i]=rand()%maxn;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	while(q--){
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r) swap(l,r);
		printf("%d %d\n",l,r);
	}
}
