#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,s,l;
int a[maxn];
int main(){
	freopen("tiller.in","r",stdin);
	freopen("tiller.out","w",stdout);
	scanf("%d %d %d",&n,&s,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	if(n%2) printf("-1\n");
	else printf("%d\n",n/l);
} 
