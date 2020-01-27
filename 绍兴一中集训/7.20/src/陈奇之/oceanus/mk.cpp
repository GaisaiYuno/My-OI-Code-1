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
inline void wri(ll x){write(x);pc(' s');}
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


inline int ran(){
	return (rand() << 15 | rand());
}
void input(){
	int L = 1e8;
	n = 2e5;
	writeln(n);
	Rep(i,1,n) w[i] = ran() % L + 1;
	Rep(i,1,n) wri(w[i]);puts("");
	rep(i,1,n){
		int a = i + 1,b = rand() % i + 1;
		wri(a),writeln(b);
		edge[a] . push_back(b);
		edge[b] . push_back(a);
	}
	w[1]+=100;
	A[0]=1e8;dfs(1);
	//m = rand() % (n+2) + 1;
	m = 2e5;
	writeln(m);
//	if(m>n) gg(-1);
	Rep(i,1,n) b[i] = A[i];// + ran() % 50 - 25;
	Rep(i,1,n) b[i] = max(b[i],1);
	Rep(i,1,n) b[i] = min(b[i],L);
	random_shuffle(b+1,b+1+n);
	Rep(i,1,m) wri(b[i]);puts("");
}
int main(){
	srand(time(NULL));
	freopen("oceanus.in","w",stdout);
	input();
}
