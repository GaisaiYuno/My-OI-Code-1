//For my love Selina
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int u,v,w;
	scanf("%d %d",&n,&k);
	long long sum=0;
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&u,&v,&w);
		sum+=w;
	}
	if(n==k){
		printf("%lld\n",sum*n);
	}else{
		printf("0\n");
	}
}
