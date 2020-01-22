#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[2001];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m,x,k,minn,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&k,&x);
		y=1; minn=2147483647;
		for(int j=1;j<=k;j++){
			y*=10;
		}
		for(int j=1;j<=n;j++){
			if(a[j]<x)continue;
			if((a[j]-x)%y==0)minn=min(minn,a[j]);
		}
		if(minn!=2147483647)printf("%d\n",minn);
		else printf("-1\n");
	}
	return 0;
}
