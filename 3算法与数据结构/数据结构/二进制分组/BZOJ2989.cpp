/*
二进制分组的基本思想是把修改操作按二进制分组，遇到修改就在尾部加一个，并与之前的合并，
比如之前有23（16+4+2+1）个，加了一个后就变成16+4+2+1+1,把1和1合并，变成 
遇到查询就在每个组内查询，再加起来就好了。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility> 
#include<vector> 
#define maxn 100000
#define maxlogn 32
#define INF 0x3f3f3f3f
using namespace std;
int n,q;
int a[maxn+5];
struct mem_pool{//手写内存池，回收删除的点防止MLE 
	 int top=0;
	 int stk[maxn*2*maxlogn+5];
	 inline void ini(int n){
	 	for(int i=n;i>=1;i--) stk[++top]=i;
	 } 
	 inline int New(){
	 	return stk[top--];
	 }
	 inline void del(int x){
	 	stk[++top]=x;
	 }
}pool;

//把x坐标离散化，以x坐标为下标建n棵可持久化线段树维护前缀和，y坐标为线段树下标
//在第x-k(离散化后)到第x+k棵线段树上查区间[y-k,y+k]就可以得到二维前缀和 
int root[maxlogn+5][maxn*2+5];//root[i][j],第i个分组区间里面第j小的x坐标对于的线段树 
struct persist_segment_tree{
	#define lson(x) tree[x].ls
	#define rson(x) tree[x].rs
	struct node{
		int ls;
		int rs;
		int val;
	}tree[maxn*2*maxlogn+5];
	bool is_del[maxn*2*maxlogn+5];
	//因为一个点不能被删除两次(主席树上的一个点可能被多个节点指向)，打标记
	int New(){
		int x=pool.New();
		is_del[x]=0;
		return x;
	}
	void push_up(int x){
		tree[x].val=tree[lson(x)].val+tree[rson(x)].val;
	}
	void update(int &x,int last,int upos,int l,int r){
		x=New();
		tree[x]=tree[last];
		if(l==r){
			tree[x].val++;
			return;
		}
		int mid=(l+r)>>1;
		if(upos<=mid) update(tree[x].ls,tree[last].ls,upos,l,mid);
		else update(tree[x].rs,tree[last].rs,upos,mid+1,r);
		push_up(x);
	} 
	int query(int xl,int xr,int ql,int qr,int l,int r){
		if(ql<=l&&qr>=r){
			return tree[xr].val-tree[xl].val;
		}
		int mid=(l+r)>>1;
		int ans=0;
		if(ql<=mid) ans+=query(tree[xl].ls,tree[xr].ls,ql,qr,l,mid);
		if(qr>mid) ans+=query(tree[xl].rs,tree[xr].rs,ql,qr,mid+1,r);
		return ans; 
	}
	void del(int x){
		if(is_del[x]) return;
		is_del[x]=1;
		pool.del(x);
		if(tree[x].ls) del(tree[x].ls);
		if(tree[x].rs) del(tree[x].rs);
		tree[x].val=tree[x].ls=tree[x].rs=0; 
	}
}T;

int top=0;
vector< pair<int,int> >v[maxlogn+5];//存储每个组里的修改操作 
int sz[maxlogn+5]; 
void rebuild(int id){//重构某个组 
	for(int i=1;i<=sz[id];i++){
		//把第i个y坐标更新 
		T.update(root[id][i],root[id][i-1],v[id][i-1].second,1,maxn*2);
	} 
} 
void insert(pair<int,int> p){
	sz[++top]=1;
	v[top].push_back(p);
	rebuild(top);
	while(top>1&&sz[top-1]==sz[top]){//类似二进制加法进位，去合并 
		for(int i=0;i<sz[top];i++) v[top-1].push_back(v[top][i]);
		sort(v[top-1].begin(),v[top-1].end());//排序，相当于离散化
		v[top].clear();
		for(int i=1;i<=sz[top];i++){
			if(root[top-1][i]) T.del(root[top-1][i]);//先删除，等下再暴力重构
			if(root[top][i]) T.del(root[top][i]); 
		}
		sz[top-1]+=sz[top];
		rebuild(top-1);
		top--;
	}
} 
int query(pair<int,int>p,int k){
	int x=p.first,y=p.second,l,r;
	int ans=0;
	for(int i=1;i<=top;i++){
		l=upper_bound(v[i].begin(),v[i].end(),make_pair(x-k,0))-v[i].begin();
		//本来是找<=再+1(root下标从1开始)，直接upper_bound也可以 
		r=upper_bound(v[i].begin(),v[i].end(),make_pair(x+k,INF))-v[i].begin();
		if(l<=r) ans+=T.query(root[i][l],root[i][r],max(y-k,0),min(y+k,maxn*2),1,maxn*2);
	}
	return ans;
}

char s[10];
int main(){
	int x,k;
	scanf("%d %d",&n,&q);
	pool.ini(maxn*2*maxlogn);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(make_pair(a[i]+i,a[i]-i+maxn));//为了防止负数，要+maxn，注意数组要开两倍 
	}
	for(int i=1;i<=q;i++){
		scanf("%s",s);
		if(s[0]=='M'){
			scanf("%d %d",&x,&k);
			a[x]=k;
			insert(make_pair(a[x]+x,a[x]-x+maxn));
		}else{
			scanf("%d %d",&x,&k);
			printf("%d\n",query(make_pair(a[x]+x,a[x]-x+maxn),k));
		}
	}
}

