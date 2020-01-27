#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1000000
using namespace std;
int t,n;
struct Tree{
	int sz;
	vector<int>E[maxn+5];
	vector<int>f;
	vector<int>d;
	int maxf;
	int maxd;
	int root;
	void dfs(int x,int fa){
		f[x]=d[x]=0;
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			if(y!=fa){
				dfs(y,x);
				f[x]=max(f[x],max(f[y],d[x]+1+d[y]));
				d[x]=max(d[x],d[y]+1);
			}
		}
	}
	void get_d(){
		dfs(root,0);
		maxf=f[root];
		maxd=d[root];
	}
	void clear(){
		maxf=maxd=root=0;
		f.resize(sz+1);
		d.resize(sz+1);
		for(int i=1;i<=sz;i++){
			E[i].clear();
			f[i]=d[i]=0;
		}
	}
	void add_edge(int u,int v){
		E[u].push_back(v);
		E[v].push_back(u);
	}
}T[maxn+5];

bool cmp1(int x,int y){
	if(T[x].maxf==T[y].maxf) return T[x].maxd>T[y].maxd;
	else return T[x].maxf>T[y].maxf;
}
bool cmp2(int x,int y){
	if(T[x].maxf==T[y].maxf) return T[x].maxd<T[y].maxd;
	else return T[x].maxf<T[y].maxf;
}

int p[maxn+5];

int ff[maxn+5];
int dd[maxn+5];
void merge(int x,int fa,int ta,int tb){//ta*tb 
	ff[x]=0;
	dd[x]=0;
	for(int i=0;i<T[ta].E[x].size();i++){
		int y=T[ta].E[x][i];
		if(y!=fa){
			merge(y,x,ta,tb);
			ff[x]=max(ff[x],max(ff[y],dd[x]+1+dd[y]));
			dd[x]=max(dd[x],dd[y]+1);
		}
	} 
	ff[x]=max(ff[x],dd[x]+T[tb].maxd);
	dd[x]=max(dd[x],T[tb].maxd);
}
int main(){
	int x;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&T[i].sz);
			T[i].clear();
			for(int j=1;j<=T[i].sz;j++){
				scanf("%d",&x);
				if(x!=0) T[i].add_edge(j,x);
				else T[i].root=j;
			}
		}
		for(int i=1;i<=n;i++){
			T[i].get_d();
		}
		
		for(int i=1;i<=n;i++) p[i]=i;
		sort(p+1,p+1+n,cmp1);
		for(int i=1;i<n;i++){
			merge(T[i].root,0,i,i+1);
		}
		printf("%d ",ff[T[n-1].root]);
		
		for(int i=1;i<=n;i++) p[i]=i;
		sort(p+1,p+1+n,cmp2);
		for(int i=1;i<n;i++){
			merge(T[i].root,0,i,i+1);
		}
		printf("%d ",ff[T[n-1].root]);
		printf("\n");
	}
}

