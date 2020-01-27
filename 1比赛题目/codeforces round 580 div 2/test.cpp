#include<iostream>
#include<cstdio>
#define maxn 100000
using namespace std;
long long a[maxn+5]; 
int main(){
	freopen("b.out","w",stdout);
	for(int i=1;i<=maxn;i++){
		a[i]=i;
		printf("%d\n",i);
	}
}

