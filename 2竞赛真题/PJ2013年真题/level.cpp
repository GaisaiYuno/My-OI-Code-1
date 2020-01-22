//level
#include<iostream>
#include<cstdio>
#define maxn 1005 
using namespace std;
int n,m,s,ans;
int a[maxn];
int f[maxn];
int g[maxn][maxn];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++) {
		int u=2;
		cin>>s;
		for(int j=1;j<=s;j++) cin>>a[j];
		for(int j=a[1]+1;j<=a[s];j++){
			if(j==a[u]) u++;
			else for(int k=1;k<=x;k++) g[j][a[u]]=1;
		}
	}
} 
