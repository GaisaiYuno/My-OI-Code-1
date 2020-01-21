//http://119.29.55.79/contest/86/problem/1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
#define maxv 20000
#define INF 0x3f3f3f3f
using namespace std;
int n,T; 
int v[maxn+5],c[maxn+5];
int f[maxv+5];//付钱的最小硬币数，完全背包 
int g[maxv+5]; //找钱的最小硬币数，完全背包 
int main(){
	scanf("%d %d",&n,&T);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	memset(g,0x3f,sizeof(g));
	g[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=v[i];j<=maxv;j++){
			g[j]=min(g[j],g[j-v[i]]+1);
		}
	} 
	
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=maxv;j>=v[i];j--){
			for(int k=1;k<=c[i]&&v[i]*k<=j;k++){
				f[j]=min(f[j],f[j-v[i]*k]+k);
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=maxv;i++){
		if(i-T>=0&&f[i]!=INF&&g[i-T]!=INF) ans=min(ans,f[i]+g[i-T]);
	}
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
} 
