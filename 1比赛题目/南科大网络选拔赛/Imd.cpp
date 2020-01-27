#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxt 10
#define maxn 100000
#define maxv 1000000000
using namespace std;
int n;
inline int random(int n){
	return 1ll*rand()*rand()%n+1;
}
inline int random(int l,int r){
	return 1ll*rand()*rand()%(r-l+1)+l;
}

int main(){
	freopen("1.in","w",stdout);
	int t=maxt;
	printf("%d\n",t);
	while(t--){ 
		int n=maxn;
		printf("%d %d %d\n",n,random(n),random(n));
		for(int i=1;i<=n;i++){
			printf("%d ",random(-maxv,maxv));
		}
		printf("\n");
		for(int i=1;i<=n;i++){
			printf("%d ",random(-maxv,maxv));
		}
		printf("\n");
	} 
}

