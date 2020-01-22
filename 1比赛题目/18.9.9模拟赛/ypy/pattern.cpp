#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20005
using namespace std;
int n,k;
int a[maxn];
int main(){
	freopen("pattern.in","r",stdin);
	freopen("pattern.out","w",stdout);
	scanf("%d %d",&n,&k);
	printf("%d\n",n/k);
}
