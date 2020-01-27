#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define gc getchar
#define pc putchar
inline ll read(){
    ll x=0,f=1;char c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
inline void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);pc('\n');}
#define debug(x) cout << #x" = " << (x) << endl
const int maxn = 2e5+233;
const int inf = 1e8;
vector<int> edge[maxn];
int w[maxn],b[maxn],A[maxn],B[maxn];
int n,m,vis[maxn],dep[maxn],id[maxn];
int fa[maxn],in[maxn],out[maxn],dfx[maxn],dfsclk=0;
int t1[maxn],t2[maxn];
void dfs(int u){
	A[u] = min(A[fa[u]],w[u]);
	dep[u] = dep[fa[u]] + 1;
	in[u] = ++dfsclk;
	dfx[dfsclk] = u;
	for(unsigned i=0;i<edge[u].size();++i){
		int v=edge[u][i];
		if(v==fa[u]) continue;
		fa[v] = u;
		dfs(v);
	}
	out[u] = dfsclk;
}

bool cmp(int a,int b){
	return A[a] > A[b] || (A[a] == A[b] && dep[a] < dep[b]);
}
inline void gg(int x){
	writeln(x);
	exit(0);
}
int a[maxn];
bool check(){
	Rep(i,1,n) a[i] = A[i];
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	Rep(i,1,m) if(b[i]>a[i]) return false;
	return true;
}
void input(){
	n = read();
	Rep(i,1,n) w[i] = read();
	rep(i,1,n){
		int a = read(),b = read();
		edge[a] . push_back(b),edge[b] . push_back(a);
	}
	m = read();
	if(m>n) gg(-1);
	Rep(i,1,m) b[i] = read();
	sort(b+1,b+1+m);reverse(b+1,b+1+m);
	A[0]=b[1];dfs(1);
}
int main(){
	freopen("oceanus.in","r",stdin);
	//freopen("std.out","w",stdout);
	input();
	if(check()) gg(0);
	Rep(may,1,300){
		Rep(i,1,n){
			w[i] += may;
			#define x dfx[j]
			Rep(j,1,n) A[x] = min(A[fa[x]],w[x]);
			if(check()) gg(may);
			w[i] -= may;
		}
	}
	gg(-1);
}
