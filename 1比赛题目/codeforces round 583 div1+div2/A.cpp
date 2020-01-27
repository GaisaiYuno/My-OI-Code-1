#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int n,d,e;
int main(){
	scanf("%d %d %d",&n,&d,&e);
	e*=5;
	int ans=INF;
	for(int i=0;i*d<=n;i++){
		ans=min(ans,n-i*d-(n-i*d)/e*e);
	}
	printf("%d\n",ans);
}
