#include<iostream>
#include<cstdio>
#define maxn 100000
using namespace std;
int n;
int deg[maxn+5];
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++; 
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
