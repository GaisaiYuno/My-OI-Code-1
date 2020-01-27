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
	for(;x<=1000;x+=lowbit(x)) c[x]++;
}
inline int query(int x){
	int ans = 0;
	for(;x;x-=lowbit(x)) ans+=c[x];
	return ans;
}
int main(){
	srand(time(NULL));
	freopen("sort.in","w",stdout);
//	freopen("sort.out","w",stdout);
	n = 2000,Q = 2000;
	writeln(n);
	writeln(Q);
	Rep(i,1,n){
		printf("%d ",rand() % 5000 + 1);
	}puts("");
	Rep(i,1,Q){
		int x = rand() % n + 1;
		writeln(x);
	}
	return 0;
}
