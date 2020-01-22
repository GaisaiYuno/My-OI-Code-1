#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
using namespace std;
int n,m;
int c[maxn],a[maxn];
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&c[i]);
	for(int i=1; i<=m; i++) scanf("%d",&a[i]);
	int j=1;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(c[i]<=a[j]) {
			cnt++;
			j++;
		}
		if(cnt==0) break;
	}
	printf("%d\n",cnt);
}
