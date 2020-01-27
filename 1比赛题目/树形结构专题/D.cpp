#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 50005
#define maxm 200005
using namespace std;
int n,m;
struct node{
	int l;
	int r;
	int mark;
	int v;
	int len(){
		return r-l+1;
	}
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=0;
	tree[pos].v=0;
	if(l==r){
		tree[pos].v=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void push_down(int pos){
	if(tree[pos].mark){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
		tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
		tree[pos].mark=0;
	}
}
void update(int L,int R,int v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].v+=v*tree[pos].len();
		tree[pos].mark+=v;
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(L,R,pos<<1);
	if(R>mid) ans+=query(L,R,pos<<1|1);
	return ans;
}
int bin_search(int l,int r,int x,int *a){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]>x) r=mid-1;
		else l=mid+1;	
	}
	return -1;
}
int a[maxn],b[maxn];
int last[maxn];
struct ask{
	int l;
	int r;
	int i;
}q[maxm];
int ans[maxm];
int cmp(ask x,ask y){
	return x.r==y.r?x.l<y.l:x.r<y.r;
}
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int n2=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=bin_search(1,n2,a[i],b);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].i=i;	
	}
	sort(q+1,q+1+m,cmp);
	int cnt=1;
	build(1,n,1);
	for(int i=1;i<=n;i++){
		update(last[a[i]]+1,i,1,1);
		last[a[i]]=i;
		while(q[cnt].r==i){
			ans[q[cnt].i]=query(q[cnt].l,q[cnt].l,1);
			cnt++;
		}
		if(cnt>m) break;
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",query(i,i,1));
//	}
//	printf("\n");
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
}

