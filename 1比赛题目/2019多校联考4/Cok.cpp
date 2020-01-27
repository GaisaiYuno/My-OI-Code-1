
//最小值肯定是某个点->某个点的颜色上一个出现的位置
//离散化，然后预处理last[i]表示a[i]上一次出现的位置
//然后离线询问，按r排序
//从小到大枚举右端点i,然后将i到last[i]的距离加入线段树(位置为last[i])
//直接查询[l,r]最小值
#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector> 
#define maxn 200000 
#define INF 0x3f3f3f3f
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
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	} 
}
struct segment_tree{
	struct node{
		int l;
		int r;
		int v; 
	}tree[maxn*4+5];
	void push_up(int pos){
		tree[pos].v=min(tree[pos<<1].v,tree[pos<<1|1].v);
	}
	void build(int l,int r,int pos){
		tree[pos].l=l;
		tree[pos].r=r;
		tree[pos].v=INF;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
	} 
	void update(int upos,int uval,int pos){
		if(tree[pos].l==tree[pos].r){
			tree[pos].v=uval;
			return;
		}
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if(upos<=mid) update(upos,uval,pos<<1);
		else update(upos,uval,pos<<1|1);
		push_up(pos);
	}
	int query(int L,int R,int pos){
		if(L<=tree[pos].l&&R>=tree[pos].r) return tree[pos].v;
		int mid=(tree[pos].l+tree[pos].r)>>1;
		int ans=INF;
		if(L<=mid) ans=min(ans,query(L,R,pos<<1));
		if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
		return ans; 
	} 
}T;

struct que{
	int l;
	int r;
	int id;
	friend bool operator < (que p,que q){
		return p.r<q.r;
	}
}q[maxn+5];

int n,m,mv;
int a[maxn+5];
int tmp[maxn+5];
void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	mv=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+mv,a[i])-tmp;
} 

int pos[maxn+5];
int last[maxn+5];
int ans[maxn+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	discrete();
	for(int i=1;i<=n;i++){
		last[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	T.build(1,n,1);
	int pos=1;
	for(int i=1;i<=n;i++){
		if(last[i]) T.update(last[i],i-last[i],1);
		while(pos<=m&&q[pos].r==i){
			ans[q[pos].id]=T.query(q[pos].l,q[pos].r,1);
			pos++;
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]==INF) ans[i]=-1;
		qprint(ans[i]);
		putchar('\n');
	}
}

