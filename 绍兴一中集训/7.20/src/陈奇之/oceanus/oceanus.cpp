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
}
int over;
void pre(){
	sort(b+1,b+1+m);reverse(b+1,b+1+m);
	A[0] = b[1];dep[0] = 0;
	dfs(1);//A表示一开始的值 
	Rep(i,1,n) id[i] = i;
	sort(id+1,id+1+n,cmp);
	memset(vis,0,sizeof(vis));
	over = 0;
	vis[0] = true;
	Rep(i,1,m){
		int x = id[i];
		if(A[x] >= b[i]) vis[x] = 1;
		else{over = i;break; }
	}
	if(over == 0) gg(0);
}
const int maxm = 6e5+233;
int y[maxm];
namespace Seg{
	int T[maxm<<2],tag[maxm<<2];
	#define lson (o<<1)
	#define rson (o<<1|1)
	inline void modify(int o,int l,int r,int x,int y,int v){
		if(l==x&&r==y){
			tag[o]+=v;T[o]+=v;
			return ;
		}
		int mid = (l+r)>>1; 
		if(y<=mid) modify(lson,l,mid,x,y,v); else
		if(mid+1<=x) modify(rson,mid+1,r,x,y,v); else
		modify(lson,l,mid,x,mid,v),modify(rson,mid+1,r,mid+1,y,v);
		T[o] = min(T[lson],T[rson])+tag[o];
	}
	void add(int x,int v){
		modify(1,1,*y,1,x,v);
	}
	int querymn(){
		return T[1];
	}
}using Seg::add;
using Seg::querymn;
int main(){
	freopen("oceanus.in","r",stdin);
	freopen("oceanus.out","w",stdout);
	input();
	pre();
//	Rep(i,1,n) printf("%d ",A[i]);puts("");
//	Rep(i,1,n) printf("%d ",b[i]);puts("");
	Rep(i,1,n)if(!vis[i]&&vis[fa[i]]){
		B[i]=A[fa[i]];
		Rep(j,in[i]+1,out[i]){
			int x = dfx[j];
			B[x]=min(B[fa[x]],w[x]);
		}
	}
	Rep(i,over,m) y[++*y] = b[i];
	Rep(i,1,n) if(!vis[i]){
		y[++*y] = A[i];
		y[++*y] = B[i];
	}
	sort(y+1,y+1+*y);
	*y = unique(y+1,y+1+*y) - y - 1; 
#define find(x) (lower_bound(y+1,y+1+*y,x) - y)
	Rep(i,over,m) add(find(b[i]),-1);//b[i]增加1的需求 
	Rep(i,1,n) if(!vis[i]) add(find(A[i]),1);//A[i]增加1的供应 
	Rep(t,1,n){int i = id[t];
		if(!vis[i]&&vis[fa[i]]){
			Rep(j,in[i],out[i]){
				int x = dfx[j];
				t1[j] = find(A[x]),t2[j] = find(B[x]);
				add(t1[j],-1);
				add(t2[j],1);
			}
			if(querymn() >= 0) gg(b[over] - w[i]);
			Rep(j,in[i],out[i]){
				int x = dfx[j];
				add(t2[j],-1);
				add(t1[j],1);
			}
		}
	}
	gg(-1);
	return 0;
}
//1 2 3  4  5
//5 4 4 -1 -2
/*
对于所有情况
我需要保证
对于b[i]为需求
那么就是b[i]~INF要减小1
对于所有都这样弄一便
然后就是a[i]为供应
那么就是a[i]~INF要增加1,
所有都这样弄一次 
*/

