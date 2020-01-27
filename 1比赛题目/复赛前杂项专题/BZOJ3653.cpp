#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 300000
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int head[maxn+5];
int esz=1;
void add_edge(int u,int v){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].next=head[u];
	head[u]=esz;
}
int sz[maxn+5];
int deep[maxn+5];
int maxd[maxn+5];
int fa[maxn+5],son[maxn+5];
void dfs1(int x,int f){
	sz[x]=1;
	fa[x]=f;
	deep[x]=deep[f]+1;
	maxd[x]=max(maxd[x],deep[x]);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=f){
			dfs1(y,x);
			sz[x]+=sz[y];
			maxd[x]=max(maxd[x],maxd[y]);
			if(maxd[y]>maxd[son[x]]) son[x]=y;
		}
	}
}

struct query{
	int id;
	int k;
	query(){
		
	}
	query(int _id,int _k){
		id=_id;
		k=_k;
	}
};
vector<query>q[maxn+5];
ll ans[maxn+5];

ll tmp[maxn+5],*id=tmp;//相当于把id指向的位置及后面初始化为0 
ll* dp[maxn+5];
//dp[x][i] 对于x子树里离x深度>=i的节点y,求sum(sz[y]-1) 
void dfs2(int x){
	dp[x][0]=sz[x]-1;
	if(son[x]){//重儿子O(1)继承 
		dp[son[x]]=dp[x]+1;//dp[x][i]=sum(dp[y][i+1])
		dfs2(son[x]);
		dp[x][0]+=dp[son[x]][0]; 
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa[x]&&y!=son[x]){
			dp[y]=id;
			id+=maxd[y]-deep[y]+1;
			dfs2(y);
			for(int j=0;j<=maxd[y]-deep[y];j++) dp[x][j+1]+=dp[y][j];//轻儿子暴力合并
			dp[x][0]+=dp[y][0]; 
		}
	}
	for(int i=q[x].size()-1;i>=0;i--){
		int k=q[x][i].k;
		int num=q[x][i].id;
		ans[num]+=1ll*min(deep[x]-1,k)*(sz[x]-1);//b为a的祖先，b有min(deep[x]-1,k)种，c有(sz[x]-1) 
		if(k>=maxd[x]-deep[x]) ans[num]+=dp[x][0]-(sz[x]-1);//整个子树里的距离都<=k 
		else ans[num]+=dp[x][0]-dp[x][k+1]-(sz[x]-1);
	}
}
int main(){
	int u,v;
	qread(n);
	qread(m);
	for(int i=1;i<n;i++){
		qread(u);
		qread(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		q[u].push_back(query(i,v));
	}
	dfs1(1,0);
	dp[1]=id;
	id+=maxd[1];
	dfs2(1);
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);	
} 
