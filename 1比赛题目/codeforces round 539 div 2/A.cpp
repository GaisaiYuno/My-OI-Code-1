#include<iostream>
#include<cstdio>
using namespace std;
int n,v;
int main() {
	scanf("%d %d",&n,&v);
	if(v>=n-1){
		printf("%d\n",n-1);
		return 0;
	}
	int ans=v-1;
	for(int i=1; i<=n-v; i++) {
		ans+=i;
	}
	printf("%d\n",ans);
}

