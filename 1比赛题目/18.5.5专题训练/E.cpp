#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005
#define maxm 200005
#define maxv 1000005
using namespace std;
int a[maxn];
struct node{
	int l;
	int r;
	long long v;
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos);
}
void update(int tpos,int v,int l,int r,int pos){
	if(l==r){
		tree[pos].v+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(tpos<=mid) update(tpos,v,l,mid,pos<<1);
	else update(tpos,v,mid+1,r,pos<<1|1);
	push_up(pos); 
}
long long query(int L,int R,int l,int r,int pos){
	if(L<=l&&R>=r){
		return tree[pos].v;
	}
	long long ans=0;
	int mid=(l+r)>>1;
	if(L<=mid) ans+=query(L,R,l,mid,pos<<1);
	if(R>mid) ans+=query(L,R,mid+1,r,pos<<1|1);
	return ans;
}
struct que{
	int l;
	int r;
	int id; 
	friend bool operator <(que x,que y){
		if(x.r==y.r) return x.l<y.l;
		else return x.r<y.r;
	}
}q[maxm];
int t,n,m; 
int las[maxv];
long long ans[maxm];
int main(){
	scanf("%d",&t);
	while(t--){
//		memset(a,0,sizeof(a));
//		memset(q,0,sizeof(q));
		memset(las,0,sizeof(las));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d %d",&q[i].l,&q[i].r);
			q[i].id=i;
		}
		sort(q+1,q+1+m);
		build(1,n,1);
		int cnt=1;
		for(int i=1;i<=m;i++){
			while(cnt<=q[i].r){
				if(las[a[cnt]]){
					update(las[a[cnt]],-a[cnt],1,n,1);
				}
				las[a[cnt]]=cnt;
				update(cnt,a[cnt],1,n,1);
				cnt++;
			}
			ans[q[i].id]=query(q[i].l,q[i].r,1,n,1);
		}
		for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
		
	} 
}
