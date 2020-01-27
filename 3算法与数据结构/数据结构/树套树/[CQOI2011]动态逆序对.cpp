#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define maxm 100000
#define maxnlogn 50000000
#define maxlogn 20 
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(long long x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
struct segment_tree_val{
#define lson(x) (tree[x].ls)
#define rson(x) (tree[x].rs)
	struct node{
		int ls;
		int rs;
		int v;
	}tree[maxnlogn+5];
	int ptr;
	void push_up(int x){
		tree[x].v=tree[lson(x)].v+tree[rson(x)].v;
	}
	void update(int &x,int upos,int uval,int l,int r){
		if(!x) x=++ptr;
		if(l==r){
			tree[x].v+=uval;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,upos,uval,l,mid);
		else update(tree[x].rs,upos,uval,mid+1,r);
		push_up(x);
	}
	int totx,toty;
	int x[maxn+5],y[maxn+5];
	int query_less(int k,int l,int r){//查询<k的数的个数 
		int cnt=0;
		while(l!=r){
			int mid=(l+r)>>1;
			if(k<=mid){
				for(int i=1;i<=totx;i++) x[i]=lson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=lson(y[i]);
				r=mid;
			}else{
				for(int i=1;i<=totx;i++) cnt-=tree[lson(x[i])].v;
				for(int i=1;i<=toty;i++) cnt+=tree[lson(y[i])].v;
				for(int i=1;i<=totx;i++) x[i]=rson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=rson(y[i]);
				l=mid+1;
			}
		}
		return cnt;
	}
	int query_more(int k,int l,int r){//查询>k的数的个数 
		int cnt=0;
		while(l!=r){
			int mid=(l+r)>>1;
			if(k<=mid){
				for(int i=1;i<=totx;i++) cnt-=tree[rson(x[i])].v;
				for(int i=1;i<=toty;i++) cnt+=tree[rson(y[i])].v;
				for(int i=1;i<=totx;i++) x[i]=lson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=lson(y[i]);
				r=mid;
			}else{
				for(int i=1;i<=totx;i++) x[i]=rson(x[i]);
				for(int i=1;i<=toty;i++) y[i]=rson(y[i]);
				l=mid+1;
			}
		}
		return cnt;
	}
}T1;

struct fenwick_tree{
	inline int lowbit(int x){
		return x&(-x);
	} 
	int root[maxn+5];
	void update(int t2pos,int t1pos,int val){
		for(int i=t2pos;i<=n;i+=lowbit(i)){
			T1.update(root[i],t1pos,val,1,n);
		}
	}
	int query_less(int lpos,int rpos,int val){
		T1.totx=T1.toty=0;
		for(int i=lpos-1;i;i-=lowbit(i)) T1.x[++T1.totx]=root[i];
		for(int i=rpos;i;i-=lowbit(i)) T1.y[++T1.toty]=root[i]; 
		return T1.query_less(val,1,n);
	}
	int query_more(int lpos,int rpos,int val){
		T1.totx=T1.toty=0;
		for(int i=lpos-1;i;i-=lowbit(i)) T1.x[++T1.totx]=root[i];
		for(int i=rpos;i;i-=lowbit(i)) T1.y[++T1.toty]=root[i]; 
		return T1.query_more(val,1,n);
	}
}T2;

int pos[maxn+5];
long long ans=0;
int main(){
//	freopen("4.in","r",stdin);
//	freopen("4.out","w",stdout); 
//	freopen("1.txt","r",stdin);
	int x;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		pos[a[i]]=i;
		ans+=T2.query_more(1,i-1,a[i]);
		T2.update(i,a[i],1); 
	}
	qprint(ans);
	putchar('\n');
	for(int i=1;i<m;i++){
		qread(x);
		ans-=T2.query_more(1,pos[x]-1,x);
		ans-=T2.query_less(pos[x]+1,n,x);
		qprint(ans);
		putchar('\n');
		T2.update(pos[x],x,-1); 
	}
}
/*
5 4
1 5 3 4 2
5 
1
4
2

*/ 

