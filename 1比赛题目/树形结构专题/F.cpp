#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
long long sum[maxn];
struct node{
	int l;
	int r;
	long long mark;
	long long v;
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
		tree[pos].v=sum[l];
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
void update(int L,int R,long long v,int pos){
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
long long query(int L,int R,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		return tree[pos].v;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	long long ans=0;
	if(L<=mid) ans+=query(L,R,pos<<1);
	if(R>mid) ans+=query(L,R,pos<<1|1);
	return ans;
}
char cmd[10];
int main(){
	int u,x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='M'){
			scanf("%d %d",&u,&x);
			update(u,n,(long long)x-a[u],1);
			a[u]=x;
		}else{
			scanf("%d",&u);
			printf("%lld\n",query(1,u,1));
		}
	}
}

