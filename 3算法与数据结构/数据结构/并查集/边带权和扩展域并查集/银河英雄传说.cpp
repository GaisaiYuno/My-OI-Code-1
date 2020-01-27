//http://119.29.55.79/problem/303
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
using namespace std;
const int n=30000;
int m; 
int fa[maxn+5];
int sz[maxn+5];
int d[maxn+5];

int find(int x){
	if(fa[x]==x) return x;
	int root=find(fa[x]);
	d[x]+=d[fa[x]];
	fa[x]=root;
	return root;
}

void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		d[fx]=sz[fy];
		sz[fy]+=sz[fx];
	}
}

void ini(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
}

char cmd[2];
int main(){
	int x,y;
	ini(n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s %d %d",cmd,&x,&y);
		if(cmd[0]=='M'){
			merge(x,y);		
		}else{
			int fx=find(x);
			int fy=find(y);
			if(fx!=fy) printf("-1\n");
			else{
				printf("%d\n",abs(d[x]-d[y])-1);
			}
		}
	}
}
