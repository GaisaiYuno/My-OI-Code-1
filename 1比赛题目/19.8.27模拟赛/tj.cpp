#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
typedef long long ll;
int n,m,i,j,k,a[N],b[N],d[N],e[N],bit[N],f[N],ans0,G[N],nxt[N];
int cl,cr,L[N],R[N],top,q[N];
ll c[N],g[N],ans1=1LL<<62;
struct E {
	int x,t;
	E() {} E(int _x,int _t) {
		x=_x,t=_t;
	}
} h[N];
inline void read(int&a) {
	char c;
	while(!(((c=getchar())>='0')&&(c<='9')));
	a=c-'0';
	while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';
}
inline void umax(int&a,int b) {
	if(a<b)a=b;
}
inline void umin(ll&a,ll b) {
	if(a>b)a=b;
}
inline int lower(int x) {
	int l=1,r=n+1,mid,t;
	while(l<=r)if(e[mid=(l+r)>>1]<=x)l=(t=mid)+1;
		else r=mid-1;
	return t;
}
inline void ins(int x,int y) {
	for(; x<=n+1; x+=x&-x)umax(bit[x],y);
}
inline int ask(int x) {
	int t=-N;
	for(; x; x-=x&-x)umax(t,bit[x]);
	return t;
}
inline void add(int x,int y) {
	nxt[y]=G[x];
	G[x]=y;
}
inline bool cmp(int x,int y) {
	return d[x]==d[y]?c[x]>c[y]:d[x]<d[y];
}
inline double pos(int x,int y) {
	return 1.0*(c[y]-c[x])/(d[x]-d[y]);
}
inline void insert(int x) {
	if(top&&d[x]==d[q[top]])top--;
	while(top>1&&pos(q[top],x)>pos(q[top],q[top-1]))top--;
	q[++top]=x;
}
inline void query(int x) {
	if(!top)return;
	int l=1,r=top-1,mid,t=top;
	while(l<=r) {
		mid=(l+r)>>1;
		if(x>pos(q[mid],q[mid+1]))r=(t=mid)-1;
		else l=mid+1;
	}
	umin(g[x],1LL*x*d[q[t]]+c[q[t]]);
}
void solve(int l,int r) {
	if(l==r)return;
	int mid=(l+r)>>1,i,j;
	solve(l,mid),solve(mid+1,r);
	for(cl=0,i=l; i<=mid; i++)if(!h[i].t)L[++cl]=h[i].x;
	for(cr=0,i=r; i>mid; i--)if(h[i].t)R[++cr]=h[i].x;
	if(!cl||!cr)return;
	sort(L+1,L+cl+1,cmp),sort(R+1,R+cr+1,cmp);
	for(i=j=1,top=0; i<=cr; i++) {
		while(j<=cl&&d[L[j]]<=d[R[i]])insert(L[j++]);
		query(R[i]);
	}
}
int main() {
	read(n);
	for(i=1; i<=n; i++)read(a[i]);
	for(i=1; i<=n; i++)read(b[i]),e[i+1]=d[i]=a[i]-i;
	sort(e+1,e+n+2);
	for(i=1; i<=n+1; i++)bit[i]=-N;
	ins(lower(0),0);
	for(i=1; i<=n; i++)g[i]=ans1,j=lower(d[i]),ins(j,f[i]=ask(j)+1);
	ans0=ask(n+1);
	for(i=0; i<=n; i++)G[i]=-1;
	for(i=n; ~i; i--)if(f[i]>=0)add(f[i],i);
	for(i=0; i<ans0; i++) {
		j=G[i],k=G[i+1],m=0;
		while(~j||~k) {
			if(j<0)h[++m]=E(k,1),k=nxt[k];
			else if(k<0||j<k)h[++m]=E(j,0),j=nxt[j];
			else h[++m]=E(k,1),k=nxt[k];
		}
		solve(1,m);
		for(k=G[i+1]; ~k; k=nxt[k]) {
			g[k]+=b[k]+a[k]+1LL*k*(k-1)/2;
			c[k]=g[k]+1LL*k*(k+1)/2-1LL*a[k]*k-a[k];
		}
	}
	for(i=0; i<=n; i++)if(f[i]==ans0)umin(ans1,g[i]+1LL*(n-i)*a[i]+1LL*(n-i)*(n-i+1)/2);
	return printf("%d %lld",ans0,ans1),0;
}
