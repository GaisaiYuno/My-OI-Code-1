#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500005
using namespace std;
int n,m;
struct peo {
	int x;
	int y;
	int z;
} p[maxn];
int cmp1(peo a,peo b) {
	return a.x<b.x;
}
int cmp2(peo a,peo b) {
	return a.y>b.y;
}
struct node {
	int l;
	int r;
	int v;
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void update(int tpos,int x,int pos) {
	if(tree[pos].l==tree[pos].r) {
		tree[pos].v=x;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) update(tpos,x,pos<<1);
	else update(tpos,x,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans=max(ans,query(L,R,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
	return ans;
}
int dis[maxn];//离散化
void discrete() {
	sort(dis+1,dis+1+n);
	m=unique(dis+1,dis+1+n)-dis-1;
	for(int i=1; i<=n; i++) {
		p[i].x=lower_bound(dis+1,dis+1+m,p[i].x)-dis;//离散化第一维,用第一维作为线段树插入第三维的位置
	}
	build(1,m,1);
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&p[i].x);
		dis[i]=p[i].x;
	}
	for(int i=1; i<=n; i++) scanf("%d",&p[i].y);
	for(int i=1; i<=n; i++) scanf("%d",&p[i].z);
	discrete();
	sort(p+1,p+1+n,cmp2);//以第二维大->小排序
	int ans=0;
//	for(int i=1;i<=n;i++){
//		printf("x=%d y=%d z=%d\n",p[i].x,p[i].y,p[i].z);
//	}
	int j;
	for(int i=1; i<=n;i=j) {
//		int j;
		for(j=i;j<=n;j++){
			if(p[j].y!=p[i].y) break;
			if(p[j].z<query(p[j].x+1,m,1)) ans++;
		}
		for(int k=i;k<j;k++) update(p[k].x,p[k].z,1);
	}
	printf("%d\n",ans);
}
