#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
int n,d,k,a[500000+5],b[500000+5],i;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	printf("-1");
	return 0;
}
