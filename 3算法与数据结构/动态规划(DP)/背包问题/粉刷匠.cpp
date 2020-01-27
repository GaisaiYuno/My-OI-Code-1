////http://119.29.55.79/contest/86/problem/3 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50
#define maxt 2500 
using namespace std;
int n,m,T;
int a[maxn+5];
int cnt0[maxn+5],cnt1[maxn+5]; 
int g[maxn+5][maxt+5];
void get_g(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=T;j++) g[i][j]=0; 
	}
	for(int i=1;i<=m;i++){
		cnt0[i]=cnt0[i-1]+(a[i]==0);
		cnt1[i]=cnt1[i-1]+(a[i]==1);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<i;k++){
				g[i][j]=max(g[i][j],g[k][j-1]+max(cnt0[i]-cnt0[k],cnt1[i]-cnt1[k]));
			}
		}
	}
}
int f[maxt+5];
int main(){
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%1d",&a[j]);
		get_g();
		for(int j=T;j>=0;j--){
			for(int k=0;k<=m;k++){
				if(j-k>=0) f[j]=max(f[j-k]+g[m][k],f[j]); 
			}
		}
	}
	printf("%d\n",f[T]); 
}
