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
	for(;x<=5000;x+=lowbit(x)) c[x]++;
}
inline int query(int x){
	int ans = 0;
	for(;x;x-=lowbit(x)) ans+=c[x];
	return ans;
}
int calc(){
	Rep(i,1,5000) c[i] = 0;
	int ans = 0;
	Rep(i,1,n){
		ans += query(5000) - query(a[i]);
		add(a[i]);
	}
	return ans;
}
int id[maxn],id2[maxn];
void F(int x){
	int T = 0;
	Rep(i,1,n){
		if(a[i] <= x){
			id[++T] = a[i];
			id2[T] = i;
		}
	}
	sort(id+1,id+1+T);
	Rep(i,1,T) a[id2[i]] = id[i];
}
int main(){
	freopen("sort.in","r",stdin);
//	freopen("sort.out","w",stdout);
	n = read();
	Q = read();
	Rep(i,1,n) a[i] = read();
	writeln(calc());
	while(Q--){
		int x = a[read()];
		F(x);
		writeln(calc());
	}
	return 0;
}
