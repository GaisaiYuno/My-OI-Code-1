#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200000 
using namespace std;
struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].v=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1); 
	}
	void update(int upos,int uval,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=uval;//相同坐标的点只算1次，因为经过它的直线x=l只有1条 
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1; 
		if(upos<=mid) update(upos,uval,pos<<1);
		else update(upos,uval,pos<<1|1);
		push_up(pos); 
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=0;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
}T;

struct point{
	int x;
	int y;
	point(){
		
	}
	point(int _x,int _y){
		x=_x;
		y=_y;
	} 
	friend bool operator < (point p,point q){
		if(p.y==q.y) return p.x<q.x;
		else return p.y>q.y;
	}
}a[maxn+5];
int b[maxn+5];
int n,xn,y_n;
int tmp[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i].x;
	sort(tmp+1,tmp+1+n);
	xn=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i].x=lower_bound(tmp+1,tmp+1+xn,a[i].x)-tmp; 
	for(int i=1;i<=n;i++) tmp[i]=a[i].y;
	sort(tmp+1,tmp+1+n);
	y_n=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i].y=lower_bound(tmp+1,tmp+1+y_n,a[i].y)-tmp; 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	discrete();
	sort(a+1,a+1+n);
	long long ans=0;
	T.build(1,xn+1,1);
	int l=1,r=1;
	while(l<=n){
		while(a[r].y==a[l].y){
			T.update(a[r].x,1,1);
			b[r]=a[r].x;
			r++;
		}
		b[r]=xn+1;
		for(int i=l;i<r;i++){
			//该层最右端的新点为b[i] 
			long long cntl=T.query(1,b[i]-1,1);
			long long cntr=T.query(b[i]+1,b[i+1]-1,1);
			ans+=(cntl+1)*(cntr+1);//还要加上本身 
		}
		l=r;
	}
	printf("%I64d\n",ans);
}

