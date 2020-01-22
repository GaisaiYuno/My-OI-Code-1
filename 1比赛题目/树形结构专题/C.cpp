#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn],last[maxn];
struct node {
	int l;
	int r;
	int v;
} tree[maxn<<2];
void push_up(int pos) {
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
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
void update(int tpos,int v,int pos) {
	if(tree[pos].l==tree[pos].r) {
		tree[pos].v+=v;
		return;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(tpos<=mid) update(tpos,v,pos<<1);
	else update(tpos,v,pos<<1|1);
	push_up(pos);
}
int query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		return tree[pos].v;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(L,R,pos<<1);
	if(R>mid) ans+=query(L,R,pos<<1|1);
	return ans;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
	build(1,n*2,1);
	for(int i=1;i<=n*2;i++){
//		printf("%d\n",a[i]);
		if(last[a[i]]==0){
			last[a[i]]=i;
			update(i,1,1);
		}else{
			ans+=query(last[a[i]]+1,i,1);
			update(last[a[i]],-1,1);
		}
	}
	printf("%d\n",ans);
	
}

