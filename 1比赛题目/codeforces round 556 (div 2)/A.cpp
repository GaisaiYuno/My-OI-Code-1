#include<iostream>
#include<cstdio>
#define maxn 1005
#define INF 0x7fffffff
using namespace std;
int n,m,r; 
int s[maxn],b[maxn]; 
int main(){
	scanf("%d %d %d",&n,&m,&r);
	int buy=INF,sell=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		buy=min(buy,s[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		sell=max(sell,b[i]);
	}
	printf("%d\n",max(r,r-r/buy*buy+r/buy*sell));
}

