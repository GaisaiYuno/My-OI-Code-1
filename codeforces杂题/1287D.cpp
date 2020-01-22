//转换思路，求每个点的值在所有值中的排名 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 2000
using namespace std;
int n;
int c[maxn+5];
vector<int>E[maxn+5];
vector<int>seq[maxn+5];//按照值从小到大存储子树中点的编号 
inline void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}
void merge(vector<int>&x,vector<int>&y){
	for(int tmp : y) x.push_back(tmp); 
}
void dfs(int x,int fa){
	for(int y : E[x]){
		if(y!=fa){	 
			dfs(y,x);
			merge(seq[x],seq[y]); 
		} 
	}
//	sort(seq[x].begin(),seq[x].end()); 
	if(seq[x].size()<c[x]){
		printf("NO\n");
		exit(0);
	}
	seq[x].insert(seq[x].begin()+c[x],x);
} 

int ans[maxn+5];
int main(){
	int f,root=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&f,&c[i]);
		if(f==0) root=f;
		add_edge(f,i);
	}
	dfs(root,0);
	printf("YES\n"); 
	for(int i=0;i<(int)seq[root].size();i++) ans[seq[root][i]]=i+1;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}

