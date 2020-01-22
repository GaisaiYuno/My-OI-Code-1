//http://119.29.55.79/problem/567
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000 
#define INF 0x3f3f3f3f
using namespace std;

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
int a[maxn+5],b[maxn+5];
struct segment_tree{
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)
	struct node{
		int l;
		int r;
		int x;//当前区间左端点选的是a的时候，右端点的最小值 
		int y;//当前区间左端点选的是b的时候，右端点的最小值
	}tree[maxn*4+5];
	void push_up(int pos){
		int mid=(tree[pos].l+tree[pos].r)>>1;
		tree[pos].x=tree[pos].y=INF;
		if(tree[lson(pos)].x<=a[mid+1]) tree[pos].x=tree[rson(pos)].x;
		else if(tree[lson(pos)].x<=b[mid+1]) tree[pos].x=tree[rson(pos)].y;
		if(tree[lson(pos)].y<=a[mid+1]) tree[pos].y=tree[rson(pos)].x;
		else if(tree[lson(pos)].y<=b[mid+1]) tree[pos].y=tree[rson(pos)].y;
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].x=a[l];
			tree[pos].y=b[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos); 
	}

	void update(int upos,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].x=a[tree[pos].l];
			tree[pos].y=b[tree[pos].l];
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,pos<<1);
		else update(upos,pos<<1|1);
		push_up(pos);
	}

}T;

bool check(int x,int y){
	swap(a[x],a[y]);
	swap(b[x],b[y]);
	T.update(x,1);
	T.update(y,1);
	return T.tree[1].x!=INF||T.tree[1].y!=INF;
}
int main(){
	int x,y;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		qread(b[i]);
		if(a[i]>b[i]) swap(a[i],b[i]);
	}
	T.build(1,n,1);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		if(check(x,y)) puts("TAK");
		else puts("NIE");
	}
}
