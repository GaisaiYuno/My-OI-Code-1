#include<iostream>
#include<cstdio>
#define ForMyLove return 0;
using namespace std;
int n,m;
int main(){
//	freopen("zzc.in","r",stdin);
//	freopen("zzc.out","w",stdout);
	scanf("%d %d",&n,&m);
	printf("%d\n",min(min(n,m),(n+m)/3));
	ForMyLove
}
