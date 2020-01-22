#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define maxv 1000
using namespace std;
int n,m;
int a[maxn+5],b[maxn+5];
int vis[maxv+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=1; 
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		vis[b[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!vis[a[i]+b[j]]){
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
		}
	}
}

