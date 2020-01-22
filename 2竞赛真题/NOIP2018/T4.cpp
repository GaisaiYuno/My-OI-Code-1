#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 5000
using namespace std;
int n,m;
vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}

int cnt=0;
int seq[maxn+5];
int ans[maxn+5];
bool vis[maxn+5];
int du,dv;
void dfs(int x){
	vis[x]=1;
	seq[++cnt]=x;
	for(int i=0;i<(int)E[x].size();i++){
		int y=E[x][i];
		if((x==du&&y==dv)||(x==dv&&y==du)) continue;
		if(vis[y]) continue;
		dfs(y);
	}
}

bool is_lower(int *a,int *b,int n){
	for(int i=1;i<=n;i++){
		if(a[i]<b[i]) return 1;
		if(a[i]>b[i]) return 0;
	}
	return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		sort(E[i].begin(),E[i].end());
	}
	if(m==n-1){
		du=dv=0;
		dfs(1);
		for(int i=1;i<=cnt;i++) printf("%d ",seq[i]);
	}else{
		for(int i=1;i<=n;i++) ans[i]=n+1;
		for(int x=1;x<=n;x++){
			for(int j=0;j<(int)E[x].size();j++){
				int y=E[x][j];
				du=x;
				dv=y;
				if(du>dv) continue;
				cnt=0;
				for(int i=1;i<=n;i++) vis[i]=0;
				dfs(1);
				if(cnt==n&&is_lower(seq,ans,n)){
					for(int i=1;i<=n;i++) ans[i]=seq[i];
				}
			} 
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
}

