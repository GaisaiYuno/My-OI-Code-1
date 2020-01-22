#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#define maxn 200005
using namespace std;
int n; 
vector<int>G[maxn];
int tim=0;
int cnt=0;
int dfn[maxn];
int low[maxn];
int ins[maxn];
int sz[maxn];
int belong[maxn];
stack<int>s;
void tarjan(int x){
	s.push(x);
	ins[x]=1;
	dfn[x]=low[x]=++tim;
	int t=G[x].size();
	for(int i=0;i<t;i++){
		int y=G[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		int y;
		do{
			y=s.top();
			s.pop();
			ins[y]=0;
			sz[cnt]++;
			belong[y]=cnt;
		}while(x!=y);
	}
}

int main(){
	scanf("%d",&n);
	int t;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		G[i].push_back(t);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	int ans=n;
	for(int i=1;i<=cnt;i++){
		if(sz[i]>1) ans=min(ans,sz[i]);
	}
	printf("%d\n",ans);
} 
