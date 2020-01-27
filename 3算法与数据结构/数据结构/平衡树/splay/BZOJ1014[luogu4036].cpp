#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
#define INF 0x3f3f3f3f
using namespace std;
typedef unsigned long long ll;
int n,m;
char s[maxn];
int a[maxn];
const ll seed=27;
ll pows[maxn];
struct Splay{
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node{
		int fa;
		int ch[2];
		int val;
		ll hash_val;
		int cnt;
		int sz; 
	}tree[maxn];
	int root;
	int ptr;
	int New(int val){
		ptr++;
		tree[ptr].val=val;
		tree[ptr].hash_val=val;
		tree[ptr].cnt=tree[ptr].sz=1;
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[x].cnt+tree[lson(x)].sz+tree[rson(x)].sz;
		tree[x].hash_val=tree[lson(x)].hash_val*pows[tree[rson(x)].sz+1]+tree[x].val*pows[tree[rson(x)].sz]+tree[rson(x)].hash_val;
	} 
	int chk(int x){
		return tree[tree[x].fa].ch[1]==x;
	}
	void rotate(int x){
		int y=tree[x].fa,z=tree[y].fa,k=chk(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		tree[z].ch[chk(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	int find_kth(int k){
		int cur=root;
		while(1){
			if(k<=tree[lson(cur)].sz) cur=lson(cur);
			else if(k<=tree[lson(cur)].sz+tree[cur].cnt) return cur; 
			else{
				k-=tree[lson(cur)].sz+tree[cur].cnt;
				cur=rson(cur);
			} 
		}
		return 0;
	} 
	void splay(int x,int goal=0){
		while(tree[x].fa!=goal){
			int y=tree[x].fa;
			int z=tree[y].fa;
			if(z!=goal){
				if(chk(x)==chk(y)) rotate(y);
				else rotate(x);
			}
			rotate(x); 
		}
		if(goal==0) root=x;
	}
	int split(int l,int r){
		int lx,rx;
		lx=find_kth(l-1);
		rx=find_kth(r+1);
		splay(rx);
		splay(lx,rx); 
		return rson(lson(root));
	}
	bool check(int l,int r,int mid){
		l=split(l+1,l+mid);
		int h1=tree[l].hash_val;//必须在第二次split之前保存h1,否则旋转后结构会变 
		r=split(r+1,r+mid);
		int h2=tree[r].hash_val;
		return h1==h2;
	}
	void update(int x,int d){
		int u=split(x+1,x+2); 
		tree[u].val=x;
		tree[u].hash_val=x;
		push_up(tree[u].fa);
		push_up(root);
	}
	void insert(int x,int d){
		int l=find_kth(x);
		int r=find_kth(x+1);
		splay(r);
		splay(l,r);
		int xx=l;
		int yy=New(d);
		tree[yy].fa=xx;
		tree[xx].ch[1]=yy;
		push_up(xx);
		push_up(root); 
	}
	void build(int l,int r,int f){
		int mid=(l+r)>>1;
		tree[mid].val=a[mid];
		tree[mid].hash_val=a[mid];
		tree[mid].cnt=tree[mid].sz=1;
		tree[mid].fa=f;
		tree[f].ch[mid>f]=mid;
		if(l==r) return;
		if(l<=mid-1) build(l,mid-1,mid);
		if(mid+1<=r) build(mid+1,r,mid);
		push_up(mid); 
	}
}T; 
char cmd[2],d[2];
int bin_search(int x,int y){
//	printf("work %d %d: ",x,y);
//	T.check(x,y,5); 
	int l=1,r=min(T.ptr-x-1,T.ptr-y-1),mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
//		printf("%d ",mid);
		if(T.check(x,y,mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
//	printf("\n");
	return ans;
}
int main(){
	int x,y; 
	scanf("%s",s+1);
	n=strlen(s+1);
	pows[0]=1;
	for(int i=1;i<=n+2;i++) pows[i]=pows[i-1]*seed;
	for(int i=1;i<=n;i++) a[i+1]=s[i]-'a'+1;
	a[1]=0;
	a[n+2]=0;
	T.build(1,n+2,0);
	T.root=(n+3)>>1;
	T.ptr=n+2;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d %d",&x,&y);
			printf("%d\n",bin_search(x,y));
		}else if(cmd[0]=='R'){
			scanf("%d",&x);
			scanf("%s",d); 
			T.update(x,d[0]-'a'+1);
		}else{
			scanf("%d",&x);
			scanf("%s",d); 
			T.insert(x,d[0]-'a'+1);
		}
	}
}
/*
aa
2
I 1 a
Q 1 2
*/
