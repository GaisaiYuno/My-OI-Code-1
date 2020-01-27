//http://119.29.55.79/contest/88/problem/1 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 100
#define maxm 500
using namespace std;
int n,m;
int w0[maxn+5],v0[maxn+5];
int w[maxn+5],v[maxn+5];

vector<int>G[maxn+5],T[maxn+5];
int cnt;
namespace Tarjan{
	int tim;
	int dfn[maxn+5];
	int low[maxn+5];
	int bel[maxn+5];
	bool ins[maxn+5];
	stack<int>stk;
	void tarjan(int x){
	    low[x]=dfn[x]=++tim;
	    stk.push(x);
	    ins[x]=1; 
	    for(int y : G[x]){
	        if(!dfn[y]){
	            tarjan(y);
	            low[x]=min(low[x],low[y]);
	        }else if(ins[y]){
	            low[x]=min(low[x],dfn[y]);
	        }
	    }
	    if(dfn[x]==low[x]){
	        int y;
	        cnt++;
	        do{
	            y=stk.top();
	            stk.pop();
	            bel[y]=cnt;
	            ins[y]=0;
	        }while(y!=x);
	    }
	}
	
	int in[maxn+5];
	void graph_to_tree(){
	    for(int i=1;i<=n;i++){
	        if(!dfn[i]) tarjan(i);
	    }
	    for(int i=1;i<=n;i++){
			w[bel[i]]+=w0[i];
			v[bel[i]]+=v0[i];
	    }
	    for(int i=1;i<=n;i++){
	    	for(int j : G[i]){
	    		if(bel[i]!=bel[j]){
	    			T[bel[i]].push_back(bel[j]);
//	    			printf("%d->%d\n",bel[i],bel[j]);
	    			in[bel[j]]++;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			if(!in[i]){
//				printf("%d->%d\n",0,i);
				T[0].push_back(i);
			}
		}
	}
} 

int tim;
int pre[maxn+5];
int dfn[maxn+5],hash_dfn[maxn+5],nex[maxn+5];
int dp[maxn+5][maxm+5];
void dfs(int x){
	dfn[x]=tim++;
	hash_dfn[dfn[x]]=x;
	for(int y : T[x]){
		pre[y]=pre[x]+w[x];
		dfs(y);
	}
	nex[dfn[x]]=tim;
}

int main(){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w0[i]);
	for(int i=1;i<=n;i++) scanf("%d",&v0[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(x!=0)G[x].push_back(i);
	}
	Tarjan::graph_to_tree();
	dfs(0);
//	for(int i=0;i<=cnt;i++){
//		printf("%d: (%d,%d)\n",i,w[i],v[i]);
//	}
	for(int i=0;i<=cnt;i++){
		int x=hash_dfn[i];
		for(int j=pre[x];j+w[x]<=m;j++){
			dp[i+1][j+w[x]]=max(dp[i+1][j+w[x]],dp[i][j]+v[x]);
		}
		for(int j=pre[x];j<=m;j++){
			dp[nex[i]][j]=max(dp[nex[i]][j],dp[i][j]);
		}
	} 
	int ans=dp[cnt+1][m];
//	for(int i=1;i<=cnt;i++) ans=max(ans,dp[i][m]);
	printf("%d\n",ans);
}
