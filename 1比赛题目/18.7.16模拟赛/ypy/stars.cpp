#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 15005
#define maxx 32005
using namespace std;
int n;
struct point{
	int x;
	int y;
};
point star[maxn];
struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
	}tree[maxx<<2];
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
	void update(int tpos,int x,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v+=x;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) update(tpos,x,pos<<1);
		else update(tpos,x,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		int ans=0;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) ans+=query(L,R,pos<<1);
		if(R>mid) ans+=query(L,R,pos<<1|1);
		return ans;
	}
};
segment_tree T; 
int ans[maxn];
int main(){
	freopen("stars.in","r",stdin);
	freopen("stars.out","w",stdout);
//	freopen("stars3.in","r",stdin);
//	freopen("stars_my.out","w",stdout);
	int val;
	scanf("%d",&n);
	T.build(0,maxx-5,1);
//	int lasty=-1,lastv=-1;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&star[i].x,&star[i].y);
	    val=T.query(0,star[i].x,1);
//		printf("v=%d\n",val);
		ans[val]++;
		T.update(star[i].x,1,1);
//		lasty=star[i].y;
//		lastv=val;
	}
	
	for(int i=0;i<=n-1;i++){
		printf("%d\n",ans[i]);
	}
}
/*
5
1 1
5 1
7 1
3 3
5 5
*/
