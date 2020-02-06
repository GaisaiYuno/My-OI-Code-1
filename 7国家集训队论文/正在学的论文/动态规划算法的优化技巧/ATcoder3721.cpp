//https://www.cnblogs.com/Sakits/p/8027335.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 3000000
#define mod 1145141
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
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod; 
		k>>=1;
	}
	return ans;
}
const ll inv2=fast_pow(2,mod-2);

int n;
struct edge {
	int from;
	int to;
	int next;
} E[maxn*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

struct node {
	ll f[3];//一个三元组存储dp值 
	node() {

	}
	node(ll x,ll y,ll z) {
		f[0]=x;
		f[1]=y;
		f[2]=z;
	}
	inline ll& operator [] (int i) {
		return f[i];
	}
};
vector<node>v[maxn+5];
int id[maxn+5];
void merge(int x,int y) {//启发式合并节点 
	if(v[id[x]].size()<v[id[y]].size()) swap(id[x],id[y]);
	x=id[x];
	y=id[y];
	int nx=v[x].size()-1,ny=v[y].size()-1;
	for(int i=0; i<=ny; i++) {
		ll sum0,sum1,sum2=0;
		int tx=nx-i,ty=ny-i;//注意dp数组是倒序存储的 
		sum0=v[x][tx][0]*v[y][ty][0]%mod;//合并的dp方程见博客正文 
		sum1=(v[x][tx][1]*v[y][ty][0]+v[x][tx][0]*v[y][ty][1])%mod;
		for(int j=0; j<=2; j++) {
			for(int k=2; j+k>=2; k--) {
				sum2=(sum2+v[x][tx][j]*v[y][ty][k]%mod)%mod;
			}
		}
		v[x][tx]=node(sum0,sum1,sum2);
	}
	v[y].clear();
}
int ptr;
void dfs(int x) {
	if(!head[x]) id[x]=++ptr;//叶子节点才分配 
	int maxd=0;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		dfs(y);
		if(!id[x]) id[x]=id[y];//类似长链剖分,直接继承某一个节点 
		else {
			maxd=max(maxd,min((int)v[id[x]].size(),(int)v[id[y]].size()));//记录一下距x的最大深度，方便转移 
			merge(x,y);
		}

	}
	int nx=v[id[x]].size()-1;
	for(int i=0; i<maxd; i++) {
		v[id[x]][nx-i][0]=(v[id[x]][nx-i][0]+v[id[x]][nx-i][2])%mod;
		v[id[x]][nx-i][2]=0;
	}
	v[id[x]].push_back(node(inv2,inv2,0));//加入当前节点的状态 
}
int main() {
	int f;
	qread(n);
	for(int i=1; i<=n; i++) {
		qread(f);
		add_edge(f,i);
	}
	dfs(0);
	ll ans=0;
	for(int i=0;i<(int)v[id[0]].size();i++) (ans=ans+v[id[0]][i][1]);
	ans=ans*fast_pow(2,n+1)%mod;
	printf("%lld\n",ans);
}

