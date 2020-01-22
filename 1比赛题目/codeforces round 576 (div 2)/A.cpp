#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100000
#define maxlogn 20
#define INF 0x3f3f3f3f
using namespace std;
int n,x,y;
int a[maxn+5];


int main() {
	scanf("%d %d %d",&n,&x,&y);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
//	T.ini();
	for(int i=1; i<=n; i++) {
		int lmin=INF,rmin=INF;
		for(int j=max(i-x,1);j<i;j++) lmin=min(lmin,a[j]);
		for(int j=i+1;j<=min(i+y,n);j++) rmin=min(rmin,a[j]);
		if(a[i]<lmin&&a[i]<rmin){
			printf("%d\n",i);
			break;
		}
	}
}

