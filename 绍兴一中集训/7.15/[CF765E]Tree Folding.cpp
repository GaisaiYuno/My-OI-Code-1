#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#define maxn 200000
using namespace std;
int n;
vector<int>E[maxn+5];
int root;
int dfs(int x,int fa){
	set<int>s;
	for(int y : E[x]){
		if(y!=fa){
			int ans=dfs(y,x);
			if(ans==-1) return -1;
			s.insert(ans+1);//加上根节点 
		}
	}
	if(s.size()==0) return 0;
	else if(s.size()==1) return *s.begin();
	else if(s.size()==2&&fa==0) return *s.begin()+*(--s.end());
	else{
		root=x;
		return -1;
	}
} 
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int ans=dfs(1,0);
	if(ans==-1){
		if(root!=0){
			ans=dfs(root,0);
		}
	}
	while(ans%2==0) ans/=2;//对折
	printf("%d\n",ans); 
}
