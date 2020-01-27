//http://codeforces.com/problemset/problem/280/D
/*
经典模型，线段树维护最大连续和
考虑取k次
每取一次，和s,最大区间内的数*=-1，
第二次再取最大区间，和x,s+x相当于在上一次的区间里去掉-x,把一个区间断成两个
区间*-1，则最大值等取反，并还要维护最小值 ，交换最大最小值
每次查询完记得取反回去 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define maxk 20
using namespace std;

inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];
struct val{
	int sum;
	
	int lmin;
	int lminp;
	int rmin;
	int rminp;
	int minv;
	int minpl;
	int minpr;
	
	int lmax;
	int lmaxp;
	int rmax;
	int rmaxp;
	int maxv;
	int maxpl;
	int maxpr;

	friend val operator + (val lson,val rson){
		val ans;
		ans.sum=lson.sum+rson.sum;
		
		ans.lmin=lson.lmin;
		ans.lminp=lson.lminp;
		if(lson.sum+rson.lmin<ans.lmin){//不用判断lson.lmin==lson.sum 
			ans.lmin=lson.sum+rson.lmin;
			ans.lminp=rson.lminp;
		}
		
		ans.rmin=rson.rmin;
		ans.rminp=rson.rminp;
		if(rson.sum+lson.rmin<ans.rmin){
			ans.rmin=rson.sum+lson.rmin;
			ans.rminp=lson.rminp;
		}
		
		int minv=min(min(lson.minv,rson.minv),lson.rmin+rson.lmin);
		ans.minv=minv;
		if(lson.minv==minv){
			ans.minpl=lson.minpl;
			ans.minpr=lson.minpr;
		}else if(rson.minv==minv){
			ans.minpl=rson.minpl;
			ans.minpr=rson.minpr;
		}else{
			ans.minpl=lson.rminp;
			ans.minpr=rson.lminp;
		}
		
		
		ans.lmax=lson.lmax;
		ans.lmaxp=lson.lmaxp;
		if(lson.sum+rson.lmax>ans.lmax){
			ans.lmax=lson.sum+rson.lmax;
			ans.lmaxp=rson.lmaxp;
		}
		
		ans.rmax=rson.rmax;
		ans.rmaxp=rson.rmaxp;
		if(rson.sum+lson.rmax>ans.rmax){
			ans.rmax=rson.sum+lson.rmax;
			ans.rmaxp=lson.rmaxp;
		}
		
		int maxv=max(max(lson.maxv,rson.maxv),lson.rmax+rson.lmax);
		ans.maxv=maxv;
		if(lson.maxv==maxv){
			ans.maxpl=lson.maxpl;
			ans.maxpr=lson.maxpr;
		}else if(rson.maxv==maxv){
			ans.maxpl=rson.maxpl;
			ans.maxpr=rson.maxpr;
		}else{
			ans.maxpl=lson.rmaxp;
			ans.maxpr=rson.lmaxp;
		}
		
		return ans;
	}
	
	void reverse(){
		sum=-sum;
		lmin=-lmin;
		lmax=-lmax;
		swap(lmin,lmax);
		swap(lminp,lmaxp);
		rmin=-rmin;
		rmax=-rmax;
		swap(rmin,rmax);
		swap(rminp,rmaxp);
		minv=-minv;
		maxv=-maxv;
		swap(minv,maxv);
		swap(minpl,maxpl);
		swap(minpr,maxpr);
	}
	
	void set(int pos,int val){
		sum=lmin=lmax=rmin=rmax=minv=maxv=val;
		lminp=lmaxp=rminp=rmaxp=minpl=maxpl=minpr=maxpr=pos;
	}
	
	void print(){
		printf("val: maxv=%d lmax=%d rmax=%d\n",maxv,lmax,rmax);
	}
};

struct segment_tree{
	struct node{
		int l;
		int r;
		int sum;
		int mark;//区间-1（翻转max,min） 标记 
		val v;
	}tree[maxn*4+5];
	void push_up(int pos){
//		if(pos==2){
//			pos=2;
//		}
		tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
	} 
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		if(l==r){
			tree[pos].v.set(l,a[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		push_up(pos);
//		printf("[%d,%d]: ",l,r);
//		tree[pos].v.print();
	}
	void push_down(int pos){
		if(tree[pos].mark){
			tree[pos<<1].mark^=1;
			tree[pos<<1].v.reverse();
			tree[pos<<1|1].mark^=1;
			tree[pos<<1|1].v.reverse();
			tree[pos].mark=0;
		}
	}
	void update_segment(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			tree[pos].mark^=1;
			tree[pos].v.reverse();
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(L<=mid) update_segment(L,R,pos<<1);
		if(R>mid) update_segment(L,R,pos<<1|1);
		push_up(pos);
	}
	void update_point(int upos,int val,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v.set(tree[pos].l,val);
			return;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update_point(upos,val,pos<<1);
		else update_point(upos,val,pos<<1|1);
		push_up(pos); 
	}
	val query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r){
			return tree[pos].v;
		}
		push_down(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		val lans,rans;
		lans.set(0,0);
		rans.set(0,0);
		if(L<=mid){
			lans=query(L,R,pos<<1);
		}
		if(R>mid){
			rans=query(L,R,pos<<1|1);
		}
		if(lans.maxpl==0) return rans;
		else if(rans.maxpl==0) return lans;
		else return lans+rans;
	}
}T;


val tmp[maxk+5];
int solve(int l,int r,int k){
	int sz=0;
	int ans=0;
	for(int i=1;i<=k;i++){
		tmp[++sz]=T.query(l,r,1);
		if(tmp[sz].maxv<0){
			sz--;
			break;
		}
		ans+=tmp[sz].maxv;
		T.update_segment(tmp[sz].maxpl,tmp[sz].maxpr,1);
	}
	for(int i=sz;i>=1;i--){
		T.update_segment(tmp[i].maxpl,tmp[i].maxpr,1);
	}
	return ans;
}

int main(){
//#ifndef LOCAL
//	freopen("easy.in","r",stdin);
//	freopen("easy.out","w",stdout);
//#endif
	int op,x,val,l,r,k;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	T.build(1,n,1);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(op);
		if(op==0){
			qread(x);
			qread(val);
			T.update_point(x,val,1);
		}else{
			qread(l);
			qread(r);
			qread(k);
			qprint(solve(l,r,k));
			putchar('\n');
		} 
	}
}
/*
3
8 0 9 
2
1 2 2 1
1 1 3 3

*/ 
