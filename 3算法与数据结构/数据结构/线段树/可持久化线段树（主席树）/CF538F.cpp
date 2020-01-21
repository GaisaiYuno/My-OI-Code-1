//意到一个完全k叉树下v节点的儿子的公式是：k*(v-1)+2...kv+1,相应的父节点的公式是 (v+k-2)/k。儿子的编号是连续的
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxlogn 20
using namespace std;
struct node{
#ifdef DEBUG
	int l;
	int r;
#endif
	int ls;
	int rs;
	int cnt; 
}tree[maxn*maxlogn];
int ptr;
inline void push_up(int x){
	tree[x].cnt=tree[tree[x].ls].cnt+tree[tree[x].rs].cnt;
}
void update(int &x,int last,int upos,int l,int r){
	x=++ptr;
	tree[x]=tree[last];
#ifdef DEBUG
	tree[x].l=l;
	tree[x].r=r;
#endif
	if(l==r){
		tree[x].cnt++;
		return;
	}
	int mid=(l+r)>>1;
	if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
	else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
	push_up(x);
}
int get_sum(int L,int R,int l,int r,int x){
	if(L<=l&&R>=r){
		return tree[x].cnt;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans+=get_sum(L,R,l,mid,tree[x].ls);
	if(R>mid) ans+=get_sum(L,R,mid+1,r,tree[x].rs);
	return ans;
}

int n;
int root[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	int m=n;
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	}
	for(int i=1;i<=n;i++){
		update(root[i],root[i-1],a[i],1,m);
	}
	
	for(int k=1;k<=n-1;k++){
		int lim=(n+k-2)/k;
		for(int i=1;i<=lim;i++){
			int l=k*(i-1)+2;
			int r=min(k*i+1,n);
			int cnt=0;
			if(a[i]-1<1) cnt=0; 
			else cnt=get_sum(1,a[i]-1,1,m,root[r])-get_sum(1,a[i]-1,1,m,root[l-1]);
			ans[k]+=cnt;
		}
	}
	for(int i=1;i<=n-1;i++){
		printf("%d ",ans[i]);
	}
}

