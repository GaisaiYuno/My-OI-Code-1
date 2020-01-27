#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int n,q;
namespace brute_force{
	struct edge{
		int from;
		int to;
		int next;
		int len;
	}E[maxn*2+5];
	int head[maxn+5];
	int sz=1;
	void add_edge(int u,int v,int w){
		sz++;
		E[sz].from=u;
		E[sz].to=v;
		E[sz].next=head[u];
		E[sz].len=w;
		head[u]=sz;
	}
	bool flag=false;
	int vis[maxn*2+5];
	void dfs(int x,int t,int d){
		if(flag) return;
		if(x==t){
			if(d==0) flag=true;
//			return;
		}
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!vis[i]){
				vis[i]=1;
				dfs(y,t,d^E[i].len);
				vis[i]=0;
			}
		}
	}
	void solve(){
		int w,x,y,z;
		for(int i=1;i<=q;i++){
			scanf("%d %d %d %d",&w,&x,&y,&z);
			if(w==1){
				add_edge(x,y,z&1);
				add_edge(y,x,z&1);
			}else{
				flag=false;
				dfs(x,y,0);
				if(flag) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
}

namespace test_sol{
	int fa[maxn+5];
	int d[maxn+5];//到代表元素的距离，偶环距离等价于树，奇环距离无意义 
	void ini(){
		for(int i=1;i<=n;i++){
			 fa[i]=i;
			 d[i]=0;
		}
	}
	int find(int x){
		if(fa[x]==x) return x;
		else{
			int f=find(fa[x]);
			d[x]^=d[fa[x]];
			fa[x]=f;
			return f;
		}
	} 
	void merge(int x,int y,int z){
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy){
			d[fx]=d[x]^d[y]^z;
			fa[fx]=fy;
		}
	}
	
	bool ring1[maxn+5];//奇环
	bool ring0[maxn+5];//偶环 
	
	void add(int u,int v,int len){
		int fu=find(u);
		int fv=find(v);
		if(fu==fv){
			if(ring1[fu]==1) return;
			else if(ring0[fu]==1){
				if((d[u]^d[v]^len)==1) ring1[fu]=1;
			}else{
				if((d[u]^d[v]^len)==1) ring1[fu]=1;
				else ring0[fu]=1;
			}	
		}else{
			if(!ring1[fu]&&!ring1[fv]){
				merge(u,v,len);
			}else{
				merge(u,v,len);
				ring1[fv]=1;
			}
		}
	}
	
	bool check(int u,int v){
		int fu=find(u);
		int fv=find(v);
		if(fu==fv){
			if(!ring1[fu]&&!ring1[fv]){
				if((d[u]^d[v])==0) return 1;
				else return 0;
			}
			else{
				return 1;
			}
		}else{
			return 0;
		}
	} 
	
	void solve(){
		int w,x,y,z;
		ini();
		for(int i=1;i<=q;i++){
			scanf("%d %d %d %d",&w,&x,&y,&z);
			if(w==1){
				add(x,y,z&1);
			}else{
				if(check(x,y)) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&q);
	brute_force::solve();
}
/*
5 9
1 1 2 3
1 1 3 2
1 3 5 5
2 1 5 1
2 2 5 1
1 2 4 4
1 1 4 6
2 1 5 1
2 3 5 1

*/

