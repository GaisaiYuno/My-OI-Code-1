#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 20
using namespace std;
int n,k;
int a[maxn+5][maxn+5];
int pos[maxn+5][maxn+5];
bool check(int x,int y){
	for(int i=1;i<=k;i++){
		if(pos[i][x]>pos[i][y]) return 0;
	}
	return 1;
}
int main(){
#ifndef LOCAL
	freopen("gymnastics.in","r",stdin);
	freopen("gymnastics.out","w",stdout);
#endif 
	scanf("%d %d",&k,&n);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			pos[i][a[i][j]]=j; 
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)||check(j,i)) ans++;
		}
	}
	printf("%d\n",ans);
}

