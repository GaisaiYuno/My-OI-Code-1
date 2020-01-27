//洛谷 NASA的食物计划
#include<iostream>
#include<cstdio>
#define maxn 501
using namespace std;
int M,V,n;
int f[maxn][maxn];
struct node {
	int m;
	int v;
	int c;
} a[maxn];
int main() {
	cin>>V>>M;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].v>>a[i].m>>a[i].c;
	}
	for(int i=1; i<=V; i++) {
		for(int j=V; j>=a[i].v; j--) {
           for(int k=M;k>=a[i].m;k--){
           	  f[j][k]=max(f[j][k],f[j-a[i].v][k-a[i].m]+a[i].c);
		   }
		}
	}
	cout<<f[V][M];
	return 0;
}
