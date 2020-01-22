#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#define maxn 500005
using namespace std;
int n,m;
vector<int>peo[maxn];
int gsz[maxn];
vector<int>E[maxn]; 

int fa[maxn];
int sz[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	fa[fy]=fx;
	sz[fx]+=sz[fy];
}

int main(){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		sz[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&gsz[i]);
		for(int j=1;j<=gsz[i];j++){
			scanf("%d",&x);
			peo[i].push_back(x);
		}
		for(int j=0;j<gsz[i]-1;j++){
			merge(peo[i][j],peo[i][j+1]);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",sz[find(i)]);
	}
}

