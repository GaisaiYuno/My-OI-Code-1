#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int a[maxn];
//struct box{
//	int w;
//	int h;
//}b[maxn];
struct node{
	int l;
	int r;
	long long v;
	long long mark;
	int len(){
		return r-l+1;
	}
}tree[maxn*4]; 
void push_up(int pos){
	tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
} 
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].mark=-1;
	if(l==r){
		tree[pos].v=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1); 
	push_up(pos); 
}
void push_down(int pos){
	if(tree[pos].mark!=-1){
		tree[pos<<1].mark=tree[pos].mark;
		tree[pos<<1|1].mark=tree[pos].mark;
		tree[pos<<1].v=tree[pos].mark;
		tree[pos<<1|1].v=tree[pos].mark;
		tree[pos].mark=-1;
	}
}
void update(int L,int R,long long v,int l,int r,int pos){
	if(L<=l&&R>=r){
		tree[pos].mark=v;
		tree[pos].v=v;
		return;
	}
	push_down(pos); 
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,l,mid,pos<<1);
	if(R>mid) update(L,R,v,mid+1,r,pos<<1|1);
	push_up(pos);
}
long long query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	long long ans=0;
	if(L<=mid) ans=max(ans,query(L,R,l,mid,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,mid+1,r,pos<<1|1));
	return ans;
}
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	scanf("%d",&m);
	long long w,h,ans;
	while(m--){
		scanf("%I64d %I64d",&w,&h);
		ans=query(1,w,1,n,1);
		printf("%I64d\n",ans);
		update(1,w,ans+h,1,n,1);
	
	} 

}
