//http://119.29.55.79/contest/95/problem/4
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
using namespace std;
int n,m;
struct disjoint_set{
	int fa[maxn+5];
	int tim[maxn+5];//记录x什么时间与父亲相连 
	int sz[maxn+5]; 
	int find(int x){
		while(fa[x]!=0) x=fa[x];
		return x;
	}
	int get_deep(int x){
		int ans=0;
		while(fa[x]!=0){
			ans++;
			x=fa[x];
		}
		return ans;
	}
	void merge(int x,int y,int t){
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			if(sz[fx]>sz[fy]) swap(fx,fy);
			fa[fx]=fy;
			tim[fx]=t; 
			sz[fy]+=sz[fx];
		}
	} 
	int query(int x,int y){//其实是跳到lca 
		int ans=0;
		if(find(x)==find(y)){
			int dx=get_deep(x),dy=get_deep(y);
			if(dx<dy){
				swap(x,y);
				swap(dx,dy);
			}
			while(dx>dy){
				ans=max(ans,tim[x]);
				x=fa[x];
				dx--; 
			}
			if(x==y) return ans; 
			while(x!=y){
				ans=max(ans,max(tim[x],tim[y]));
				x=fa[x];
				y=fa[y];
			}
			return ans;
		}else return 0; 
	}
	void ini(int n){
		for(int i=1;i<=n;i++){
			fa[i]=0;
			sz[i]=1;
		}
	}
}S;


int main(){
	int u,v,cmd;
	int last=0;
	scanf("%d %d",&n,&m); 
	int tim=0;
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&cmd,&u,&v);
		u^=last;
		v^=last;
		if(cmd==0) S.merge(u,v,++tim);
		else{
			last=S.query(u,v);
			printf("%d\n",last);
		}
	}
}
/*
5 9
0 2 5
1 2 5
*/
