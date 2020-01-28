#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
int n,m,q,fa[maxn],ans[maxn];
vector<pair<int,int> > vec[maxn];
vector<pair<int,vector<int> > > g[maxn];

void dfs0(int pos,int fa){
	sort(vec[pos].begin(),vec[pos].end());
	vec[pos].erase(unique(vec[pos].begin(),vec[pos].end()),vec[pos].end());
	for(int i=0,j,v;i<vec[pos].size();i=j){
		v=vec[pos][i].first;
		j=i+1;
		while(j<vec[pos].size()&&vec[pos][j].first==v)
			++j;
		if(v==fa)
			continue;
		g[pos].push_back(make_pair(v,vector<int>()));
		g[v].push_back(make_pair(pos,vector<int>()));
		for(int k=i;k<j&&k<i+3;++k){
			g[pos].back().second.push_back(vec[pos][k].second);
			g[v].back().second.push_back(vec[pos][k].second);
		}
		dfs0(v,pos);
	}
}
inline void chkmax(int&a,int b){if(a<b)a=b;}
namespace work{
	struct query{
		int id,x,y;
	};
	vector<query> vec[maxn];
	int size[maxn],sfa[20][maxn],sdep[maxn],dp[maxn][3][3],tmp[maxn];
	bool vis[maxn];
	void dfs1(int pos,int fa,int&rt,int tot){
		int maxson=0;
		size[pos]=1;
		for(int i=0,v;i<g[pos].size();++i)
			if(!vis[v=g[pos][i].first]&&v!=fa){
				dfs1(v,pos,rt,tot);
				size[pos]+=size[v];
				chkmax(maxson,size[v]);
			}
		if(maxson<=tot/2&&tot-size[pos]<=tot/2)
			rt=pos;
	}
	void solve0(int pos,int tot,int fa){
		dfs1(pos,0,pos,tot);
		vis[pos]=true;
		sfa[0][pos]=fa;
		sdep[pos]=sdep[sfa[0][pos]]+1;
		for(int i=1;i<20;++i)
			sfa[i][pos]=sfa[i-1][sfa[i-1][pos]];
		for(int i=0,v;i<g[pos].size();++i)
			if(!vis[v=g[pos][i].first])
				if(size[v]<=size[pos])
					solve0(v,size[v],pos);
				else
					solve0(v,tot-size[pos],pos);
	}
	inline int lca(int u,int v){
		if(sdep[u]<sdep[v])swap(u,v);
		for(int i=19;~i;--i)
			if(sdep[sfa[i][u]]>=sdep[v])
				u=sfa[i][u];
		if(u==v)
			return u;
		for(int i=19;~i;--i)
			if(sfa[i][u]!=sfa[i][v])
				u=sfa[i][u],v=sfa[i][v];
		return sfa[0][u];
	}
	vector<int> vfa[maxn];
	void dfs2(int pos,int fa,int rt){
		tmp[pos]=rt;
		for(int i=0,v;i<g[pos].size();++i)
			if(!vis[v=g[pos][i].first]&&v!=fa){
				vfa[v]=g[pos][i].second;
				for(int j=0;j<vfa[rt].size();++j)
					for(int k=0;k<vfa[v].size();++k){
						dp[v][j][k]=-1e9;
						for(int l=0;l<vfa[pos].size();++l)
							chkmax(dp[v][j][k],dp[pos][j][l]+(vfa[pos][l]!=vfa[v][k]));
					}
				dfs2(v,pos,rt);
			}
	}
	void solve(int pos,int tot){
		dfs1(pos,0,pos,tot);
		vis[pos]=true;
		for(int i=0,v;i<g[pos].size();++i)
			if(!vis[v=g[pos][i].first]){
				vfa[v]=g[pos][i].second;
				for(int j=0;j<vfa[v].size();++j)
					for(int k=0;k<vfa[v].size();++k)
						dp[v][j][k]=j==k?0:-1e9;
				dfs2(v,pos,v);
			}
		for(int i=0;i<vec[pos].size();++i){
			int x=vec[pos][i].x,y=vec[pos][i].y;
			if(y==pos)
				swap(x,y);
			if(x==y)
				ans[vec[pos][i].id]=0;
			else if(x==pos){
				for(int j=0;j<vfa[tmp[y]].size();++j)
					for(int k=0;k<vfa[y].size();++k)
						chkmax(ans[vec[pos][i].id],dp[y][j][k]);
				++ans[vec[pos][i].id];
			}
			else{
				for(int j=0;j<vfa[x].size();++j)
					for(int k=0;k<vfa[tmp[x]].size();++k)
						for(int l=0;l<vfa[tmp[y]].size();++l)
							for(int m=0;m<vfa[y].size();++m)
								chkmax(ans[vec[pos][i].id],dp[x][k][j]+dp[y][l][m]+(vfa[tmp[x]][k]!=vfa[tmp[y]][l]));
				++ans[vec[pos][i].id];
			}
		}
		for(int i=0,v;i<g[pos].size();++i)
			if(!vis[v=g[pos][i].first])
				if(size[v]<=size[pos])
					solve(v,size[v]);
				else
					solve(v,tot-size[pos]);
	}
	int main(){
		solve0(1,n,0);
		scanf("%d",&q);
		for(int i=1,u,v;i<=q;++i){
			scanf("%d%d",&u,&v);
			vec[lca(u,v)].push_back((query){i,u,v});
		}
		memset(vis,false,sizeof(vis));
		solve(1,n);
		for(int i=1;i<=q;++i)
			printf("%d\n",ans[i]);
	}
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		vec[u].push_back(make_pair(v,w));
		vec[v].push_back(make_pair(u,w));
	}
	dfs0(1,0);
	work::main();
	return 0;
}
