#include <bits/stdc++.h>
#define MAXN 100005
#define int long long
using namespace std;
struct edge{
	int to,cost;
};
vector<edge>G[MAXN];
void add_edge(int u,int v,int w){
	edge temp;
	temp.to=v;
	temp.cost=w;
	G[u].push_back(temp);
}
int vis[MAXN],dis[MAXN];
inline int read(){
	char ch=getchar();
	int x=0,f=1;
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void spfa(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	vis[s]=true;
	queue<int>Q;
    while (Q.size()) Q.pop();
	Q.push(s);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		vis[v]=false;
		for (register int i=0;i<G[v].size();++i){
			int u=G[v][i].to;
			int len=G[v][i].cost;
			if (dis[u]>dis[v]+len){
				dis[u]=dis[v]+len;
				if (!vis[u]){
					vis[u]=true;
					Q.push(u);
				}
			}
		}
	}
}
vector<int>query[MAXN];
map<pair<int,int>,int>ans;
int ask[MAXN][2];
#undef int
int main(){
#define int long long
	int n,m;
	scanf("%I64d%I64d",&n,&m);
	for (int i=0;i<m;++i){
		int u,v,w;
		scanf("%I64d%I64d%I64d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
    int q;
    scanf("%I64d",&q);
    for (int i=0;i<q;++i){
        int u,v;
        scanf("%I64d%I64d",&u,&v);
        if (u>v) swap(u,v);
        query[u].push_back(v);
        ask[i][0]=u;
        ask[i][1]=v;
    }
    for (int i=1;i<=n;++i){
        if (query[i].size()!=0){
            spfa(i);
            for (int j=0;j<query[i].size();++j){
                ans[make_pair(i,query[i][j])]=dis[query[i][j]];
            }
        }
    }
    for (int i=0;i<q;++i){
        printf("%I64d\n",ans[make_pair(ask[i][0],ask[i][1])]);
    }
}
