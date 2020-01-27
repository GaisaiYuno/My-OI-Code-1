#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#define maxn 100005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}

int n,m;
struct edge{
	int u;
	int v;
	edge(){
		
	}
	edge(int from,int to){
		u=from;
		v=to;
	}
	friend bool operator ==(edge x,edge y){
		return (x.u==x.v)&&(y.u==y.v);
	}
	friend bool operator < (edge x,edge y){
		if(x.u==y.u) return x.v<y.v;
		else return x.u<y.u; 
	}
};
map<edge,int>used1,used2;

vector<int>G[maxn];
vector<int>D[maxn];

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

int in[maxn];
int out[maxn];
void graph_to_dag(){
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		int t=G[i].size();
		for(int j=0;j<t;j++){
			int k=G[i][j];
			if(belong[i]!=belong[k]){
				if(used.count(edge(belong[i],belong[k]))) continue;
				used[edge(belong[i],belong[k])]=1;
				D[belong[i]].push_back(belong[k]);
				in[belong[k]]++;
				out[belong[i]]++;
			}
		}
	}
}


int solve(){
	int tmp=0;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(out[i]==0){
			tmp++;
			ans+=sz[i];
		}
	}
	if(tmp==1) return ans;
	else return 0;
}

int main(){
//	freopen("cow.in","r",stdin);
//	freopen("cow.out","w",stdout);
	int u,v;
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		if(u==v) continue;
		if(used1.count(edge(u,v))) continue;
		used1[edge(u,v)]=1;
		G[u].push_back(v);
	}
	graph_to_dag();
	printf("%d\n",solve());
}

