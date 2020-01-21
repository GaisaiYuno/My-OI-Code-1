#include<iostream>
#include<cstdio>
#include<cstdlib>
#define maxn 100005 
#define maxv 1000000000
#define maxlogn 20
using namespace std;
inline void qread(int& x) {
    x=0;
    char c=getchar();
    int sign=1;
    while(c<'0'||c>'9') {
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    x*=sign;
}
inline void qprint(int x) {
    if(x<0) {
        putchar('-');
        qprint(-x);
    } else if(x==0) {
        putchar('0');
        return;
    } else {
        if(x/10>0) qprint(x/10);
        putchar('0'+x%10);
    }
}

int n,m;
int a[maxn];
struct treap{
	struct node{
		int ls;
		int rs;
		int cnt;
		int sz;
		int val;
		int dat; 
	}tree[maxn*maxlogn];
	int ptr;
	int New(int val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].cnt=tree[ptr].sz=1;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
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
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[x].rs==0||tree[tree[x].ls].dat>tree[tree[x].rs].dat){
						rturn(x);
						del(tree[x].rs,val);
					}else{
						lturn(x);
						del(tree[x].ls,val);
					}
					push_up(x); 
				}
				else x=0;
			}
			return;
		}
		if(val<tree[x].val){
			del(tree[x].ls,val);
		}else{
			del(tree[x].rs,val);
		}
		push_up(x);
	}
	int get_rank(int x,int val){
		if(x==0) return 0;
		if(val<tree[x].val) return get_rank(tree[x].ls,val);
		else if(val==tree[x].val){
			return tree[tree[x].ls].sz;
		}else{
			return tree[tree[x].ls].sz+tree[x].cnt+get_rank(tree[x].rs,val); 
		}
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
		for(int i=l;i<=r;i++) T1.insert(tree[pos].root,a[i]);
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	}
	void update(int qpos,int v,int pos){
		T1.del(tree[pos].root,a[qpos]);
		T1.insert(tree[pos].root,v);
		if(tree[pos].l==tree[pos].r) return;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(qpos<=mid) update(qpos,v,pos<<1);
		else update(qpos,v,pos<<1|1);
	}	
	int query_rank(int L,int R,int v,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return T1.get_rank(tree[pos].root,v);
		}	
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=0;
		if(L<=mid) ans+=query_rank(L,R,v,pos<<1);
		if(R>mid) ans+=query_rank(L,R,v,pos<<1|1);
		return ans; 
	}
	int query_val(int L,int R,int k,int pos){
		int l=0,r=maxv,mid,tmp,ans;
		while(l<=r){
			mid=(l+r)>>1;
			tmp=query_rank(L,R,mid,1);
			if(tmp+1<=k){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
		return ans;
	}
}T2;
int main(){
	int l,r,v,t;
	char cmd[2];
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	T2.build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			qread(l);
			qread(r);
			qread(v);
			qprint(T2.query_val(l,r,v,1));
			putchar('\n');
		}else{
			qread(t);
			qread(v);
			T2.update(t,v,1); 
			a[t]=v;
		} 
	}
}

