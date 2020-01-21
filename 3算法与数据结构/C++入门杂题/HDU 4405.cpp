#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
double E[maxn];
int fa[maxn];
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){

		if(n==0&&m==0) break;
		memset(E,0,sizeof(E));
		memset(fa,-1,sizeof(fa));
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			fa[u]=v;
		} 
		E[n]=0;
		for(int i=n-1;i>=0;i--){
			if(fa[i]!=-1){
				E[i]=E[fa[i]];
			}else{
				for(int j=1;j<=6;j++){
					if(i+j<=n){
						E[i]+=E[i+j]/6.0;
					}
				} 
				E[i]+=1;
			}
		}
		printf("%.4f\n",E[0]);
	}
} 
