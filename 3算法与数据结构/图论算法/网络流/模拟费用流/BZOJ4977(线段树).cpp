#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define maxn 200000
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int a[maxn+5],b[maxn+5],c[maxn+5];
struct item{
	int val;
	int type;
	int id;
	item(){
		
	}
	item(int _val,int _type,int _id){
		val=_val;
		type=_type;
		id=_id;
	}
	friend bool operator < (item p,item q){
		//按a和b从小到大排序，对于相同的情况，将玩家优先放在前面 
		if(p.val==q.val) return p.type<q.type;
		return p.val<q.val;
	}
}all[maxn+5];
//set<item>house; 
item house[maxn+5];

struct segment_tree{
	struct node{
		int l;
		int r;
		int val;
		int mark;
		int len(){
			return r-l+1;
		}
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
	}
	void add_mark(int pos,int mark){
		tree[pos].val+=mark;
		tree[pos].mark+=mark;
	}
	void push_down(int pos){
		if(tree[pos].mark){
			add_mark(pos<<1,tree[pos].mark);
			add_mark(pos<<1|1,tree[pos].mark);
			tree[pos].mark=0;
		}
	}
	void update(int L,int R,int val,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			add_mark(pos,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update(L,R,val,pos<<1);
		if(R>mid) update(L,R,val,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].val;
		}
		push_down(pos);
		int ans=INF;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) ans=min(ans,query(L,R,pos<<1));
		if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
		return ans;
	}
}T;

int sz=0;
int pos[3][maxn+5];//排序后a[i],b[i]在all数组里的位置 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) all[++sz]=item(a[i],1,i);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&b[i],&c[i]);
		all[++sz]=item(b[i],2,i);
		house[i]=item(c[i]-b[i],2,i); 
	}
	sort(all+1,all+1+sz);
	sort(house+1,house+1+m);
	for(int i=1;i<=sz;i++){
		pos[all[i].type][all[i].id]=i;
	}
	T.build(1,sz,1);
	int ptr=m;
	long long ans=0;
	for(int i=n;i>=1;i--){//a已经排过序，从大到小处理a[i] 
		T.update(pos[1][i],sz,-1,1);
		while(ptr>0){
			int id=house[ptr].id;
			if(T.query(pos[2][id],sz,1)>=-1&&T.query(1,pos[2][id]-1,1)>=0&&a[i]+house[ptr].val>0){
				ans+=a[i]+house[ptr].val;
				T.update(pos[2][id],sz,1,1);
				ptr--;
				break; 
			}
			ptr--;
		}
		if(ptr==0) break; 
	}
	printf("%lld\n",ans);
}
