//把每个套娃看成点(x,y)
//那么一组套娃就相当于一个下降的折线
//显然不相交下降折线数量=最长上升子序列长度
//由于有询问(A,B)，把询问离线，按x从大到小排序，扫描线，做到某个有询问的地方就更新答案
//把y离散化之后dp,dp[i]=max(dp[j]+1), j<=i 用线段树维护
//查询B，就是查询[1,B]中dp最大值 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300000
#define maxq 300000
using namespace std;
struct segment_tree{
	struct node{
		int l;
		int r;
		int v;
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=max(tree[pos<<1].v,tree[pos<<1|1].v);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int upos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=val;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,val,pos<<1);
		else update(upos,val,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=0;
		if(L<=mid) ans=max(ans,query(L,R,pos<<1));
		if(R>mid) ans=max(ans,query(L,R,pos<<1|1));
		return ans;
	}
}T;

int n,q;
struct node{
	int x;
	int y;
	int dy; //y轴离散化。方便dp 
	int type;//询问和点放在一起， 用type区分，方便排序 
	friend bool operator < (node p,node q){
		if(p.x==q.x){
			if(p.y==q.y) return p.type<q.type;
			else return p.y<q.y; 
		}
		else return p.x>q.x;
	} 
}a[maxn+maxq+5];
int b[maxn+5];
int ans[maxn+5];
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].type=0;
		b[i]=a[i].y;
	}
	for(int i=n+1;i<=n+q;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].type=i-n;
	}
	sort(b+1,b+1+n);
	int sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n+q;i++){
		a[i].dy=upper_bound(b+1,b+1+sz,a[i].y)-b-1;
		//为了处理询问的边界情况，若a[i]<B<a[i+1],应该取i而不是i+1,所以不能lower_bound 
//		printf("db:%d %d\n",a[i].dy,lower_bound(b+1,b+1+sz,a[i].y)-b);
	}
	sort(a+1,a+1+n+q);
	T.build(1,sz,1);
	for(int i=1;i<=n+q;i++){
		if(a[i].type==0){
			T.update(a[i].dy,T.query(1,a[i].dy,1)+1,1);
		}else{
			ans[a[i].type]=T.query(1,a[i].dy,1);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d ",ans[i]);
	}
}
/*
7 3
9 5
3 7
10 6
5 10
2 6
10 10
4 1
10 5
3 5
3 9
*/ 
