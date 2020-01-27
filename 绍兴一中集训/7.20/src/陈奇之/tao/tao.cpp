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
const int maxn = 4e5+233;
struct node{
	int x,y,z;
	bool operator < (const node &w) const{
		return x > w.x || (x==w.x && y < w.y) || (x==w.x && y==w.y && z < w.z);
	}
}a[maxn];
int n,Q,c[maxn];
int v[maxn],ans[maxn];
#define lowbit(x) ((x & -x))
inline void add(int x,int vv){
	for(;x<maxn;x+=lowbit(x)) v[x]=max(v[x],vv);
}
inline int query(int x){
	int ans = 0;
	for(;x;x-=lowbit(x)) ans=max(ans,v[x]);
	return ans;
}
int main(){
//	freopen("tao.in","r",stdin);
//	freopen("tao.out","w",stdout);
	n = read(),Q = read();
	Rep(i,1,n){
		a[i].x = read(),a[i].y = read(),a[i].z = 0;
		c[i]=a[i].y;
	}
	Rep(i,1,Q){
		a[n+i].x = read(),a[n+i].y = read(),a[n+i].z = i;
	}
	sort(c+1,c+1+n);
	int sz= unique(c+1,c+1+n)-c-1;
	sort(a+1,a+1+n+Q);
	Rep(i,1,n+Q){
		a[i].y = upper_bound(c+1,c+sz+1,a[i].y)-c-1;
		if(a[i].z) ans[a[i].z] = query(a[i].y);
		else add(a[i].y,query(a[i].y) + 1);
	}
	Rep(i,1,Q) writeln(ans[i]);
	return 0;
}
/*
7 3
9 5
3 7
10 6
5 10
2 6
10 10
4 1
10 5
3 5
3 9
*/

