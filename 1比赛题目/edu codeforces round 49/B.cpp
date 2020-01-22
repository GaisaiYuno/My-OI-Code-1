#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,q,x,y,ans;
int main() {
	scanf("%d %d",&n,&q);
	for(int i=1; i<=q; i++) {
		scanf("%d %d",&x,&y);
		if(x%2==1&&y%2==1) {
			ans=n*(x-1)/2+(y+1)/2;
			printf("%I64d\n",ans);
		} else if(x%2==1&&y%2==0) {
			ans=(n*n+1)/2+n*(x-1)/2+y/2;
			printf("%I64d\n",ans);
		} else if(x%2==0&&y%2==0) {
			ans=(x-2)/2*n+(n+1)/2+(y/2);
			printf("%I64d\n",ans); 
		} else {
			ans=(n*n+1)/2+(x-2)/2*n+n/2+(y+1)/2;
			printf("%I64d\n",ans); 
		}
	}
}
