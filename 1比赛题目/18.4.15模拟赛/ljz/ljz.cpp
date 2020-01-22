#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define size 200005
#define INF 1000000001
using namespace std;
struct node{
	int l;
	int r;
	long long v;
	long long mark;
	int is_mark;
	int len(){
		return r-l+1;
	}
}tree[maxn<<2];
int a[maxn];
void push_up(int pos){
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void push_down(int pos){
	if(tree[pos].is_mark){
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1].is_mark=1;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos<<1|1].is_mark=1;
		tree[pos<<1].v+=tree[pos].mark*tree[pos<<1].len();
		tree[pos<<1|1].v+=tree[pos].mark*tree[pos<<1|1].len();
		tree[pos].mark=0;
		tree[pos].is_mark=0;
	}
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].mark=0;
	tree[pos].is_mark=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}
void update(int L,int R,int v,int l,int r,int pos){
	if(L<=l&&R>=r){
		tree[pos].mark+=v;
		tree[pos].is_mark=1;
		tree[pos].v+=v*tree[pos].len();
		return;
	}
	push_down(pos);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,l,mid,pos<<1);
	if(R>mid) update(L,R,v,mid+1,r,pos<<1|1);
	push_up(pos);
}
long long query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r) return tree[pos].v;
	long long ans=0;
	int mid=(l+r)>>1;
	push_down(pos);
	if(L<=mid) ans=ans+query(L,R,l,mid,pos<<1);
	if(R>mid) ans=ans+query(L,R,mid+1,r,pos<<1|1);
	return ans;
}
int n;
int main(){
//	printf("%.2fMB",(double)(sizeof(a)+sizeof(tree))/1024/1024);
//	freopen("ljz.in","r",stdin);
//	freopen("ljz.out","w",stdout);
    int i,j,z,maxj;
    scanf("%d",&n);
    build(1,size,1);
    maxj=0;
    for(int u=1;u<=n;u++){
    	scanf("%d %d %d",&i,&j,&z);
    	update(i,j,z,1,size,1);
    	maxj=max(j,maxj);
	}
	long long ans=-INF;
	for(int i=1;i<=maxj+1;i++){
		ans=max(ans,query(1,i,1,size,1));
		//printf("%d\n",query(1,i,1,size,1));
	} 
	printf("%lld\n",ans);
}
