/*

            -. .
       _____   ',' ,
     ,'     ,'   ', ',
   ,'     ,'      |  |
  \       \       |  |
    \ /^\   \    ,' ,'
          \   \ ,' ,'      L'Internationale,
    / ~-.___\.-'  ,'            Sera le genre humain.
  /   .______.- ~ \
/   /'          \   \
\./               \/'

Problem:Szk-Schools
Source:http://111.230.183.91/problem/147
Algorithm:KM
Description:直接暴力建图跑KM算法，注意无解的情况，delta的更新放在dfs外面，否则会死循环 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 205
#define INF 0x3f3f3f3f
using namespace std;
struct school{
	int old;
	int l;
	int r;
	int price;
}a[maxn];

int n,m;
int dist[maxn][maxn];
int la[maxn];
int lb[maxn];
int va[maxn];
int vb[maxn];
int match[maxn];
int delta;
int dfs(int x){
	va[x]=1;
	for(int y=1;y<=n;y++){
		if(!vb[y]&&dist[x][y]!=INF){
			if(la[x]+lb[y]==dist[x][y]){
				vb[y]=1;
				if(!match[y]||dfs(match[y])){
					match[y]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}

int KM(){
	for(int i=1;i<=n;i++){
		la[i]=-INF;
		for(int j=1;j<=n;j++){
			if(dist[i][j]!=INF)la[i]=max(la[i],dist[i][j]);
		}
		lb[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(1){
			memset(va,0,sizeof(va));
			memset(vb,0,sizeof(vb));
			delta=INF;
			if(dfs(i)) break;
			for(int j=1;j<=n;j++){
				if(!va[j]) continue;
				for(int k=1;k<=n;k++){
					if(!vb[k]&&dist[j][k]!=INF){
						delta=min(delta,la[j]+lb[k]-dist[j][k]);
					}
				}
			}
			if(delta==INF) return -1;
			for(int j=1;j<=n;j++){
				if(va[j]) la[j]-=delta;
				if(vb[j]) lb[j]+=delta;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dist[match[i]][i];
	}
	return -ans;
}

void add_edge(int u,int v,int w){
	dist[u][v]=w;
} 

int main(){
	int u,v,w;
	scanf("%d",&n);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++){
		scanf("%d %d %d %d",&a[i].old,&a[i].l,&a[i].r,&a[i].price);
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i].l;j<=a[i].r;j++){
			add_edge(i,j,-abs(a[i].old-j)*a[i].price);
		}
	}
	int ans=KM();
	if(ans!=-1) printf("%d\n",ans);
	else printf("NIE\n");
}

