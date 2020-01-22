#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxlogn 40
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

int n,m;
int sz;
struct point{
	int x;
	int y;
}p[maxn+5];
struct line{
	int x;
	int y1;
	int y2;
	int type;
	line(){
		
	}
	line(int _x,int _y1,int _y2,int _type){
		x=_x;
		y1=_y1;
		y2=_y2;
		type=_type;
	}
	friend bool operator < (line p,line q){
		return p.x<q.x;
	}
}a[maxn*2+5];

struct segment_tree{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs) 
	struct node{
		int l;
		int r;
		int ls;
		int rs;
		int cov;//被覆盖的标记,扫描到左侧的边+1,右侧的边-1 ,需要永久化 
		ll slen;//长度之和 
		int len(){
			return r-l+1;
		}
	}tree[maxn*maxlogn+5];
	int ptr;
	int root;
	int New(int l,int r){
		ptr++;
		tree[ptr].l=l;
		tree[ptr].r=r;
		tree[ptr].ls=tree[ptr].rs=tree[ptr].cov=tree[ptr].slen=0;
		return ptr;
	}
	void push_up(int x){
		if(tree[x].cov) tree[x].slen=tree[x].len();
		else if(tree[x].l==tree[x].r) tree[x].slen=0;
		else tree[x].slen=tree[lson(x)].slen+tree[rson(x)].slen; 
	}
	void update(int &x,int L,int R,int l,int r,int val){
		if(!x) x=New(l,r);
		if(L<=tree[x].l&&R>=tree[x].r){
			tree[x].cov+=val;
			push_up(x);
			return;
		}
		int mid=(tree[x].l+tree[x].r)>>1;
		if(L<=mid) update(tree[x].ls,L,R,l,mid,val);
		if(R>mid) update(tree[x].rs,L,R,mid+1,r,val);
		push_up(x);
	}
	void clear(){
		ptr=0;
		root=0;
	}
}T;

bool check(int mid){
	T.clear();
	sz=0;
	for(int i=1;i<=n;i++){
		int xl,xr,yl,yr;
		xl=max(p[i].x-mid,-mid);
		xr=min(p[i].x+mid,mid);
		yl=max(p[i].y-mid,-mid);
		yr=min(p[i].y+mid,mid);
		if(xl>xr||yl>yr) continue;
		a[++sz]=line(xl,yl,yr,1);
		a[++sz]=line(xr+1,yl,yr,-1);
	}
	sort(a+1,a+1+sz); 
	ll ans=0;
	for(int i=1;i<=sz;i++){
		if(i!=1) ans+=1ll*(a[i].x-a[i-1].x)*T.tree[T.root].slen;
		T.update(T.root,a[i].y1,a[i].y2,-mid,mid,a[i].type);
	}
	if(ans>=1ll*(mid*2+1)*(mid*2+1)) return 1;
	else return 0;
}
int main(){
//	freopen("1.in","r",stdin);
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		if(n==-1) break;
//		ini();
		for(int i=1;i<=n;i++){
			qread(p[i].x);
			qread(p[i].y);
		}
		int l=0,r=1e6,ans=-1,mid;
//		check(4);
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else l=mid+1; 
		} 
		printf("Case %d: ",++cas);
		if(ans==-1) printf("never\n");
		else printf("%d\n",ans);
	}
	
} 
