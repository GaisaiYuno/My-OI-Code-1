#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define maxn 100005
#define maxlogn 17
using namespace std;
int n,m;
struct treap{
	struct node{
		int ls;
		int rs;
		int val;
		int cnt;
		int sz;
		int dat;
	}tree[maxn*maxlogn];
	int ptr;
	void push_up(int x){
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
	}
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		tree[ptr].sz=tree[ptr].cnt=1;
		return ptr;
	}
	void rturn(int &x){
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(x);
	}
	void lturn(int &x){
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(x); 
	} 
	void insert(int &x,int val){
		if(x==0){
			x=New(val);
			return;
		}
		if(tree[x].val==val){
			tree[x].cnt++;
			push_up(x);
			return;
		}
		if(val<tree[x].val){
			insert(tree[x].ls,val);
			if(tree[tree[x].ls].dat>tree[x].dat) rturn(x); 
		}else{
			insert(tree[x].rs,val);
			if(tree[tree[x].rs].dat>tree[x].dat) lturn(x);
		} 
		push_up(x);
	} 
	void del(int &x,int val){
		if(x==0) return;
		if(tree[x].val==val){
			if(tree[x].cnt>1){
				tree[x].cnt--;
				push_up(x);
				return;
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[x].rs==0||tree[tree[x].ls].dat>tree[tree[x].rs].dat){
						rturn(x);
						del(tree[x].rs,val);
					}else{
						lturn(x);
						del(tree[x].ls,val);
					}
				}else x=0;
				return;
			}
		}
		if(val<tree[x].val){
			del(tree[x].ls,val);
		}else{
			del(tree[x].rs,val);
		}
		push_up(x);
	} 
	int lower_bound(int x,int val){
		if(x==0) return 0;
		if(val<tree[x].val) return lower_bound(tree[x].ls,val);
		else if(val==tree[x].val) return lower_bound(tree[x].ls,val)+tree[x].cnt;
		else return tree[tree[x].ls].sz+tree[x].cnt+lower_bound(tree[x].rs,val);
	}
	void print(int x){
		if(x==0) return;
		print(tree[x].ls);
		for(int i=1;i<=tree[x].cnt;i++) printf("%d ",tree[x].val);
		print(tree[x].rs);
	}
}T1;
struct segment_tree{
	struct node{
		int l;
		int r;
		int root;
	}tree[maxn<<2];
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void insert(int tpos,int tval,int pos){
		T1.insert(tree[pos].root,tval);
		if(tree[pos].l==tree[pos].r) return;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) insert(tpos,tval,pos<<1);
		else insert(tpos,tval,pos<<1|1);
	}
	void del(int tpos,int tval,int pos){
		T1.del(tree[pos].root,tval);
		if(tree[pos].l==tree[pos].r) return;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(tpos<=mid) del(tpos,tval,pos<<1);
		else del(tpos,tval,pos<<1|1);
	}
	int query(int p,int q,int qk,int pos){
		if(tree[pos].l==tree[pos].r) return tree[pos].l;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int lcnt=T1.lower_bound(tree[pos<<1].root,p)-T1.lower_bound(tree[pos<<1].root,q-1);
		if(qk<=lcnt) return query(p,q,qk,pos<<1);
		else return query(p,q,qk-lcnt,pos<<1|1);
	}
	void debug(int pos){
		printf("[%d,%d]: " ,tree[pos].l,tree[pos].r); 
		T1.print(tree[pos].root);
		printf("\n");
		if(tree[pos].l==tree[pos].r) return;
		debug(pos<<1);
		debug(pos<<1|1);
	}
}T2;

struct oper{
	int type;
	int l,r,k;
	int pos,val;
	int dval;
}q[maxn];
int a[maxn];
int sz;
int b[maxn]; 
int main(){
	char cmd[2];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[++sz]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			q[i].type=0;
			scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].k);
		}else{
			q[i].type=1;
			scanf("%d %d",&q[i].pos,&q[i].val);
			b[++sz]=q[i].val;
		} 
	}
	sort(b+1,b+1+sz);
	sz=unique(b+1,b+1+sz)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;
	for(int i=1;i<=m;i++){
		if(q[i].type==1){
			q[i].dval=lower_bound(b+1,b+1+sz,q[i].val)-b;
		}
	}
	T2.build(1,sz,1);
	T2.debug(1);
	for(int i=1;i<=n;i++){
		T2.insert(a[i],i,1);
	} 
	T2.debug(1);
	for(int i=1;i<=m;i++){
		if(q[i].type==0){
			printf("%d\n",b[T2.query(q[i].r,q[i].l,q[i].k,1)]); 
		}else{
			T2.del(a[q[i].pos],q[i].pos,1);
			T2.insert(q[i].dval,q[i].pos,1);
			a[q[i].pos]=q[i].dval;
		}
	}
}

