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
const int maxn = 3e5+233;
int a[maxn],y[maxn];
int n,Q;
vector<int> vec[maxn];
int c[maxn],ans[maxn];
ll f[maxn];
#define lowbit(x) ((x & -x))
#define debug(x) cout << #x" = " << x << endl
inline void add(int x){
	for(;x<=n;x+=lowbit(x))
		c[x]++;
}
inline int query(int x){
	int ans = 0;
	for(;x;x-=lowbit(x)) ans+=c[x];
	return ans;
}
inline int find(int x,int lim){
	if(a[x] > lim) return a[x];
	return 0; 
	//小于等于lim的都已经被over掉了 
}//第x个数是多少？？woc这TM真的能做吗 
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	n = read(),Q = read();
	Rep(i,1,n){
		a[i] = read();
		y[++*y] = a[i];
	}sort(y+1,y+1+*y);
	*y = unique(y+1,y+1+*y) - y - 1;
	Rep(i,1,n) a[i] = lower_bound(y+1,y+1+*y,a[i]) - y;
	Rep(i,1,n) vec[a[i]] . push_back(i);
	f[0] = 0;
	Rep(i,1,*y){
		f[i] = f[i-1];
		for(unsigned j=0;j<vec[i].size();++j)
			f[i] += query(n) - query(vec[i][j]);
		for(unsigned j=0;j<vec[i].size();++j)
			add(vec[i][j]); 
	}
	ll ans = f[*y];
	int mx = 0;
	writeln(ans);
	while(Q--){
		int x = read();
		x = find(x,mx);
		mx = max(mx,x);
		writeln(ans - f[mx]);
	}
	return 0;
}

/*
i < j
a[i] > a[j]


现在的问题是，对于所有a[i] > a[j]的i,j
有多少i < j

f[i]表示只考虑小于等于i的这些数字，逆序対的个数是多少 
*/
