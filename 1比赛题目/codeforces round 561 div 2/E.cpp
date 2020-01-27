#include<iostream>
#include<cstdio>
#define maxm 55
#define maxn 10005
using namespace std;
int m,n;
int a[maxm][maxn];
int main() {
	int sz,x;
	scanf("%d %d",&m,&n);
	for(int i=1; i<=m; i++) {
		scanf("%d",&sz);
		for(int j=1; j<=sz; j++) {
			scanf("%d",&x);
			a[i][x]=1;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			bool flag=true;
			for(int k=1; k<=n; k++) {
				if(a[i][k]==1&&a[j][k]==1) {
					flag=false;
				}
			}
			if(flag) {
				printf("impossible\n");
				return 0;
			}
		}
	}
	printf("possible");
}

