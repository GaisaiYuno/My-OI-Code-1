//https://www.luogu.org/problemnew/show/P3567
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500005
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
int root[maxn];
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
int query(int ql,int qr,int qk,int l,int r){
	if(l==r){
		if((tree[qr].cnt-tree[ql].cnt)*2>qk) return l;
		else return 0;
	}
	int mid=(l+r)>>1;
	int lcnt=tree[tree[qr].ls].cnt-tree[tree[ql].ls].cnt;
	if(qk<lcnt*2) return query(tree[ql].ls,tree[qr].ls,qk,l,mid);
	else return query(tree[ql].rs,tree[qr].rs,qk,mid+1,r);
}

int n,m,sz;
int a[maxn];
int b[maxn];
int main(){
	int l,r;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
	} 
	for(int i=1;i<=n;i++){
		update(root[i],root[i-1],a[i],1,sz);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l,&r);
		int ans=query(root[l-1],root[r],r-l+1,1,sz);
		if(ans==0) printf("0\n");
		else printf("%d\n",b[ans]);
	}
}

